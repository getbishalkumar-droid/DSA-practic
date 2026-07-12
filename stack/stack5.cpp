#include<iostream>
#include<stack>
using namespace std;

//create a function for inserting at any index of stack

void insert(stack<char> &st,int pos,char data){
    stack<char> temp;
    int num=st.size()-pos;
    for(int i=0;i<num;i++){
        temp.push(st.top());
        st.pop();
    }
    st.push(data);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}

//create a function for inserting at any index of stack recursive solution

void Insert(stack<char> &st,int pos,char data){
    int count=0;
    int n=st.size()-pos;
    //base case
    if(count>=n){
        st.push(data);
    }else{
        char curr=st.top();
        st.pop();
        count++;
        Insert(st,pos,data);
        st.push(curr);
    }
}


int main(){
    stack<char> st;
    
    st.push('l');
    st.push('a');
    st.push('h');
    st.push('i');
    st.push('B');

    cout<<st.size()<<endl;

    Insert(st,3,'s');

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}