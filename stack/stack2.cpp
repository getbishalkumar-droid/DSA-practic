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

class stack{
    node* head;
    int capacity;
    int currsize;
    public:
    stack(int c){
        capacity=c;
        head=NULL;
        currsize=0;
    }

    bool isempty(){
        return head==NULL;
    }

    bool isfull(){
        return currsize==capacity;
    }

    void push(int val){
        if(currsize==capacity){
            cout<<"overflow"<<endl;
            return;
        }
        node* new_node=new node(val);
        new_node->next=head;
        head=new_node;
        currsize++;
    }

    int pop(){
        if(head==NULL){
            cout<<"underflow"<<endl;
            return -100000;
        }
        node* temp=head;
        head=head->next;
        int val=temp->val;
        free(temp);
        currsize--;
        return val;
        
    }

    int size(){
        return currsize;
    }

    int gettop(){
        return head->val;
    }
    
};
int main(){
    stack st(10);
    cout<<st.isempty()<<endl;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.pop()<<endl;
    cout<<st.size()<<endl;
    // st.push(4);
    // st.push(5);
    // st.push(6);
    // st.push(7);
    // st.push(8);
    // st.push(9);
    // st.push(10);
    // st.push(11);
    // cout<<st.isempty()<<endl;
    // cout<<st.isfull()<<endl;
    // st.push(12);
    // st.pop();
    // st.pop();
    // st.pop();
    // cout<<st.gettop()<<endl;
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // cout<<st.isempty()<<endl;
    // cout<<st.isfull()<<endl;

}