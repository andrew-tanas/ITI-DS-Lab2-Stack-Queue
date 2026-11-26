#include <iostream>

#include "../include/Queue.hpp"
using namespace std;

// 3. Definition and initialization of the static data member outside the class
int Queue::activeQueuesCount = 0;
int main() {
  Queue *q = new Queue();
  q->push(1);
  q->push(3);
  q->push(10);
  q->push(5);
  q->push(6);
  q->push(8);

  q->display();

  int x = q->pop();
  cout << x << endl;

  q->display();

  delete q;

  return 0;
}
