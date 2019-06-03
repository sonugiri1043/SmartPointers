#include <memory>

template< class T > class my_shared_ptr {
 public:
  my_shared_ptr() {
    ref_count = NULL;
    obj_ptr = NULL;
  }     

  my_shared_ptr( T * obj_ptr ) {
    this->obj_ptr = obj_ptr;
    ref_count = new int;
    *ref_count = 1;
  }

  my_shared_ptr( const my_shared_ptr< T > &sp ) {
    if( sp.ref_count ) {
      *sp.ref_count = *sp.ref_count + 1;
      this->ref_count = sp.ref_count;
      this->obj_ptr = sp.obj_ptr;
    }  
  }  
   
  ~my_shared_ptr() {
    if( ref_count != NULL ) {
      *ref_count = *ref_count - 1;
      if( *ref_count == 0 ) {
	delete obj_ptr;
	delete ref_count;
	obj_ptr = NULL;
	ref_count = NULL;
      }
    }
  }     
            
  my_shared_ptr< T > & operator=( my_shared_ptr< T > &sp ) {
    *sp.ref_count = *sp.ref_count + 1;
    this->ref_count = sp.ref_count;
    this->obj_ptr = sp.obj_ptr;
    return *this;
  }        
            
  void reset() {
    if( ref_count ) {
      if( *ref_count > 1 ) {
	*ref_count = *ref_count - 1;
	this->ref_count = NULL;
	this->obj_ptr = NULL;
      } else {
	delete ref_count;
	ref_count = NULL;
	delete obj_ptr;
	obj_ptr = NULL;
      }
    }
  }
 
  int use_count() {
    if( ref_count ) {
      return *ref_count;
    }
    return 0;
  }
 
  T * get() {
    return obj_ptr;
  }
 
 private:
  int *ref_count;
  T *obj_ptr;
};

