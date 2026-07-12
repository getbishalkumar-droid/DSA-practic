#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;

    node(int v){
        val=v;
        next=NULL;
    }
};

void insertatlast(node* head,int val){
    node* new_node=new node(val);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}

void insert(node*head,int val,int position){
    if(position==1){
        cout<<"use insertion at head";
    }

    else{
    node* new_node=new node(val);
    node* temp=head;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
    }
    node* tptr;
    tptr=new_node;
    new_node->next=temp->next;
    temp->next=tptr;}

}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

void update(node* head,int v,int position){
    node* temp=head;
    for(int i=1;i<position;i++){
        temp=temp->next;
    }
    temp->val=v;
}

int main(){
    node* head=new node(3);
    insertatlast(head,5);
    insertatlast(head,5);
    insertatlast(head,5);
    insert(head,9,3);
    update(head,4,2);
    

    display(head);

return 0;   

}