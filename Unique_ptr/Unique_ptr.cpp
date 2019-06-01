#include <iostream>
#include <memory> // unique_ptr

using std::cout;
using std::endl;
using std::unique_ptr;

// g++ Unique_ptr.cpp --std=c++14

class Test {
public:
  Test() {
    std::cout<< "Test constructor called." << endl;
  }
  ~Test() {
    std::cout<< "Test destructor called." << endl;
  }
  void show() {
    std::cout<< "public method" << endl;
  }
};

// Destructor is called when unique_ptr goes out of scope
void Test_unique_ptr_ReleaseMemory_when_out_of_scope() {
  unique_ptr<Test> u( new Test() );
  u->show();
  return;
}

// Destructor gets called as there is no owner for returned unique_ptr
unique_ptr< Test> Test_unique_ptr_No_OwnerShip_Transfer() {
  unique_ptr<Test> u( new Test() );
  u->show();
  // Compiler changes this to "return move( uni )
  return u;
}
 
// Unique pointer can be assigned to another using std::move
void Test_ownership_Transfer_using_move() {
  unique_ptr<Test> u1( new Test() );
  unique_ptr<Test> u2;
  // u2 = u1; // this would fail to compile
  u2 = move( u1 );
  u2->show();
  return;
}
 
//unique_ptr can be returned from a function
unique_ptr<Test> fn_return_unique_ptr() {
  cout<< "Unique pointer returned from fn." << endl;
  unique_ptr< Test > uni ( new Test );
  //Compiler changes this to "return move( uni )
  return uni;
}
 
int main() {
  Test_unique_ptr_ReleaseMemory_when_out_of_scope();
  Test_unique_ptr_No_OwnerShip_Transfer();
  Test_ownership_Transfer_using_move();
  fn_return_unique_ptr();
  return 0;
}
