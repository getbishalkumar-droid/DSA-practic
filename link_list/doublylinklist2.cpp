#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node* prev;
    
    node(int v){
        val=v;
        next=NULL;
        prev=NULL;
    }
};
class doublylinklist{
    public:
    node* head;
    node* tail;
    doublylinklist(){
        head=NULL;
        tail=NULL;
    }
    void insertatend(int val){
        node* new_node=new node(val);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        return;
    }
    void displayfromstart(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        return;
    }
    
};
//create a function for reversing a doubly link list
    void reverse(node* &head,node* &tail){
        if(head==NULL||head->next==NULL){
            return;
        }
        node* curr=head;
        while(curr!=NULL){
            node* Next=curr->next;
            curr->next=curr->prev;
            curr->prev=Next;
            curr=Next;
        }
        node* new_head=tail;
        tail=head;
        head=new_head;
        return;
    }
//create a function for checking pallindrom
bool ispallindrom(node* head,node* tail){
    node* p1=head;
    node* p2=tail;
    while((p1!=p2)&&(p1->prev!=p2)){
        if(p1->val!=p2->val){
            return false;
        }
        p1=p1->next;
        p2=p2->prev;
    }
    return true;
}
//create a function for deleting same neighbour nodes
void deletesameneighbournodes (node* tail){
    node* curr=tail->prev;
    while(curr->prev!=NULL){
        if(curr->prev->val==curr->next->val){
            node* temp=curr;
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            curr=curr->prev;
            free(temp);
        }
        else
        curr=curr->prev;
    }
}
//create a function for checking cp
bool iscp(node* ptr){
    if(ptr->prev->val<ptr->val&&ptr->next->val<ptr->val){
        return true;
    }
    if(ptr->prev->val>ptr->val&&ptr->next->val>ptr->val){
        return true;
    }
    return false;
}
//create a function for finding minimum distance and maximum distance between two critical points
vector<int> minmaxdisbwcp(node* head,node* tail){
    node* curr=tail->prev;
    vector<int> ans(2,100000);
    int firstcp=-1;
    int lastcp=-1;
    int pos=0;
    if(curr==NULL){
        ans[0]=ans[1]=-1;
    }
    else{
    while(curr->prev!=NULL){
        if(iscp(curr)){
            if(firstcp==-1){
               firstcp=lastcp=pos;//ans[0] for min dis and ans[1] for max dis
            }
            else{
               ans[0]=min(ans[0],pos-lastcp);
               ans[1]=pos-firstcp;
               lastcp=pos;
            }
            
        }
        curr=curr->prev;
        pos++;
    }
  }
  if(ans[0]==100000){
    ans[0]=ans[1]=-1;
  }
  return ans;
}
//create a function for returning valuse which sum equals to target sum
vector<int> targersum(node* head,node* tail,int target){
    node* stptr=head;
    node* endptr=tail;
    vector<int> ans(2,-1);
    while(stptr!=endptr&&stptr->prev!=endptr){
        int sum=stptr->val+endptr->val;
        if(sum==target){
            ans[0]=stptr->val;
            ans[1]=endptr->val;
            return ans;
        }
        else if(sum<target){
            stptr=stptr->next;
        }
        else{
            endptr=endptr->prev;
        }
    }
    return ans;
}  
int main(){
  doublylinklist dll;
  dll.insertatend(2);
  
  dll.insertatend(5);
  
  dll.insertatend(8);
  
  dll.insertatend(6);//cp
  
  dll.insertatend(10);//cp
  
//   dll.insertatend(6);//cp

//   dll.insertatend(7);

  dll.displayfromstart();
  cout<<endl;

  cout<<"************************************************************"<<endl;
 vector<int> ans=targersum(dll.head,dll.tail,8);
 cout<<ans[0]<<" "<<ans[1];
}