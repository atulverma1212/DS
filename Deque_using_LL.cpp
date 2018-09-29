#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    node *next;
};

class DQ
{
    node *head,*tail;
public:
    DQ() { head=tail=NULL; }
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
        if(head==NULL && tail==NULL)
            head = tail = newnode;
        else
        {
            tail->next=newnode;
            tail=tail->next;
        }
    }
    void insertfront()
    {
        node *newnode = createnode();
        if(head==NULL && tail==NULL)
            head = tail = newnode;
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    void disp()
    {
        node *temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    int pop_back()
    {
        if(tail==NULL)
        {
            cout << "Underflow\n"; return -1;
        }
        node *temp=head;
        int ret;
        if(tail == head->next)
        {
            ret = tail->data;
            tail = head;
            return ret;
        }
        if(tail==head)
        {
            ret = tail->data;
            tail = head = NULL;
            return ret;
        }
        while(temp->next!=NULL && temp->next->next!=NULL)
            temp=temp->next;
        ret = temp->next->data;
        free(temp->next);
        temp->next=NULL;
        tail=temp;
        return ret;
    }
    int pop_front()
    {
        if(head==NULL)
        {
            cout << "Underflow\n"; return -1;
        }
        node *temp=head;
        int ret = head->data;
        head=head->next;
        free(temp);
        return ret;
    }
    int back() { return tail->data; }
    int front() { return head->data; }
};

int main()
{
    DQ deq;
    int n=1,p;
    do
    {
        cout << "\n1. Push Front \n2. Push Back \n3. Pop front \n4. Pop back \n5. Front \n6. Back \n7. Display \nEnter choice: ";
        cin >> n;
        switch(n)
        {
        case 1:
            deq.insertfront();
            break;
        case 2:
            deq.insertnode();
            break;
        case 3:
            cout << deq.pop_front() << endl;
            break;
        case 4:
            cout << deq.pop_back() << endl;
            break;
        case 5:
            cout << deq.front() << endl;
            break;
        case 6:
            cout << deq.back() << endl;
            break;
        case 7:
            deq.disp();
            break;
        }
    }while(n>0);
}


