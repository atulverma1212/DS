/*
In this challenge, you must first implement a queue using two stacks. Then process  queries, where each query is one of the following  types:

1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.

*/

#include <iostream>
using namespace std;

int arr[200000],str[200000];
int atop=-1,stop=-1;

void apush(int n) { arr[++atop]=n; }
void spush(int n) { str[++stop]=n; }
int apop() { return arr[atop--]; }
int spop() { return str[stop--]; }

void push(int n)
{
    apush(n);
}

void pop(int p)
{
    if(stop==-1)
  {  while(atop>-1)
    {
        spush(apop());
    }}
    if(p==2)
   { int temp = spop();
   }
    else if(p==3)
        cout << str[stop] << endl;

}



int main() {
    int n;
    cin >> n;
    int p,q,r;
    while(n--)
    {
        cin >> p;
        switch(p)
        {
            case 1:
                cin >> q;
                push(q);
                break;
            default:
                pop(p);
                break;
        }
    }
    return 0;
}
