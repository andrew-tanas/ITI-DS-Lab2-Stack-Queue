#include "../include/Queue.hpp"

#include "../include/linkedList.hpp"

int Queue ::getactiveQueuesCount() {
  // LOG(this->top);//Compiler Error Unabialable for Static memberFunction
  return activeQueuesCount;
}
Queue::Queue() {
  activeQueuesCount++;
  LOG("No Parameter Constructor Queue()");
  this->items = new linkedList::linkedList();
  this->front = items->tail;
  this->rear = items->head;
  // ctor
}
Queue::Queue(Queue& s) {
  activeQueuesCount++;
  LOG("Copy Constructor :: ");
  this->items = new linkedList::linkedList();
  // this->sizeArray = s.sizeArray;
  for (node::node* current = items->head; current != nullptr;
       current = current->next) {
    this->items->AppendData(current->data);
  }
  front = this->items->tail;
  rear = this->items->head;
}
// Queue::Queue(int sizeArray) {
//   activeQueuesCount++;
//   LOG("Parameter Constructor Queue()");
//   this->sizeArray = sizeArray;
//   this->top = -1;
//   this->items = new int[sizeArray];
//   // ctor
// }
void Queue::push(int data) {
  items->AppendData(data);
  if (items->head == nullptr) {
    rear = items->head;
  }
  front = items->tail;
  LOG("We Write index :" << front->data);
}
int Queue::pop() {
  if (rear == nullptr && front == nullptr) {
    LOG("Queue Empty");
    return -1;
  } else {
    return items->DeleteFirstNode();
    front = items->tail;
  }
}

void Queue::display(void) { items->displayAllData(); }

Queue& Queue::operator=(const Queue s) {  // Queue1 = Queue2
  LOG("Assgiment Operator :: ");
  delete this->items;
  items = new linkedList::linkedList();
  for (node::node* current = items->head; current != nullptr;
       current = current->next) {
    this->items->AppendData(current->data);
  }
  front = this->items->tail;
  rear = this->items->head;

  return *this;
}

Queue::~Queue() {
  LOG("Destructor");
  activeQueuesCount--;
  delete items;
  // dtor
}
