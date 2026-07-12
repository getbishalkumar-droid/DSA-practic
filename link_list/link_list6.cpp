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

class linklist{
   public:
   node* head;

   linklist(){
    head=NULL;
   }

   void insertatend(int val){
    node* new_node=new node(val);
    if(head==NULL){
        head=new_node;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
   }

   void display(){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"\t";
        temp=temp->next;
    }
   }
};

void remdupfromarr(node* head){
    node* temp=head;
    while(temp->next!=NULL){
    if(temp->val==temp->next->val){
        node* ptr=temp->next;
        temp->next=temp->next->next;
        free(ptr);
    }
     else{
        temp=temp->next;
     }}
}

//printing link list in reverse order
void printrev(node* head){ //1
    if(head==NULL)    //2
    return;                //3
    printrev(head->next);//4
    cout<<head->val<<"\t";//5

}

//riversing linkage of the list

void revers(node* &head){
    node* prev=NULL;
    node* curr=head;
    node* Next;

    while(curr!=NULL){
        Next=curr->next;  //element ka address change nahi karta linking ko change karta hai
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    head=prev;
}

void disaddandval(node* head){//display adderss and value
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"/"<<temp<<"\t";
        temp=temp->next;
    }
}

node* reversrec(node* &head){//reverse by recursion
    //base case
    if(head==NULL||head->next==NULL)
    return head;

    //recursive case
    node* new_head=reversrec(head->next);

    head->next->next=head;
    head->next=NULL;
    return new_head;
}

//reversing k element of a link list 
node* reversekll(node* head,int k){
    int count=0;
    node* prev=NULL;
    node* curr=head;
    
    while(curr!=NULL&&count<k){
        node* Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
        count++;

    }
    
    if(curr!=NULL){
    node* new_head=reversekll(curr,k);
    head->next = new_head;
    }

    return prev;
}



int main(){
    linklist ll;
    ll.insertatend(1);
    ll.insertatend(2);
    ll.insertatend(3);
    ll.insertatend(4);
    ll.insertatend(5);
    ll.insertatend(6);
    ll.insertatend(7);
    ll.insertatend(8);
    ll.insertatend(9);

    disaddandval(ll.head);
    cout<<endl;

    ll.head=reversekll(ll.head, 3);

    disaddandval(ll.head);
}