#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

template <typename T1, typename T2>
class Pair
{
public:
    Pair(T1 first, T2 second);
    T1 get_first() const;
    T2 get_second() const;
    void show();

private:
    T1 first_;
    T2 second_;
};

template <typename T1, typename T2>
Pair<T1, T2>::Pair(T1 first, T2 second) : first_(first), second_(second) {}

template <typename T1, typename T2>
T1 Pair<T1, T2>::get_first() const { return first_; }

template <typename T1, typename T2>
T2 Pair<T1, T2>::get_second() const { return second_; }

template <typename T1, typename T2>
void Pair<T1, T2>::show() { cout << "{" << first_ << "," << second_ << "}"; }

template <typename T1, typename T2>
void sort_by_first(vector<Pair<T1, T2>> &p)
{
    for (unsigned i = 1; i < p.size(); i++) {
        Pair<T1, T2> tmp = p[i];
        unsigned j;
        for (j = i; j > 0 && tmp.get_first() < p[j-1].get_first(); j--){
            p[j] = p[j-1];
        }
        p[j] = tmp;
    } 
}

template <typename T1, typename T2>
void sort_by_second(vector<Pair<T1, T2>> &p)
{   
    for (unsigned i = 1; i < p.size(); i++) {
        Pair<T1, T2> tmp = p[i];
        unsigned j;
        for (j = i; j > 0 && tmp.get_second() < p[j-1].get_second(); j--){
            p[j] = p[j-1];
        }
        p[j] = tmp;
    } 
}

template <typename T1, typename T2>
void show(vector<Pair<T1, T2>> p)
{
    cout << "{";
    for (auto i : p)
    {
        i.show();
    }
    cout << "}";
}

int main()
{
    vector<Pair<string, int>> persons = {{"Maria", 17}, {"Ana", 21}, {"Pedro", 19}};
    sort_by_first(persons);
    show(persons);
    cout << '\n';
    return 0;
}