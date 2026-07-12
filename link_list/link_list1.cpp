#include<iostream>
using namespace std;

class Node{
    public:
    int Value;
    Node* next;

    Node(int value){
        Value=value;
        next=NULL;
    }


        
};

int main(){
    Node* n=new Node(1);
    cout<<n->Value<<" "<<n->next<<endl;//head=n(n is a ptr)

}
