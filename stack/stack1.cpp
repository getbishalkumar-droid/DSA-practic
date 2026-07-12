#include<iostream>
using namespace std;
class stack{
    int capacity;
    int* arr;
    int top;
    public:
    stack(int c){
       this->capacity=c;
       arr=new int[c];
       this->top=-1;
    }
//create a function for inserting a element at top
void push(int val){
    if(this->top==this->capacity-1){
        cout<<"overflow\n";
        return;
    }
    top++;
    this->arr[this->top]=val;
}
// create a function for deleting element from top
int pop(){
    if(this->top==-1){
       cout<<"underflow\n";
       return -100000;
    }
    this->top--;
}
// create a function for accessing the top element
int getTop(){
    if(this->top==-1){
       cout<<"underflow\n";
       return -100000;
    }
    return this->arr[this->top];
}
//create a function for checking the stack is empty or not
bool isempty(){
    if(this->top==-1){
        return true;
    }
    else{
        return false;
    }
}
//create a function for returning the size of stack
int size(){
    return this->top+1;
}
//create a function for checking the stack is full or not
bool isfull(){
    return this->top==this->capacity-1;
}
};
int main(){
    stack st(10);
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    cout<<st.getTop()<<endl;
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    st.push(10);
    st.push(11);
    cout<<st.isempty()<<endl;
    cout<<st.isfull()<<endl;
    st.push(12);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    
}