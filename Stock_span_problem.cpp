#include<iostream>
using namespace std;

int arr[10];
int top=-1;

int arr1[10]={0};
int atop=-1;

void apush()
{
    atop++;
    arr1[atop]=1;
}

void inc(int d) { arr1[atop]+=d; }

int apop() { int d = arr1[atop]; atop--; return d; }

void push(int d)
{
    top++;
    arr[top] = d;
}

void clear() { for(int i=0;i<=atop;i++) cout << arr1[i] << " "; cout << endl; }

int pop() { int d = arr[top]; top--; return d; }

int main()
{
    int ans[7] = {0};
    int str[7] = {100, 80, 60, 70, 60, 75, 85};
    int j=1;
    for(int i=0;i<7;i++)
    {
        if(top==-1)
        {
            push(str[i]);
            apush();
        }
        else  if(arr[top]<=str[i])
            {
                apush();
                while(arr[top]<=str[i])
                {
                    int d = pop();
                    inc(apop());
                }
                push(str[i]);
            }
            else
            {
                push(str[i]);
                apush();
            }

            cout << arr1[top] << " ";
    }
}
