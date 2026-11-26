#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include "node.hpp"

using namespace node;

namespace linkedList {
class linkedList {
 private:
  node::node* GetData(int data);

 public:
  node::node* head;
  node::node* tail;
  linkedList();
  ~linkedList();

  void InsertAfter(int data, int afterData);
  void InsertBefore(int data, int beforeData);
  int GetCount();
  int GetDataByIndex(int index);
  void AppendData(int data);
  void displayAllData();
  int DeleteLastNode();
  int DeleteFirstNode();
};
}  // namespace linkedList

#endif