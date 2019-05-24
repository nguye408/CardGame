// Huy Vu
// stack.h
// Purpose: Declaration of class Stack
#include <cassert>

#ifndef STACK_H
#define STACK_H

class Stack
{
 public:
  explicit Stack(int size = 50);        // constructor
  Stack(const Stack& aStack);           // copy constructor
  Stack& operator=(const Stack& rhs);   // overloaded assignment operator
  ~Stack();                             // destructor
  
  bool push(int data);    // Push item onto the stack
  bool pop(int& data);    // Remove item from the stack
  bool isEmpty() const;   // check if the stack is empty or not

 private:
  int* list;        // pointer list 
  int max;          // maximum size of stack 
  int top;          // top of the stack

  bool isFull() const; // check if the stack is full or not
  bool resize();       // resize stack
};
#endif
