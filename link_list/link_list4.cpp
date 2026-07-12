// deletion of element from link list
#include<iostream>
using namespace std;

//defining node class
class node{
    public:
    int val;
    node* next;

    node(int v){
        val=v;
        next=NULL;
    }

};

//insert at head function

void insertathead(node* &head,int v){
    node* new_node=new node(v);
    new_node->next=head;
    head=new_node;
}

//insert at tell function
void insertattell(node* head,int v){
    node* new_node=new node(v);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}

//insert at given position function

void insert(node* head,int val,int pos){
    if(1==pos){
        insertathead(head,val);
    }
    else{
    node* new_node=new node(val);
    node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    }
}


//update at given position

void update(node* head,int v,int pos){
    node* temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    temp->val=v;
}

//delete from heading
void delhead(node* &head){
    node* ptr=head;
    head=head->next;
    free(ptr);
}

//delete tail
void deltail(node* head){
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* ptr=temp->next;
    temp->next=NULL;
    free(ptr);
    
}

//delete from any position
void del(node* head,int pos){
    if(pos==1){
        delhead(head);
    }
    else{
    node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    node* ptr=temp->next;
    temp->next=temp->next->next;
    free(ptr);} 
}
 //display node element
 void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main(){
    node* head=NULL;
    insertathead(head,2);
    insertattell(head,3);
    insertathead(head,1);
    insert(head,4,3);
    update(head,3,3);
    update(head,4,4);
    delhead(head);
    deltail(head);
    insertattell(head,4);
    del(head,2);
    display(head);
    
    return 0;
}