#include <iostream>
#include "node.cpp"

using namespace std;

node *remove(int x, node *n)
{
    node *curr = n;
    node *prev = nullptr;
    while (curr != nullptr && curr->value != x)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr != nullptr)
    {
        if (prev == nullptr)
            n = curr->next;
        else
            prev->next = curr->next;
        delete curr;
    }
    return n;
}