 #include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *next;

    node(int v)
    {
        val = v;
        next = NULL;
    }
};

class linklist
{
public:
    node *head;

   
    linklist()
    {
        head = NULL;
    }

    void insertattail(int val)
    {
        node *new_node = new node(val);
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
};
//create a function to murg two shorted link list such that the resultent list is also shorted
node* merg(node* head1,node* head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* dummynode=new node(-1);
    node* ptr3=dummynode;
    while(ptr1&&ptr2){
        if(ptr1->val < ptr2->val){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;

    }
    if(ptr1){
        ptr3->next=ptr1;
    }
    if(ptr2){
        ptr3->next=ptr2;
    }
    return dummynode->next;
}

//create a function for finding the mid element of a link list without traversing the array twice

void findmid(node* head){
    node* p1=head;
    node* p2=head;
    
    while(p2->next&&p2->next->next){
        p1=p1->next;
        p2=p2->next->next;
        
    }
    if(p2->next==NULL){
        cout<<p1->val;
    }
    if(p2->next->next==NULL){
        cout<<p1->val<<" "<<p1->next->val; 
    }
}
//create a function for detecting a circular loop in link list
int findloping(node* head){
    node* p1=head;
    node* p2=head;
    while(p2&&p2->next){
       p1=p1->next;
       p2=p2->next->next;

       if(p1==p2)
       return 1;
    }
    return -1;
}

//create a function for remove lopping in link list
int removeloping(node* head){
    node* p1=head;
    node* p2=head;
    while(p2&&p2->next){
       p1=p1->next;
       p2=p2->next->next;

       if(p1==p2){
        p2=head;
        while(p1->next!=p2->next){
            p1=p1->next;
            p2=p2->next;
        }
        p2->next=NULL;
       }
     
    }
    return -1;
}
//create a function for checking a link list is pallindrom or not
bool ispalindrom(node* head){
    //1.find middle element
    node* p1=head;
    node* p2=head;
    while(p2&&p2->next){
        p1=p1->next;
        p2=p2->next->next;
    }
    // 2.break link list and reverse it
    node* prev=p1;
    node* curr=p1->next;
    p1->next=NULL;
    while(curr){
        node* Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    // 3.comp element
    node* head1=head;
    node* head2=prev;
    while(head2&&head1){
        if(head1->val!=head2->val)
        return false;
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}
//create a function for rotating the link list k times
void rotateKtimes(node* &head,int k){
    // 1.find length of link list&last node 
    node* temp=head;
    int len=0;
    while(temp->next){
        temp=temp->next;
        len++;
    }
    temp->next=head;
    // 2.break link list into n-k%n length from starting
    node* ptr=head;
    for(int i=0;i<len-k%len;i++){
        ptr=ptr->next;
    }
    head=ptr->next;
    ptr->next=NULL;
}
//create a function in which ood index element is connected with even index element
void oddeven(node* head){
    node* p1=head;
    node* p2=head->next;
    node* temp=head->next;
    while(p1&&(p2&&p2->next)){
       p1->next=p1->next->next;//time complexity is bigo of n
       p2->next=p2->next->next;
       p1=p1->next;
       p2=p2->next;
    }
    p1->next=temp;

    
}
//create a function in which 1st ele is connected with last element and last ele is connected with 2nd ele and 2nd
//ele is connected with 2nd last ele
void changelink(node* head){
    //1.reverse the link list from last to mid
    node* p1=head;
    node* p2=head;
    while(p2&&p2->next){
        p1=p1->next;
        p2=p2->next->next;
    }
    node* prev=p1;
    node* curr=p1->next;
    p1->next=NULL;
    while(curr){
        node* Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    //2.create loop for chenge linkage
    node* head1=head;
    node* head2=prev;
    while(head2->next){
       node* h1next=head1->next;
       node* h2next=head2->next;
       head1->next=head2;
       head1=h1next;
       head2->next=head1;
       head2=h2next;
    }
}
//create a recursive function for changing linkage of two ele
node* change2link(node* head){
    //create link change function for two element
     node* prev=NULL;
     node* curr=head;
     int count=0;
     while(curr!=NULL&&count<2){
        node* Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
        count++;
     }
     //agar jyda element hai to function ko batao thumara kaam khatam nahi hua hai
     if(curr!=NULL){
      node* new_head=change2link(curr);
      head->next=new_head;   
     }
     return prev;
}
//Method 2
node* Change2link(node* head){
    node* first_node=head;
    node* second_node=head->next;
    //base case
if(first_node==NULL||first_node->next==NULL){
    return first_node;
}
    //recursive function
    first_node->next=Change2link(second_node->next);
    second_node->next=first_node;
    return second_node;
}
//**********************************************MAIN BODY***********************************************************************
int main(){
    linklist ll1;
    linklist ll2;
    linklist ll3;
    ll1.insertattail(1);
    ll1.insertattail(2);
    ll1.insertattail(3);
    ll1.insertattail(4);
    ll1.insertattail(5);

    
    
   ll1.display();
   ll1.head=change2link(ll1.head);
   cout<<endl;
   ll1.display();
    
    
}