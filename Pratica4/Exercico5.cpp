#include "svnode.cpp"

svnode *sum(const svnode *a, const svnode *b)
{
    svnode *res = nullptr;
    auto svn1 = a;
    auto svn2 = b;

    while (svn1 != nullptr && svn2 != nullptr)
    {
        if (svn1->position < svn2->position)
        {
            res = build(svn1->position, svn1->value, res);
            svn1 = svn1->next;
        }
        else if (svn1->position > svn2->position)
        {
            res = build(svn2->position, svn2->value, res);
            svn2 = svn2->next;
        }
        else if (svn1->position == svn2->position)
        {
            if (svn1->value + svn2->value != 0)
            {
                res = build(svn1->position, svn1->value + svn2->value, res);
            }
            svn1 = svn1->next;
            svn2 = svn2->next;
        }
    }

    while (svn1 != nullptr || svn2 != nullptr)
    {
        if (svn1 != nullptr)
        {
            res = build(svn1->position, svn1->value, res);
            svn1 = svn1->next;
        }
        else if (svn2 != nullptr)
        {
            res = build(svn2->position, svn2->value, res);
            svn2 = svn2->next;
        }
    }

    return res;
}