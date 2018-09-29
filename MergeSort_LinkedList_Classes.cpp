#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    node *next;
};

void split(node*, node**, node**);
node *mergeList(node *a,node *b);

void msort(node **head)
{
    if(*head==NULL || (*head)->next==NULL) return;
    node *temp=*head,*a,*b;
    split(temp,&a,&b);
    msort(&a);
    msort(&b);
    *head = mergeList(a,b);
}

void split(node *head,node **a,node **b)
{
    if(head==NULL) return;
     node *fast = head;
    node *slow = head;
    while(fast->next!=NULL)
    {
        fast=fast->next;
        if(fast->next!=NULL)
        {
            fast = fast->next;
            slow=slow->next;
        }
    }
    *a = head;
    *b = slow->next;
    slow->next=NULL;
}

node  *mergeList(node *a,node *b)
{
    node *temp = NULL;
    if(a==NULL) return b;
    if(b==NULL) return a;
    if(a->data < b->data)
    {
        temp = a;
        temp->next = mergeList(a->next,b);
    }
    else
    {
        temp = b;
        temp->next=mergeList(a,b->next);
    }
    return temp;
}




class Node
{
    node *head;
public:
    Node() { head=NULL; }
    node *createnode()
    {
        node *temp = new node();
        cin >> temp->data;
        temp->next = NULL;
        return temp;
    }
    void insertnode()
    {
        node *newnode= createnode();
        node *temp = head;
        if(head==NULL)
            head = newnode;
        else
        {
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next = newnode;
        }
    }

    void disp()
    {
        node *temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    node **get() { return &head; }

};




int main()
{
    Node arr;
    int n,d;
    cin >> n;
    for(int i=0;i<n;i++)
        arr.insertnode();
    node **head=arr.get();
    msort(&(*head));
    arr.disp();
}
