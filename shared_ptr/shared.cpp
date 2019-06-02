#include <iostream>
#include <memory> // std::shared_ptr

using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;


class Test {
public:
  Test(){ cout<< "Constructor" << endl; }
  ~Test() { cout<< "Destructor" << endl; }
  void public_fn() { cout<< "Public function" << endl; }
};

// Memory gets freed when ptr goes out of scope
void shared_ptr_release_mem() {
  shared_ptr<Test> ptr( new Test() );
}

// use make_shared to get shared ptr
void shared_ptr_make_shared() {
  shared_ptr< Test > ptr = make_shared<Test>();
}

// function can return shared_ptr
shared_ptr<Test> return_shared_ptr() {
  shared_ptr<Test> ptr = make_shared<Test>();
  return ptr;
}

void shared_ptr_return_test() {
  shared_ptr<Test> shard_ptr = return_shared_ptr();
}

// reference count test
void shared_ptr_ref_count_test() {
  shared_ptr<Test> ptr1;
  shared_ptr<Test> ptr2( new Test() );
  cout<< ptr2.use_count() << endl;
  ptr1 = ptr2;
  cout<< ptr1.use_count() << endl;
  
  shared_ptr<Test> ptr3(ptr2);
  cout<< ptr3.use_count() << endl;

  cout<< "Stored pointer by shared ptrs" << endl;
  cout<< ptr1.get() << endl;
  cout<< ptr2.get() << endl;

  ptr3.reset();
  cout<< "use_count after reset" << endl;
  cout<< ptr1.use_count() << endl;
  cout<< ptr3.use_count() << endl;
}

int main() {
  cout<< "shared ptr reference count" << endl;
  shared_ptr_release_mem();
  cout<< "get shared ptr using make_shared" << endl;
  shared_ptr_make_shared();
  cout<< "shared pointer can be returned from a fn" << endl;
  shared_ptr_return_test();
  cout<< "Shared pointer ref count test" << endl;
  shared_ptr_ref_count_test();
  return 0;
}
