#include "../include/node.hpp"

#include <iostream>

namespace node {
node::node(int data) {
  this->data = data;
  prev = NULL;
  next = NULL;
}
node::~node() = default;
}  // namespace node
