#include<iostream>
#include<stack>
using namespace std;

//create a function for inserting a element at the bottom of the stack iterative solution
/*
  time complexity=o(n)
  space complexity=o(n)
*/


void insertAtBottom(stack<int> &st,int x){
    stack<int> temp;
    while(!st.empty()){
        int curr=st.top();
        temp.push(curr);
        st.pop();
    }

    st.push(x);

    while(!temp.empty()){
        int curr=temp.top();
        st.push(curr);
        temp.pop();
    }
}

//create a function for inserting a element at the bottom of the stack recursive solution

/*
  time complexity=o(n)
  space complexity=o(n)
*/


void insertatbottom(stack<int> &st,int x){
    //base case
    if(st.empty()){
        st.push(x);
        return;
    }else{
        int curr=st.top();
        st.pop();
        insertatbottom(st,x);
        st.push(curr);
    }
}


int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    insertatbottom(st,100);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}
