#include "dlnode.cpp"

dlnode *insert(dlnode *dln, int k, int v)
{
    if (dln == nullptr)
    {
        dlnode *res = new dlnode{v, nullptr, nullptr};
        return res;
    }
    if (k == 0)
    {
        dlnode *res = new dlnode{v, nullptr, dln};
        dln->prev = res;
        return res;
    }

    dlnode *prev;
    dlnode *firstNode = dln;

    while (k > 0)
    {
        if (dln->next == nullptr)
        {
            dlnode *res = new dlnode{v, dln, nullptr};
            dln->next = res;
            return firstNode;
        }
        prev = dln;
        dln=dln->next;
        k--;
    }
    dlnode *res = new dlnode{v, prev, dln};
    dln->prev = res;
    prev->next = res;
    return firstNode;
}