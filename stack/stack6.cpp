#include<iostream>
#include<stack>
using namespace std;

//create a function for deleting from any index
void Delete(stack<int> &st,int idx){
   stack<int> temp;
   int n=st.size()-idx;
   for(int i=1;i<n;i++){
    temp.push(st.top());
    st.pop();
   }
   st.pop();

   while(!temp.empty()){
    st.push(temp.top());
    temp.pop();
   }
}



int main(){
    stack<int> st;
    st.push(1);
    st.push(2);//del
    st.push(3);
    st.push(4);//top

    Delete(st,1);

    while(!st.empty()){
       cout<<st.top()<<endl;
       st.pop();
    }
}