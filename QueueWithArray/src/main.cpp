#include <iostream>

#include "../include/Queue.hpp"
using namespace std;

int Queue::activeQueuesCount = 0;
int main() {
  int x;
  Queue *q = new Queue(5);
  q->push(1);
  q->push(2);
  q->push(3);
  q->push(4);
  q->push(5);
  q->push(5);
  q->pop(&x);
  q->pop(&x);
  q->push(6);
  q->push(7);
  q->push(8);
  q->pop(&x);
  q->pop(&x);
  q->pop(&x);
  q->pop(&x);
  q->pop(&x);
  q->pop(&x);
  q->push(1);
  q->push(2);
  q->push(3);
  q->push(4);
  q->push(5);
  q->push(5);
  q->display();
  delete q;

  return 0;
}
