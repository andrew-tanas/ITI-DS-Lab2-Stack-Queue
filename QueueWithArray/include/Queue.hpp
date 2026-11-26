#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_
#include <iostream>
#define LOG(str) std::cout << str << std::endl  // Macors
class Queue {
 public:
  Queue();
  Queue(int sizeArray);
  ~Queue();
  Queue(Queue &q);
  void push(int data);
  int pop(int *data);
  void display(void);
  Queue &operator=(const Queue q);
  static int getactiveQueuesCount();

 protected:
 private:
  int front;
  int rear;
  int sizeArray;
  int *items;
  // 1. Declare a static variable to count active stacks
  static int activeQueuesCount;
};

#endif  // STACK_H
