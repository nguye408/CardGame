// Huy Vu
// queue.cpp
// Purpose: Implementation for queue.cpp

#include "queue.h"

// constructor
Queue::Queue()
{
  front = nullptr;
  tail = nullptr;
}

// copy constructor
Queue::Queue(const Queue& aQueue)
{
  QNode* tmp;
  if (aQueue.front == nullptr){
	front = nullptr;
	tail = nullptr;
  }else{
	front = new QNode;
	assert(front != nullptr);
	front->d = aQueue.front->d;
	tail = front;
	tmp = aQueue.front->next;
	while (tmp != nullptr){
	  tail->next = new QNode;
	  assert(tail->next != nullptr);
	  tail = tail->next;
	  tail->d = tmp->d;
	  tmp = tmp->next;
	}
	tail->next = nullptr;
  }
}

// overloaded assignment operator
Queue& Queue::operator=(const Queue& rhs)
{
  QNode* tmp;
  if (this != &rhs){
	while (front != nullptr){
	  tmp = front;               // let tmp point to the front of the queue
	  front = front->next;       // set front to the next value
	  delete tmp;                // delete tmp list
	}

	if (rhs.front == nullptr){
	  front = nullptr;
	  tail = nullptr;
	}else{
	  front = new QNode;
	  assert(front != nullptr);
	  front->d = rhs.front->d;   // check memory
	  tail = front;
	  tmp = rhs.front->next;
	  while (tmp != nullptr){
		tail->next = new QNode;
		assert(tail->next != nullptr);
		tail = tail->next;
		tail->d = tmp->d;
		tmp = tmp->next;
	  }
	  tail->next = nullptr;
	}
  }
  return *this;
}

// destructor
Queue::~Queue()
{
  QNode* tmp;
  while (front != nullptr){
	tmp = front;
	front = front->next;
	delete tmp;
  }
}

// add data to the queue
bool Queue::enqueue(int data)
{
  if (front == nullptr){
	front = new QNode;
	if (front == nullptr)
	  return false;
	front->d = data;
	front->next = nullptr;
	tail = front;
  }else{
	tail->next = new QNode;
	if (tail->next == nullptr)
	  return false;
	tail = tail->next;
	tail->d = data;
	tail->next = nullptr;
  }
  return true;
}

// remove data from the queue
bool Queue::dequeue(int& data)
{
  QNode* tmp;
  if (front == nullptr)
	return false;
  data = front->d;
  tmp = front;
  front = front->next;
  delete tmp;
  return true;
}

// check if the queue is empty or not
bool Queue::isEmpty() const
{
  return front == nullptr;
}
