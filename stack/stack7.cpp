#include<iostream>
#include<stack>
using namespace std;

//create a function for inserting at any index of stack

void insertAtEnd(stack<int> &st,int data){
    stack<int> temp;
    
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    st.push(data);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}

//create a function for reverse a current stack
// iterative solution****************************************************************************
/*
  time complexity o(n);
  space complexity o(n)
*/
 
void reverse(stack<int> &st){
    stack<int> temp1;
    stack<int> temp2;

    while(!st.empty()){
        temp1.push(st.top());
        st.pop();
    }
     while(!temp1.empty()){
        temp2.push(temp1.top());
        temp1.pop();
    }
     while(!temp2.empty()){
        st.push(temp2.top());
        temp2.pop();
    }
}

//recursive solution**************************************************************************
/*
   time complexity = o(n*n)
   space complexity = o(n)
*/

void Reverse(stack<int> &st){
    if(st.size()==1){
       return;
    }else{
        int curr=st.top();
        st.pop();
        reverse(st);
        insertAtEnd(st,curr);

    }
}


int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);//top

    Reverse(st);
    reverse(st);


    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}