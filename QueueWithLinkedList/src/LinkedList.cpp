#include "../include/linkedList.hpp"

#include <iostream>

#include "../include/node.hpp"

namespace linkedList {
linkedList::linkedList() {
  head = NULL;
  tail = NULL;
}
linkedList::~linkedList() {
  node::node* current = head;
  //   current node;
  while (current != NULL) {
    head = current->next;
    delete current;
    current = head;
  }
  tail = NULL;
}
node::node* linkedList::GetData(int data) {
  node::node* current = head;
  while (current != NULL) {
    if (current->data == data) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void linkedList::AppendData(int data) {
  node::node* newNode = new node::node(data);
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
}
void linkedList::InsertAfter(int data, int afterData) {
  node::node* current = linkedList::GetData(afterData);
  if (current != NULL) {
    node::node* newNode = new node::node(data);
    if (current->next == NULL) {
      newNode->next = NULL;
      current->next = newNode;
      newNode->prev = current;
      tail = newNode;
    } else {
      newNode->next = current->next;
      newNode->prev = current;
      newNode->next->prev = newNode;
      current->next = newNode;
    }
  }
}
void linkedList::InsertBefore(int data, int beforeData) {
  node::node* current = linkedList::GetData(beforeData);
  if (current != NULL) {
    node::node* newNode = new node::node(data);
    if (current->prev == NULL) {
      newNode->prev = NULL;
      newNode->next = current;
      current->prev = newNode;
      newNode->next = current;
      head = newNode;
    } else {
      newNode->prev = current->prev;
      newNode->next = current;
      newNode->prev->next = newNode;
      current->prev = newNode;
    }
  }
}
int linkedList::GetCount() {
  int cnt = 0;
  node::node* current = head;
  while (current != NULL) {
    cnt++;
    current = current->next;
  }
  return cnt;
}
int linkedList::GetDataByIndex(int index) {
  if (index >= 0) {
    int currentIndex = 0;
    node::node* current = head;
    while (current != NULL) {
      if (currentIndex == index) {
        return current->data;
      }
      currentIndex++;
      current = current->next;
    }
  }
  return -1;
}
void linkedList::displayAllData() {
  std::cout << "List: \n";
  std::cout << "Cout: " << GetCount() << std::endl;

  for (int i = 0; i < GetCount(); i++) {
    std::cout << "at index " << i << ": " << GetDataByIndex(i) << "\n";
  }
  std::cout << std::endl;

  // std::cout << "Count: " << GetCount() << std::endl;
}

int linkedList::DeleteLastNode() {
  if (tail != NULL) {
    node::node* temp = tail;
    int data = tail->data;
    if (head == tail) {
      head = NULL;
      tail = NULL;
    } else {
      tail = tail->prev;
      tail->next = NULL;
    }
    // tail = tail->prev;
    delete temp;
    return data;
  }

  return -1;
}

int linkedList::DeleteFirstNode() {
  if (head != NULL) {
    node::node* temp = head;
    int data = head->data;
    if (head == tail) {
      head = NULL;
      tail = NULL;
    } else {
      head = head->next;
      head->prev = NULL;
    }
    // head = head->next;
    delete temp;
    return data;
  }

  return -1;
}
}  // namespace linkedList