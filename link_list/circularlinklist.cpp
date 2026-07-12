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
class circularll
{
public:
    node *head;
    circularll()
    {
        head = NULL;
    }
    // create a function for inserting a element at start
    void insertatstart(int val)
    {
        node *new_node = new node(val);
        if (head == NULL)
        {
            head = new_node;
            head->next = new_node;
        }
        else
        {
            node *temp = head;
            do
            {
                temp = temp->next;
            } while (temp->next != head);
            new_node->next = head;
            head = new_node;
            temp->next = head;
        }
    }
    // create a function for displaying element
    void display()
    {
        if(head==NULL){
            cout<<"no element in cll";
            return;
        }
        node *temp = head;
        do
        {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);
    }
    // create a function for inserting at tail
    void insertatend(int val)
    {
        node *new_node = new node(val);
        if (head == NULL)
        {
            head = new_node;
            head->next = new_node;
        }
        else
        {
            node *temp = head;
            do
            {
                temp = temp->next;
            } while (temp->next != head);
            temp->next = new_node;
            new_node->next = head;
        }
    }
    // create a function for inserting at kth position
    void insertatkpos(int val, int pos)
    {
        if (pos == 1)
        {
            insertatstart(val);
        }
        else
        {
            node *new_node = new node(val);
            node *temp = head;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
 // create a function for deleting head
    void delhead()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next == head)
        {
            node *temp = head;
            head = NULL;
            free(temp);
        }
        else
        {
            node *ptr = head;
            node *temp = head;

            do
            {
                temp = temp->next;
            } while (temp->next != head);

            head = head->next;
            temp->next = head;
            free(ptr);
        }
    }
//create a function for deleting tail
void deletetail(){
    if(head==NULL){
        return;
    }
    node* temp=head;
    while(temp->next->next!=head){
        temp=temp->next;
    }
    node* ptr=temp->next;
    temp->next=head;
    free(ptr);
}    
};

int main()
{
    circularll cll;
    cll.insertatend(1);
    cout << cll.head << endl;
    cll.insertatend(2);
    cout << cll.head << endl;
    cll.insertatend(3);
    cout << cll.head << endl;
    cll.insertatend(4);
    cout << cll.head << endl;
    cll.insertatend(5);
    cout << cll.head << endl;
    cll.insertatend(6);
    cout << cll.head << endl;
    cll.insertatkpos(9, 5);
   
    cll.display();
    cout<<endl;
    cll.delhead();
    cll.deletetail();
    cll.display();
    cout<<endl;
}