#include <iostream>

#include "../include/Stack.hpp"
using namespace std;

void viewStack(Stack &s) { s.display(); }

// Stack returnStack() {
//   // Stack s(5);
//   // return s;
//   return Stack(5);
// }

// 3. Definition and initialization of the static data member outside the class
int Stack::activeStacksCount = 0;
int main() {
  // Stack s();//Stack
  //  Stack s5(s);//Stack
  // Stack s2(10);//Stack
  Stack *s = new Stack();
  s->push(1);
  s->push(3);
  s->push(10);
  s->push(5);
  s->push(6);
  s->push(8);

  s->display();

  int x = s->pop();
  cout << x << endl;

  s->display();

  delete s;

  return 0;
}
