#include <iostream> 
#include <memory>
#include "my_shared_ptr.h" 
 
using std::cout; 
using std::endl; 
using std::shared_ptr; 
 
class Test { 
public: 
  Test() { cout << "Test constructor" << endl; } 
  ~Test() { cout << "Test destructor" << endl; } 
}; 

// Test to verify that empty shared_ptr has 0 use_count
// and doesn't point to anything.
void test_my_shared_ptr() {
  cout<< "Empty shared_ptr use_count test." << endl; 
  shared_ptr< Test > ptr; 
  cout<< "Use count of empty ptr:" << ptr.use_count() << endl; 
  cout<< ptr.get() << endl; 

  my_shared_ptr< Test > my_ptr; 
  cout<< "Use count of empty ptr:" << my_ptr.use_count() << endl; 
  cout<< my_ptr.get() << endl; 
  cout<< endl; 
}

void test_my_shared_ptr_creation() {
  cout<< "Test shared_ptr creation." << endl; 
  shared_ptr< Test > ptr( new Test() ); 
  cout<< "Use count:" << ptr.use_count() << endl; 
  cout<< ptr.get() << endl;

  my_shared_ptr< Test > my_ptr( new Test() ); 
  cout<< "Use count:" << my_ptr.use_count() << endl; 
  cout<< my_ptr.get() << endl;
  cout<< endl; 
}

void test_my_shared_ptr_assignment() {
  cout<< "Test assignment operation" << endl; 
  shared_ptr< Test > ptr1( new Test() );
  shared_ptr< Test > ptr2; 
  ptr2 = ptr1; 
  cout<< "Use count:" << ptr1.use_count() << endl; 
  shared_ptr< Test > ptr3;
  ptr3 = ptr2;
  cout<< "Use count:" << ptr2.use_count() << endl; 
  cout<< "Use count:" << ptr3.use_count() << endl; 

  my_shared_ptr< Test > my_ptr1( new Test() );
  my_shared_ptr< Test > my_ptr2;
  my_ptr2 = my_ptr1;
  cout<< "Use count:" << my_ptr1.use_count() << endl;
  my_shared_ptr< Test > my_ptr3;
  my_ptr3 = my_ptr2;
  cout<< "Use count:" << my_ptr2.use_count() << endl;
  cout<< "Use count:" << my_ptr3.use_count() << endl;
  cout<< endl;
}

void test_my_shared_ptr_copy() {
  cout<< "Test copy operation" << endl; 
  shared_ptr< Test > ptr( new Test() ); 
  shared_ptr< Test > ptr1( ptr ); 
  cout<< "Use count:" << ptr.use_count() << endl; 
  cout<< "Use count:" << ptr1.use_count() << endl; 

  my_shared_ptr< Test > my_ptr( new Test() ); 
  my_shared_ptr< Test > my_ptr1( my_ptr ); 
  cout<< "Use count:" << my_ptr1.use_count() << endl; 
  cout<< "Use count:" << my_ptr.use_count() << endl; 
  cout<< endl; 
}

void test_my_shared_ptr_reset() {
  cout<< "Test reset operation." << endl; 
  shared_ptr< Test > ptr1( new Test() ); 
  shared_ptr< Test > ptr2( ptr1 );
  shared_ptr< Test > ptr3 = ptr2;
  ptr3.reset();
  cout<< ptr1.use_count() << endl; 
  cout<< ptr3.use_count() << endl; 
  ptr2.reset(); 
  ptr1.reset(); 
  cout<< ptr1.use_count() << endl; 

  my_shared_ptr< Test > my_ptr1( new Test() ); 
  my_shared_ptr< Test > my_ptr2( my_ptr1 );
  my_shared_ptr< Test > my_ptr3 = my_ptr2;
  my_ptr3.reset(); 
  cout<< my_ptr1.use_count() << endl; 
  cout<< my_ptr3.use_count() << endl; 
  my_ptr2.reset(); 
  my_ptr1.reset(); 
  cout<< my_ptr1.use_count() << endl; 
  cout<< endl; 
}
 
int main() { 
  test_my_shared_ptr();
  test_my_shared_ptr_creation();
  test_my_shared_ptr_assignment();
  test_my_shared_ptr_copy();
  test_my_shared_ptr_reset();
  return 0;
}
