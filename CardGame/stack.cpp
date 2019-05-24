// Huy Vu
// stack.cpp
// Purpose: Implementation of stack.h

#include "stack.h"

using namespace std;

// constructor
Stack::Stack(int size)
{
  if (size <= 1)
	size = 50;
  max = size;                   // set stack size

  list = new int[max];          // allocate memory
  assert(list != nullptr);      
  top = 0;                      // set top starts at 0
}

// copy constructor
Stack::Stack(const Stack& aStack)
{
  max = aStack.max;
  list = new int[max];          // allocate memory
  assert(list != nullptr);
  top = aStack.top;
  for (int i = 0; i < top; i++) // copy data
	list[i] = aStack.list[i];
}

// overloaded assignment operator
Stack& Stack::operator=(const Stack& rhs)
{
  if (this != &rhs){
	delete [] list;               // deallocate memory 
	max = rhs.max;
	list = new int[max];          // allocate memory
	assert(list != nullptr);
	top = rhs.top;
	for (int i = 0; i < top; i++) // copy data
	  list[i] = rhs.list[i];
  }
  return *this;
}

// destructor
Stack::~Stack()
{
  delete [] list;
}

// Push item onto the stack
bool Stack::push(int data)
{
  bool available;

  if (isFull()){          // check if the stack is full or not
	available = resize(); // resize if it is full
	if (!available)       // return false if it is not available
	  return false;
  }
  list[top] = data;       // store data at top
  top++;
  return true;
}

// Remove item from the stack
bool Stack::pop(int& data)
{
  if (isEmpty())  // return false if stack is empty
	return false;
  top--;
  data = list[top];
  return true;
}

// Check if the stack is empty or not
bool Stack::isEmpty() const
{
  return top == 0;
}

// Check if the stack is full or not
bool Stack::isFull() const
{
  return top == max;
}

// Resize the stack
bool Stack::resize()
{
  int* tmp;
  int larger = static_cast<int>(max * 1.5); // make 1.5 times bigger
  tmp = new int[larger];                    // make new aray of new size
  if (tmp == nullptr)                       // check memory allocationa 
	return false;
  for (int i = 0; i < top; i++)             // copy data to new array
	tmp[i] = list[i];
  delete [] list;                           // delete old array
  list = tmp;                               // have pointer to the new array
  max = larger;                             // change to the new size
  return true;
}
