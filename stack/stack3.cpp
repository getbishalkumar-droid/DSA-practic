#include<iostream>
#include<stack>
using namespace std;
//create a function for copy one stack to another iterative solution
stack<int> copyStack(stack<int> &input){
    stack<int> temp;
    while(not input.empty()){
        int curr=input.top();
        input.pop();
        temp.push(curr);
    }
    stack<int> result;
    while(not temp.empty()){
        int curr=temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}
//create a function for copy one stack to another recursive solution
void fun(stack<int> &st,stack<int> &result){
    if(st.empty()){
        return;
    }
    int curr=st.top();
    st.pop();
    fun(st,result);
    result.push(curr);
}


int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    
    // stack<int> copy= copyStack(st);

    stack<int> copy;

    fun(st,copy);

    while(not copy.empty()){
        int curr=copy.top();
        copy.pop();
        cout<<curr<<endl;
    }
}