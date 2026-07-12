// Stanndered Templete Library list
#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l1={1,2,3,4};
    auto itr=l1.begin();
    cout<<*itr<<endl;
    advance(itr,2);
    cout<<*itr<<endl;

//traversol in a list
//using ranged for loop    
    for(auto num:l1){
        cout<<num<<" ";
    }cout<<endl;
//using iterators
for(auto itr=l1.begin();itr!=l1.end();itr++){
     cout<<*itr<<" ";
}cout<<endl;

//reverse triversel
for(auto itr=l1.rbegin();itr!=l1.rend();itr++){
    cout<<*itr<<" ";
}cout<<endl;

//insertion
auto ptr=l1.begin();
advance(ptr,2);
l1.insert(ptr,9);

for(auto itr=l1.begin();itr!=l1.end();itr++){
     cout<<*itr<<" ";
}cout<<endl;
}
