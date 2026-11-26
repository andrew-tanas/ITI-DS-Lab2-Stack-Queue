#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <iostream>

#include "linkedList.hpp"
#include "node.hpp"

#define LOG(str) std::cout << str << std::endl  // Macors
class Queue {
 public:
  Queue();
  ~Queue();
  Queue(Queue &s);
  void push(int data);
  int pop();
  void display(void);
  Queue &operator=(const Queue s);
  static int getactiveQueuesCount();

 protected:
 private:
  node::node *front;
  node::node *rear;
  linkedList::linkedList *items;
  // 1. Declare a static variable to count active Queues
  static int activeQueuesCount;
};

#endif  // STACK_H
