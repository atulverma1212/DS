#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    int priority;
    node *next;
};

class p_queue
{
    node *head;
public:
    p_queue() { head=NULL; }
    node *create(int n,int p)
    {
        node *temp = new node();
        temp->data = n;
        temp->priority = p;
        temp->next = NULL;
        return temp;
    }
    void push(int j,int p)
    {
        node *newnode = create(j,p);
        if(head==NULL)
            head=newnode;
        else if(head->priority > p)
        {
            newnode->next = head;
            head=newnode;
        }
        else
        {
            node *temp = head;
            while(temp->next!=NULL && (temp->next)->priority <= p)
                temp=temp->next;
            newnode->next = temp->next;
            temp->next = newnode;
        }

    }
    int pop()
    {
        if(head==NULL)
        {
            cout << "Queue Underflow\n";
            return -1;
        }
        node *temp = head;
        head = head->next;
        int d = temp->data;
        free(temp);
        return d;
    }
    int peek()
    {
        if(head==NULL)
        {
            cout << "Queue Underflow\n";
            return -1;
        }
        return head->data;
    }
    void display()
    {
        node *temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};


int main()
{
    p_queue arr;
    int n=1,j,p,k;
    while(n!=-1)
    {
        cout << "1. Insert Element \n2. Pop \n3. Peek \n4. Display \n>>Enter a choice: ";
        cin >> n;
        switch(n)
        {
        case 1:
            cin >> j;
            for(int i=0;i<j;i++)
            {
                cin >> k >> p;
                arr.push(k,p);
            }
            break;
        case 2:
            cout << arr.pop() << endl;
            break;
        case 3:
            cout << arr.peek() << endl;
            break;
        case 4:
            arr.display();
            break;
        }
    }
}
