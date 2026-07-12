/*
  Given an array of integer height representing the histogram's bar height where
  the width of each bar is 1,return the area of largest histogram
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// create function

int maxArea(vector<int> input)
{
  vector<int> maxarea(input.size());
  stack<int> stk;
  int max=-100000;
  stk.push(-1);
  for (int i = 0; i < input.size(); i++)
  {
    while (stk.size()>1 && input[i] < input[stk.top()])
    {
      int curr = stk.top();
      stk.pop();
      maxarea[curr] = (i - stk.top() - 1) * input[curr];
    }
    stk.push(i);
  }

  while(stk.size()>1){
    int curr = stk.top();
    stk.pop();
    maxarea[curr]=(input.size()-stk.top()-1)*input[curr];
  }
   for(int i=0;i<maxarea.size();i++){
       if(max<maxarea[i]){
        max=maxarea[i];
       }
   }
  return max;
}

int main(){
  vector<int> arr={2,1,5,6,2,3,0,2,1,5,6,2,3};
  cout<<maxArea(arr);
}