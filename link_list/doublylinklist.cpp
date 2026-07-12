#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* prev;
    node* next;
    node(int v){
        val=v;
        prev=NULL;
        next=NULL;
    }
};
class doublylinklist{
     public:
     node* head;
     node* tail;
    doublylinklist(){
        head=NULL;
        tail=NULL;
    }
//create function for inserting at start    
    void insertatstart(int val){
        node* new_node=new node(val);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        head->prev=new_node;
        new_node->next=head;
        head=new_node;
    }
//create function for inserting at tail
void insertattail(int val){
    node* new_node=new node(val);
    if(tail==NULL){
        head=new_node;
        tail=new_node;
        return;
    }
    tail->next=new_node;
    new_node->prev=tail;
    tail=new_node;
}    
//create function for display element from head
   void displayfromhead(){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
   }
   
//create function for display element from head
   void displayfromtail(){
    node* temp=tail;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->prev;
    }
   }
//create a function for inserting a element at kth position from starting and end
void insertatkthpostionst(int val,int pos){
    if(pos==1){
      insertatstart(val);
      return;  
    }
    node* new_node=new node(val);
    node* temp=head;
    for(int i=1;i<pos-1;i++){
       temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next->prev=new_node;
    new_node->prev=temp;
    temp->next=new_node;

    return;
}
//position from tail
void insertatkthpostiontl(int val,int pos){
    if(pos==1){
      insertattail(val);
      return;  
    }
    node* new_node=new node(val);
    node* temp=tail;
    for(int i=1;i<pos-1;i++){
       temp=temp->prev;
    }
    new_node->prev=temp->prev;
    temp->prev->next=new_node;
    new_node->next=temp;
    temp->prev=new_node;

    return;
}
//create a function for deleting head element 
void deletehead(){
    if(head==NULL){
        return;
    }
    node* temp=head;
    head=head->next;
    if(head==NULL){
        tail=NULL;
    }
    else{
    head->prev=NULL;
    free(temp);
    }
}
//create a function for deleting tail
void deletetail(){
    if(head==NULL){
        return;
    }
    node* ptr=tail;
    tail=tail->prev;
    if(tail==NULL){
        head=NULL;
    }
    else{
    tail->next=NULL;
    }
     free(ptr);
} 
//create a function for deleting at kth position
void deletekpos(int pos){
    if(pos==1){
        deletehead();
        return;
    }
    node* temp=head;
    for(int i=1;i<pos;i++){
       temp=temp->next;
    }
    node* ptr=temp;
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(ptr);

}  
};

int main(){
    doublylinklist dll;
    dll.insertattail(1);
    cout<<"head="<<dll.head<<" tail="<<dll.tail<<endl;
    dll.insertattail(2);
    cout<<"head="<<dll.head<<" tail="<<dll.tail<<endl;
    dll.insertattail(3);
    cout<<"head="<<dll.head<<" tail="<<dll.tail<<endl;
    dll.insertattail(4);
    cout<<"head="<<dll.head<<" tail="<<dll.tail<<endl;
    dll.insertattail(5);
    cout<<"head="<<dll.head<<" tail="<<dll.tail<<endl;
    dll.insertattail(6);
    cout<<"head="<<dll.head<<" tail="<<dll.tail<<endl;
    dll.displayfromhead();
    cout<<endl;
    
    dll.deletekpos(4);
    dll.displayfromhead();
    
}

