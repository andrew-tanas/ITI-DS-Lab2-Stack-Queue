#ifndef _NODE_HPP_
#define _NODE_HPP_

namespace node {
class node {
 public:
  int data;
  node* prev;
  node* next;
  node(int data);
  ~node();
};
}  // namespace node

#endif