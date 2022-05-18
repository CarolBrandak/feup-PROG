#include "node.cpp"

node* reverse(const node *n)
{
    if(n==nullptr)
        return nullptr;
    node* aux=new node{n->value, nullptr, nullptr}; 
    n=n->next;
    while(n!=nullptr){
        aux->prev = new node{n->value, nullptr, aux};
        n=n->next;
        aux=aux->prev;
    }
    return aux;
}

int main(){
    node* a = build(1, nullptr);
    node* b = reverse(a);
    print(b);
    destroy(a); destroy(b);
    return 0;

}