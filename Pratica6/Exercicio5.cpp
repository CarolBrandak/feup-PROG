#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct sm_entry {
  size_t row;
  size_t col;
  int value;
};

typedef vector<sm_entry> smatrix;

//! Print a sparse matrix.
void print(const smatrix& sm) {
  cout << "[ ";
  for (sm_entry e : sm) {
    cout << '(' << e.row << ", " << e.col << ", " << e.value << ") ";
  }
  cout << "]\n";
}

void sum(const smatrix& a, const smatrix& b, smatrix& r) {
    size_t ai = 0, bi = 0;

    while (ai + bi < a.size() + b.size()) {
        if (ai < a.size() && bi < b.size()) {
            if (a[ai].row == b[bi].row && a[ai].col == b[bi].col) {
                if (a[ai].value + b[bi].value != 0)
                    r.push_back({a[ai].row, a[ai].col, a[ai].value + b[bi].value});
                ai++;
                bi++;
            }
            else if (a[ai].row < b[bi].row || (a[ai].row == b[bi].row && a[ai].col < b[bi].col)) {
                r.push_back(a[ai]);
                ai++;
            }
            else {
                r.push_back(b[bi]);
                bi++;
            }
        }
        else if (ai < a.size()) {
            if (a[ai].value != 0)
                r.push_back(a[ai]);
            ai++;
        }
        else {
            if (b[bi].value != 0)
                r.push_back(b[bi]);
            bi++;
        }
    }
}