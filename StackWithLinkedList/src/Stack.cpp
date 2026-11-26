#include "../include/Stack.hpp"

#include "../include/linkedList.hpp"

int Stack ::getactiveStacksCount() {
  // LOG(this->top);//Compiler Error Unabialable for Static memberFunction
  return activeStacksCount;
}
Stack::Stack() {
  activeStacksCount++;
  LOG("No Parameter Constructor Stack()");
  // this->sizeArray = 10;
  this->top = nullptr;
  this->items = new linkedList::linkedList();
  // ctor
}
Stack::Stack(Stack& s) {
  activeStacksCount++;
  LOG("Copy Constructor :: ");
  this->items = new linkedList::linkedList();
  // this->sizeArray = s.sizeArray;
  // this->top->data = s.top->data;
  for (node::node* current = s.items->head; current != nullptr;
       current = current->next) {
    this->items->AppendData(current->data);
  }
  this->top = this->items->tail;
}
// Stack::Stack(int sizeArray) {
//   activeStacksCount++;
//   LOG("Parameter Constructor Stack()");
//   this->sizeArray = sizeArray;
//   this->top = -1;
//   this->items = new int[sizeArray];
//   // ctor
// }
void Stack::push(int data) {
  // 5 items push() push()   push() push() push()
  // this->top->data = (this->top->data) + 1;  // 0        1        2      3 4
  LOG("We Write index :" << top);
  this->items->AppendData(data);
  this->top = this->items->tail;
}
int Stack::pop() {
  if (top == nullptr) {
    LOG("Stack Empty");
    return -1;
  } else {
    int data = items->DeleteLastNode();
    top = items->tail;
    return data;
  }
}

void Stack::display(void) { items->displayAllData(); }

Stack& Stack::operator=(const Stack s) {  // stack1 = stack2
  LOG("Assgiment Operator :: ");
  delete this->items;
  items = new linkedList::linkedList();
  // this->sizeArray = s.sizeArray;
  // this->top = s.top;
  for (node::node* current = s.items->head; current != nullptr;
       current = current->next) {
    this->items->AppendData(current->data);
  }
  this->top = this->items->tail;
  return *this;
}

Stack::~Stack() {
  LOG("Destructor");
  activeStacksCount--;
  delete items;
  // dtor
}
