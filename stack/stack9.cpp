//NEXT GREATER ELEMENT
//input :- [4,3,9,1,6,8,2]  output:-[9,9,-1,6,8,-1,-1]
//NEXT SMALLER ELEMENT :-decreasing walo ka sidha answer aa jyega incrising wale stack mai store ho jyenge
//PREV GREATER AND PREV SMALLER ELEMENT :- (int i=arr.size();i>0;i--) ka use karo

// ************************************************************************************************************

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nge(vector<int> arr){
    vector<int> output(arr.size(),-1);
    stack<int> stk;
    for(int i=0;i<arr.size();i++){
       while(!stk.empty()&& arr[i]>arr[stk.top()]){
        output[stk.top()]=arr[i];
        stk.pop();
       }
       stk.push(i);
    }

    while(!stk.empty()){
       output[stk.top()]=-1;
       stk.pop();
    }
    return output;
}

int main(){
    vector<int> arr={4,6,3,1,0,9,5,6,7,3};
    vector<int> output=nge(arr);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
}