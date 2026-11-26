#ifndef STACK_H
#define STACK_H
#include <iostream>

#include "linkedList.hpp"
#include "node.hpp"
#define LOG(str) std::cout << str << std::endl  // Macors
class Stack {
 public:
  Stack();
  Stack(int sizeArray);
  ~Stack();
  Stack(Stack &s);
  void push(int data);
  int pop();
  void display(void);
  Stack &operator=(const Stack s);
  static int getactiveStacksCount();

 protected:
 private:
  node::node *top;
  //   int sizeArray;
  linkedList::linkedList *items;
  // 1. Declare a static variable to count active stacks
  static int activeStacksCount;
};

#endif  // STACK_H
