#include "Stack.h"

Stack::Stack() : size_(0), top_(nullptr) { }

Stack::~Stack(){

}

template <typename T>
size_t Stack<T>::size() {
    return size_;
}