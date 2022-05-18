#include "etree.cpp"

int eval(const etree* t){

    switch (t->value)
    {
    case ADD:
        return eval(t->left)+eval(t->right);
        break;
    case SUB:
        return eval(t->left)-eval(t->right);
        break;
    case MUL:
        return eval(t->left)*eval(t->right);
        break;
    case DIV:
        return eval(t->left)/eval(t->right);
        break;
    default:
        return t->value;
        break;
    }

}