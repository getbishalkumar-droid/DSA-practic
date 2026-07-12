//STOCK SPAN
/*
   Given a series of n daily price quotes for a stock, we need to calculate the span 
   of the stock's price for all N days. the span of the stock's price in one day is the
   maximum number of consecutive days (starting from that day and going backward)
   for which the stock price was less then or equal to the price of that day. 

   
*/

#include<iostream>
#include<stack>
#include<vector>
#include <algorithm>
using namespace std;

//create a function

vector<int> calSpan(vector<int> input){
    vector<int> output(input.size(),-1);
    stack<int> stack;
    for(int i=input.size()-1;i>=0;i--){
        while(!stack.empty()&&input[i]>input[stack.top()]){
            output[stack.top()]=stack.top()-i;
            stack.pop();
        }
        stack.push(i);
    }
    while(!stack.empty()){
        output[stack.top()]=stack.top()+1;
        stack.pop();
    }
    return output;

}

int main(){
    vector<int> stockprise={100,80,60,70,60,75,85};
    vector<int> span=calSpan(stockprise);
    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
}