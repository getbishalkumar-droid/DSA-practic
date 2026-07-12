#include<iostream>
using namespace std;

class node{
    public:

    int val;
    node* next;

    node(int v){
        val=v;
    }
};

void insertathead(node* &head ,int val){
    node* new_node=new node(val);
    new_node->next=head;
    head =new_node;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
    cout<<temp->val<<" ";
    temp=temp->next;
}
}

int main(){
    node* head=NULL;
    int choice=1;

    while(choice){
        int val;
        cout<<"enter the element : ";
        cin>>val;
        insertathead(head,val);
        cout<<head<<endl;
        cout<<"if you want to insert another element print 1 otherwise print 0 ";
        cin>>choice;
    }
    cout<<head<<endl;
      display(head);
}