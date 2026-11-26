#include "../include/Queue.hpp"

int Queue ::getactiveQueuesCount() {
  // LOG(this->top);//Compiler Error Unabialable for Static memberFunction
  return activeQueuesCount;
}
Queue::Queue() {
  activeQueuesCount++;
  LOG("No Parameter Constructor Queue()");
  this->sizeArray = 10;
  this->front = -1;
  this->rear = -1;
  this->items = new int[sizeArray]{0};
  // ctor
}
Queue::Queue(Queue& q) {
  activeQueuesCount++;
  LOG("Copy Constructor :: ");
  this->items = new int[q.sizeArray];
  this->sizeArray = q.sizeArray;
  this->rear = q.rear;
  this->front = q.front;
  int start = rear;
  while (start != front) {
    this->items[start] = q.items[start];
    start = (start + 1) % sizeArray;
  }
}
Queue::Queue(int sizeArray) {
  activeQueuesCount++;
  LOG("Parameter Constructor Queue()");
  this->sizeArray = sizeArray;
  this->rear = -1;
  this->front = -1;
  this->items = new int[sizeArray];
  // ctor
}
void Queue::push(int data) {
  if ((rear == 0 && front == sizeArray) || ((front + 1) % sizeArray == rear)) {
    LOG("Queue is FULL");
    return;
  } else {
    if (front == -1 && rear == -1) {
      rear++;
      items[++front] = data;
    } else {
      front = (front + 1) % sizeArray;

      items[front] = data;
    }
  }

  // front = (front + 1) % sizeArray;
}
// }
int Queue::pop(int* data) {
  if (rear == -1 && front == -1) {
    LOG("Queue is EMPTY");
  } else {
    if (front == rear) {
      *data = items[rear];
      rear = -1;
      front = -1;
    } else {
      *data = items[rear];
      rear = (rear + 1) % sizeArray;
    }
    return 1;
  }

  return 0;
}
void Queue::display(void) {
  int start = rear;
  if (rear != -1 && front != -1) {
    while (start != front) {
      LOG(items[start] << "--->");
      start = (start + 1) % sizeArray;
    }
    LOG(items[front] << "--->");
  }
}
Queue& Queue::operator=(const Queue q) {
  LOG("Assgiment Operator :: ");
  delete[] this->items;
  items = new int[q.sizeArray];
  this->sizeArray = q.sizeArray;
  this->rear = q.rear;
  this->front = q.front;
  int start = rear;
  while (start != front) {
    this->items[start] = q.items[start];
    start = (start + 1) % sizeArray;
  }
  return *this;
}

Queue::~Queue() {
  LOG("Destructor");
  activeQueuesCount--;
  delete[] items;
  // dtor
}
