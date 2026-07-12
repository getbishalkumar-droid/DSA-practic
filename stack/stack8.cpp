//BALANCE BRACKET SEQUENCE

#include<iostream>
#include<stack>
using namespace std;
//create function for checking balance bracket sequence

bool isBalanced(string str){
    stack<char> stk;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch=='('||ch=='{'||ch=='['){
            stk.push(ch);
        }else{
            if(stk.empty()){
                return false;
            }else{
                if(ch==')'&&stk.top()=='(' || ch==']'&&stk.top()=='[' || ch=='}'&&stk.top()=='{'){
                    stk.pop();
                }else{
                    return false;
                }
            }
        }
    }
    return stk.empty();
}

int main(){

    cout<<isBalanced(")())");

}

