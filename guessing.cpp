#include <iostream>
#include <string>

using namespace std;

#define MAX_N 100000

// stack implementation
class myStack
{
private:
  long int _stack[MAX_N];
  long int _top;
  
public:
  myStack() { _top = -1; }
  void clear() { _top = -1; }
  
  bool push(long int val) 
  { 
    if(_top+1 == MAX_N)
      return false;
    else
    {
      _stack[++_top] = val; 
      return true;
    }
  } 
  
  long int pop() 
  { 
    if(_top == -1) return -1;
    return _stack[_top--]; 
  }
  
  void print() 
  { 
    cout << "stack (bottom-to-top): ";
    int i = -1;
    while(i < _top) cout << _stack[++i] << " ";
    cout << endl;
  }
};

// queue implementation
class myQueue
{
private:
  long int _circularQ[MAX_N];
  long int head;
  long int tail;
  long int size;
  
public:
  myQueue() { head = tail = -1; size = 0; }
  void clear() { head = tail = -1; size = 0; }
  
  bool enqueue(long int val) 
  { 
    if(size == 0)
    {
      head = tail = 0;
      _circularQ[0] = val;
    }
    else
    {
      if(size == MAX_N) return false;
      tail = (tail + 1) % MAX_N;
      _circularQ[tail] = val;
    }
    ++size;
    return true;
  }
  
  long int dequeue() 
  { 
    if(size == 0) return -1;
    long int retVal = _circularQ[head];
    head = (head + 1) % MAX_N;
    --size;
    return retVal;
  }
  
  void print() 
  { 
    cout << "queue (front-to-back): ";
    for(int i=0; i<size; ++i)
    {
        cout << _circularQ[(head+i) % MAX_N] << " ";
    }
    cout << endl;
  }
};

// max pqueue implementation
class myPriorityQueue
{
private:
  long int _myMaxHeap[MAX_N+1];
  long int last;
  
public:
  myPriorityQueue() { last = 0; }
  void clear() { last = 0; }
  
  bool insert(long int val) 
  {
    if(last == MAX_N) return false;
    _myMaxHeap[++last] = val;
    
    long int swap;
    long int parent, child;
    for(child=last, parent=child/2; parent>=1; child/=2, parent/=2)
    {
      if(_myMaxHeap[child] > _myMaxHeap[parent])
      {
        swap = _myMaxHeap[parent];
        _myMaxHeap[parent] = _myMaxHeap[child];
        _myMaxHeap[child] = swap;
      }
      else
        break; // once checkSwap fails, we know whatever's above us is in correct position so break out of loop
    }
    
    return true;
  }
  
  long int dequeueMax()
  {
    if(last == 0) return -1;
    
    long int retVal = _myMaxHeap[1];
    
    long int rootOfSubHeap=1, childOfSubHeap=2; // childOfSubHeap = 2 --> start with left child of root
    long int dangling = _myMaxHeap[last--];
    
    while(childOfSubHeap <= last)
    {
      if(childOfSubHeap < last && _myMaxHeap[childOfSubHeap] < _myMaxHeap[childOfSubHeap+1])
        ++childOfSubHeap;
    
        // we should insert value into current root (which is 'empty')
      if(dangling >= _myMaxHeap[childOfSubHeap])
        break;
    
      _myMaxHeap[rootOfSubHeap] = _myMaxHeap[childOfSubHeap]; 
        
      // move down before looping again
      rootOfSubHeap = childOfSubHeap;
      childOfSubHeap = rootOfSubHeap * 2;
    }
    
    // we found the place to insert the new value
    _myMaxHeap[rootOfSubHeap] = dangling;
    
    return retVal;
  }
  
  long int top() { return (last > 0 ? _myMaxHeap[0] : -1); }
  
  void print() 
  { 
    cout << "priority queue: ";
    for(int i=1; i<=last; ++i) cout << _myMaxHeap[i] << " ";
    cout << endl;
  }
};

int main()
{
    myStack s;
    myQueue q;
    myPriorityQueue pq;
    long int n;
    long int cmd, cmdarg;
    bool isStack, isQueue, isPQueue;
    string results[10];
    int tc=0;
    
    cin >> n;
    do
    {
      // reset the flags
      isStack = isQueue = isPQueue = true;
      
      // reset the ADTs
      s.clear();
      q.clear();
      pq.clear();
      
      for(int i=0; i<n; ++i)
      {
        cin >> cmd >> cmdarg;

        switch(cmd)
        {
          case 1:
            // once we know it is not a specific type of ADT, do not waste time inserting anymore
            if(isStack) s.push(cmdarg);
            if(isQueue) q.enqueue(cmdarg);
            if(isPQueue) pq.insert(cmdarg);
            break;
                
          case 2:
            // if the removal operation doesn't match, clear corresponding flag to indicate it is not a specific type of ADT, and forget about removal next time
            if(isStack && s.pop() != cmdarg) isStack = false;
            if(isQueue && q.dequeue() != cmdarg) isQueue = false;
            if(isPQueue && pq.dequeueMax() != cmdarg) isPQueue = false;
        }
      }
      
      // store the results
      if(isStack && !isQueue && !isPQueue) results[tc] = "stack";
      else if(!isStack && isQueue && !isPQueue) results[tc] = "queue";
      else if(!isStack && !isQueue && isPQueue) results[tc] = "priority queue";
      else if(!isStack && !isQueue && !isPQueue) results[tc] = "impossible";
      else results[tc] = "not sure";
      
      ++tc;
      
      cin >> n;
    } while(n != 0);
    
    for(int i=0; i<tc; ++i) cout << results[i] << endl;
    
    return 0;
}