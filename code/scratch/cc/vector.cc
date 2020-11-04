// Definition of Resource: Anything that must be returned to someone else
// explicitly.
// Allocations (malloc, new, new[])
// POSIX file handles (open/close)
// C FILE handles (fopen/fclose)
// Mutex locks (pthread_mutex_lock/pthread_mutex_unlock)
// C++ Threads

#include <algorithm>
#include <cstdlib>
#include <except>

using size_t = std::size_t;

// class NaiveVector {
//  public:
//   NaiveVector() : ptr_(nullptr), size_(0) {}
//   void push_back(int new_value) {
//     int* new_ptr = new int[size_ + 1];
//     std::copy(ptr_, ptr_ + size_, new_ptr);
//     delete[] ptr_;
//     ptr_ = new_ptr;
//     ptr_[size_++] = new_value;
//   }

//  private:
//   int* ptr_;
//   size_t size_;
// };

// when you escape the current scope, NaiveVector needs to delete its memory.
// It doesn't do that right now.

/*
{
  NaiveVector vec;
  vec.push_back(1);
  vec.push_back(2);
} // memory leaks
*/

// and a destructor so memory doesn't leak.

// class NaiveVector {
//  public:
//   NaiveVector() : ptr_(nullptr), size_(0) {}
//   void push_back(int new_value) {
//     int* new_ptr = new int[size_ + 1];
//     std::copy(ptr_, ptr_ + size_, new_ptr);
//     delete[] ptr_;
//     ptr_ = new_ptr;
//     ptr_[size_++] = new_value;
//   }
//   ~NaiveVector() { delete[] ptr_; }

//  private:
//   int* ptr_;
//   size_t size_;
// };

/*
{
  NaiveVector v;
  v.push_back(1);
  {
    NaiveVector w = v; // this uses the default copy constructor, which only
copies elements.
  } // destructor runs for w.
  std::cout << v[0] << '\n'; // use after free.
}
*/

// Add a Copy Constructor
// class NaiveVector {
//  public:
//   NaiveVector() : ptr_(nullptr), size_(0) {}
//   ~NaiveVector() { delete[] ptr_; }
//   NaiveVector(const NaiveVector& rhs) {
//     ptr_ = new int[rhs.size_];
//     size_ = rhs.size_;
//     std::copy(rhs.ptr_, rhs.ptr_ + size_, ptr_);
//   }
//   void push_back(int new_value) {
//     int* new_ptr = new int[size_ + 1];
//     std::copy(ptr_, ptr_ + size_, new_ptr);
//     delete[] ptr_;
//     ptr_ = new_ptr;
//     ptr_[size_++] = new_value;
//   }

//  private:
//   int* ptr_;
//   size_t size_;
// };

// Copy Assignment has the same problem.
/*
{
  NaiveVector v;
  v.push_back91);
  {
    NaiveVector w;
    w = v;
  }
  std::cout << v[0] << '\n';
}
*/

// class NaiveVector {
//  public:
//   NaiveVector() : ptr_(nullptr), size_(0) {}
//   ~NaiveVector() { delete[] ptr_; }
//   NaiveVector(const NaiveVector& rhs) {
//     ptr_ = new int[rhs.size_];
//     size_ = rhs.size_;
//     std::copy(rhs.ptr_, rhs.ptr_ + size_, ptr_);
//   }
//   NaiveVector& operator=(const NaiveVector& rhs) {
//     NaiveVector copy = rhs;
//     copy.swap(*this);
//     return *this;
//   }
//   void push_back(int new_value) {
//     int* new_ptr = new int[size_ + 1];
//     std::copy(ptr_, ptr_ + size_, new_ptr);
//     delete[] ptr_;
//     ptr_ = new_ptr;
//     ptr_[size_++] = new_value;
//   }

//  private:
//   int* ptr_;
//   size_t size_;
// };

// Rule of Three: You need a destructor to free the resources
// A copy constructor to copy the resource
// A copy assignment operator to free the left hand resource and copy the right
// hand one.

// RAII and exception safety:
// Types that use a destructor are exception safe.

// struct RAIIPtr {
//   int *ptr_;
//   RAIIPtr(int *p) : ptr_(p) {}
//   ~RAIIPtr() { delete[] ptr_; }
//   RAIIPtr(const RAIIPtr &) = delete;
//   RAIIPtr &operator=(const RAIIPtr &) = delete; // this is now non copyable.
// };

// int main() {
//   try {
//     RAIIPtr arr = new int[4];
//     throw std::runtime_error("For example");
//   } catch (const std::exception &e) {
//     std::cout << "Caught an exception: " << e.what() << '\n';
//   }
// }

// The rule of zero: if your class does not manage any resource
// don't write a special member function.

// The rule of 5:
// when your class manages a resource, hand write these five special member
// functions

// destructor to free
// copy constructor to copy
// move constructor to transfer ownership
// copy assignment operator to free the left hand and copy the right
// move assignment operator to free the left hand and transfer to the right.
