// Huy Vu
// queue.h
// Purpose: Declaratation of class Queue
#include <cassert>

#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
 public:
  Queue();                             // constructor
  Queue(const Queue& aQueue);          // copy constructor
  Queue& operator=(const Queue& rhs);  // overloaded assignment operator
  ~Queue();                            // destructor

  bool enqueue(int data);     // add data to the queue
  bool dequeue(int& data);    // remove data from the queue
  bool isEmpty() const;       // check if the queue is empty or not

 private:
  struct QNode{   // create Node 
	int d;
	QNode* next;
  };

  QNode* front;   // front pointer
  QNode* tail;    // tail pointer
};

#endif
			 
