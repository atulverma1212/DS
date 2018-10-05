#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    node *next;
};

class Stack
{
    node *head;
    node *createNode(int item);
    void insertAtBottom(int item);
public:
    Stack() { head=NULL; }
    void push(int item);
    int pop();
    int top();
    void rev();
    bool isEmpty() { return (head==NULL)? true:false; }
    void disp()
    {
        node *temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout << endl;

    }
};

void Stack :: rev()
{
    if(isEmpty()) return;
    int data = pop();
    rev();
    insertAtBottom(data);
}

node* Stack :: createNode(int item)
{
    node *temp = new node();
    temp->data = item;
    temp->next = NULL;
    return temp;
}

void Stack :: push(int item)
{
    node *temp = createNode(item);
    if(head==NULL)
        head=temp;
    else{
        temp->next = head;
        head = temp;
    }
}

int Stack :: pop()
{
    if(isEmpty()) return -1;
    int data = head->data;
    node *temp=head;
    if(head->next)
        head=head->next;
    else
        head=NULL;
    free(temp);
    return data;
}

void Stack :: insertAtBottom(int item)
{
    node *newNode = createNode(item);
    if(head==NULL){
        head=newNode;
    } else {
        node *temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=newNode;
    }
}

int Stack :: top()
{
    if(isEmpty()) return -1;
    return head->data;
}

int main()
{
    Stack arr;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.disp();
    arr.rev();
    arr.disp();
}

