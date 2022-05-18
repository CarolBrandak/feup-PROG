#include <iostream>
#include "alist.cpp"

using namespace std;

struct alist
{
  int size;      // Number of elements.
  int *elements; // List elements.
};

void append(alist *a, const alist *b)
{
  if (b->size == 0)
    return;
  int new_size = a->size + b->size;
  int *new_elements = new int[new_size];
  for (int i = 0; i < a->size; i++)
    new_elements[i]=a->elements[i];

  for (int i = 0; i < b->size; i++)
    new_elements[a->size+i]=b->elements[i];
  delete[] a->elements;
  a->size=new_size;
  a->elements=new_elements;
}