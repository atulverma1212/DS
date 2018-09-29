#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    node *next;
};

class Node
{
    node *head;
public:
    Node() { head=NULL; }
    node *create(int d)
    {
        node *temp = new node();
        temp->data = d;
        temp->next = NULL;
        return temp;
    }
    void insert_begin(int d)
    {
        node *r = create(d);
        node *temp = head;
        if(head==NULL)
        {
            head=r;
            head->next = head;
        }
        else
        {
            while(temp->next!=head)
                temp=temp->next;
            temp->next = r;
            r->next = head;
            head=r;
        }
    }
    void insert_end(int d)
    {
        node *r = create(d);
        node *temp = head;
        if(head==NULL)
        {
            head=r;
            head->next = head;
        }
        else
        {
            while(temp->next!=head)
                temp=temp->next;
            temp->next = r;
            r->next = head;
        }
    }
    void delete_end()
    {
        node *r = head;
        while(r->next->next!=head)
            r=r->next;
        node *temp = r->next;
        r->next = head;
        free(temp);
    }
    void reverse()
    {
        if(head==NULL)
            return;
        node *prev = head;
        node *current = head->next;
        node *next = NULL;
        while(current!=head)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current=next;
        }
        current->next = prev;
        head=prev;
    }
    void display()
    {
        node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp!=head);
        cout<< endl << endl;
    }
    void del(int j)
    {
        if(j==0)
        {
            node *temp = head;
            node *r = head;
            while(r->next!=head)
                r=r->next;
            r->next = head->next;
            head = head->next;
            free(temp);
        }
        else
        {
            node *temp = NULL;
            node *r = head;
            int i=0;
            while(i++<j-1)
                r=r->next;
            temp = r->next;
            r->next = temp->next;
            free(temp);
        }
    }
    void delete_by_value(int j)
    {
        node *temp = head;
        int flag=1;
        if(head->data == j)
           {
               flag=0;
               del(0);
           }
        else
        {
            while(temp->next!=head)
            {
                if(temp->next->data == j)
                {
                    node *r = temp->next;
                    temp->next = r->next;
                    free(r);
                    flag=0;
                }
                else
                    temp=temp->next;
            }

        }
        if(flag)
            cout << "Element not found\n";
    }
};

int main()
{
    Node arr;
    int n=1,j,k;
    while(n!=-1)
    {
        cout << "1. Insert in beginning \n2. Insert in end \n3. Delete at nth position \n4. Delete by value \n5. Delete from end \n6. Reverse the list \n7. Display \n>>Enter your choice: ";
        cin >> n;
        switch(n)
        {
        case 1:
            cin >> j;
            for(int i=0;i<j;i++)
            {
                cin >> k;
                arr.insert_begin(k);
            }
            break;
        case 2:
            cin >> j;
            for(int i=0;i<j;i++)
            {
                cin >> k;
                arr.insert_end(k);
            }
            break;
        case 3:
            cin >> j;
            arr.del(j);
            break;
        case 4:
            cin >> j;
            arr.delete_by_value(j);
            break;
        case 5:
            arr.delete_end();
            break;
        case 6:
            arr.reverse();
            break;
        case 7:
            arr.display();
            break;
        }

    }
}

