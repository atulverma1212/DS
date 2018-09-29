#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    node *prev;
    int data;
    node *next;
};

class Node
{
    node *head,*tail;
public:
    Node() { head=tail=NULL; }
    node *create(int d)
    {
        node *temp = new node();
        temp->data = d;
        temp->next = temp->prev = NULL;
        return temp;
    }
    void insert_begin(int d)
    {
        node *newnode = create(d);
        node *temp = head;
        if(head==NULL && tail==NULL)
            tail=head = newnode;
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    void insert_end(int d)
    {
        node *temp = create(d);
        if(tail==NULL && head==NULL)
            head=tail=temp;
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    void del(int n)
    {
        if(n==0)
        {
            node *r = head;
            head = head->next;
            head->prev=NULL;
            free(r);
        }
        else
        {
            node *temp = head;
            int i= 0;
            while(i++<n-1 && temp!=NULL)
                    temp=temp->next;
            node *r = temp->next;
            temp->next = r->next;
            r->next->prev = temp;
            free(r);
        }
    }
    void delete_end()
    {
        node *r = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(r);
    }
    void delete_by_value(int j)
    {
        if(head->data == j)
        {
            node *r = head;
            head = head->next;
            head->prev = NULL;
            free(r);
        }
        node *temp = head;
        while(temp->next!=NULL)
        {
            if(temp->next->data == j)
            {
                node *r = temp->next;
                temp->next = r->next;
                r->next->prev = temp;
                free(r);
            }
            else
            temp=temp->next;
        }
        if(temp->next==NULL)
            cout << "Element not found\n";
    }
    void display()
    {
        node *temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout << endl;
    }
    void reverse()
    {
        node *prev = NULL;
        node *current = head;
        node *next = head->next;;
        while(current->next!=NULL)
        {
            next = current->next;
            current->next = prev;
            current->prev = next;
            if(prev==NULL)
                tail = current;
            prev = current;
            current = next;
        }
        head = current;
        head->next = prev;
        head->prev =NULL;
    }
    void display_reverse()
    {
        node *temp = tail;
        while(temp!=NULL)
        {
            cout << tail->data << " ";
            tail = tail->prev;
        }
        cout << endl;
    }
};

int main()
{
    Node arr;
    int n=1,j,k;
    while(n!=-1)
    {
        cout << "1. Insert in beginning \n2. Insert in end \n3. Delete at nth position \n4. Delete by value: \n5. Delete from end \n6. Reverse the list \n7. Display \n8. Display Reverse \n>>Enter your choice: ";
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
        case 8:
            arr.display_reverse();
            break;
        }

    }
}
