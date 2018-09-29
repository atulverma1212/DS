#include<iostream>
using namespace std;

#define MAX 10
int arr[MAX];
int rear=-1,front=-1;

void insert(int d)
{
    if(rear == MAX-1)
        cout << "Queue Overflow \n";
    else if(front == -1 && rear == -1)
        front = rear = 0;
    else
        rear++;
    arr[rear] = d;
}

int pop()
{
    if(front == -1 || front == rear)
    {
        cout << "Queue Underflow \n";
        return -1;
    }
    else
    {
        int d = arr[front++];
        if(front>rear)
            front=rear=0;
        return d;
    }
}

int peek()
{
    if(front == -1 || front>rear)
    {
        cout << "Empty Queue \n";
        return -1;
    }
    else
        return arr[front];
}

int main()
{
    int n=1,j,k;
    while(n!=-1)
    {
        cout << "1. Insert Element \n2. Pop element \n3. Peek \n4. Display Queue \n>>Enter a number: ";
        cin >> n;
        switch(n)
        {
        case 1:
            cout << "Enter number of elements: ";
            cin >> j;
            for(int i=0;i<j;i++)
            {
                cin >> k;
                insert(k);
            }
            break;
        case 2:
            cout << pop() << endl << endl;
            break;
        case 3:
            cout << "Peek: " << peek() << endl << endl;
            break;
        case 4:
            for(int i=front;i<=rear;i++)
                cout << arr[i] << " ";
            cout << endl;
            break;
        }
    }
}

