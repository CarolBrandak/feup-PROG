#include "node.cpp"

node* reverse(const node* n){
    if(n==nullptr)
        return nullptr;
    node* aux= new node{n->value, nullptr, nullptr};
    n=n->next;
    while(n!=nullptr){
        aux->prev=new node{n->value, nullptr, aux};
        n=n->next;
        aux=aux->prev;
    }
    return aux;

}