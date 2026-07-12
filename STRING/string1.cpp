#include<iostream>
#include<string>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    string s="my name is bishal kumar mahato";
    cout<<s<<"\n";

    //getline function
    string s1;
    cout <<"enter your full name";
    getline(cin,s1);
    cout<<s1<<"\n";

    //index of an element
    cout<<s[0]<<"\n";

    /*inbuild function
    reverse()
    time complexity o(length of string)*/
     
    string s2="bishal";
    reverse (s2.begin(),s2.end());
    reverse (s2.begin(),s2.end());
    cout<<s2<<endl;
    
    /*substring function
    syntax stringname.substr(starting index,length)*/
     
    cout<<s2.substr(1,4)<<endl;

    //adding two string
    string first_name="bishal";
    string last_name="mahato";
    cout<<first_name+" "+last_name<<"\n";

    //adding two charector array
    char S1[20]="BISHAL ";
    char S2[20]="KUMAR";
    strcat(S1,S2);
    cout<<S1<<endl;

    //adding charector at the end of the string
    string my_name="bisha";
    my_name.push_back('l');
    cout<<my_name<<endl;
    
    //stringname.size() use to calculate length of string class o(1)
    //stringname.length() used to calculate cherector array(string) length o(length)

    //to string function
    int a=42;
    string str=to_string(a);
    str.push_back('3');
     cout<<str<<endl;

}
