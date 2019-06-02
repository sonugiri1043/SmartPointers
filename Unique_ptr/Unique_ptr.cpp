#include <iostream>
#include <memory> // unique_ptr

using std::cout;
using std::endl;
using std::unique_ptr;

// g++ Unique_ptr.cpp --std=c++14
// make_unique is only supported after c++14

/*
  In unique_ptr<>, one and only one unique_ptr<> has the Ownership
  of the Object and manages its lifetime. Its possible to transfer
  the ownership using std::move(). However, once std::move() is called
  then moved pointer will no longer hold the ownership.

  Just like shared_ptr<>, unique_ptr<> can also be returned from a Function.
  Why isn't transfer of ownership is prohibited in unique_ptr<> ?
  Compilers explicit add std::move() while returning the unique_ptr<>
  from a function which transfers the ownership.

  The C++14 specification has added the support of make_unique<>().
  Its usage is similar to that of make_shared<>() and should be used instead of new.

 */

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

void Unique_ptr_creation_using_make_unique() {
  unique_ptr<Test> ptr = std::make_unique<Test>();
}

void make_unique_without_ownership_trasnfer() {
  std::make_unique<Test>();
}
 
void make_unique_with_array() {
  unique_ptr< Test[] > ptr= std::make_unique<Test[]>(10);
  ptr[0].show();
  ptr[1].show();
}

int main() {
  Test_unique_ptr_ReleaseMemory_when_out_of_scope();
  Test_unique_ptr_No_OwnerShip_Transfer();
  Test_ownership_Transfer_using_move();
  fn_return_unique_ptr();
  Unique_ptr_creation_using_make_unique();
  make_unique_without_ownership_trasnfer();
  make_unique_with_array();
  return 0;
}
