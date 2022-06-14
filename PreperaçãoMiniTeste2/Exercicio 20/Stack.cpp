#include <iostream>
#include <iomanip>
using namespace std;

#include "Stack.h"

template <typename T>
Stack<T>::Stack() : size_(0), top_(nullptr) { }

template <typename T>
Stack<T>::~Stack()
{
    while (top_ != nullptr)
    {
        node<T> *temp = top_;
        top_ = top_->next;
        delete temp;
    }
}

template <typename T>
size_t Stack<T>::size() const { return size_; }

template <typename T>
bool Stack<T>::peek(T &elem) const
{
    if (size_ == 0)
        return false;
    elem = top_->value;
    return true;
}

template <typename T>
bool Stack<T>::pop(T &elem)
{
    if (size_ == 0)
        return false;
    elem = top_->value;
    node<T> *temp = top_;
    top_ = top_->next;
    delete temp;
    size_--;
    return true;
}

template <typename T>
void Stack<T>::push(const T &elem)
{
    node<T> *temp = new node<T>;
    temp->value = elem;
    temp->next = top_;
    top_ = temp;
    size_++;
}

int main()
{
    Stack<string> s;
    string v;
    s.push("a");
    s.push("b");
    s.push("c");
    cout << s.size();
    while (s.pop(v))
        cout << ' ' << v;
    cout << ' ' << s.size() << '\n';
    return 0;
}