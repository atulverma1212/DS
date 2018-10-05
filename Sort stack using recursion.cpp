#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &arr, int elem)
{
    if(arr.empty() || elem < arr.top())
    {
        arr.push(elem);
        return;
    }
    int temp = arr.top();
    arr.pop();
    sortedInsert(arr, elem);
    arr.push(temp);
}

void sortStack(stack <int> &arr)
{
    if(!arr.empty())
    {
        int temp = arr.top();
        arr.pop();
        sortStack(arr);
        sortedInsert(arr, temp);
    }
}

int main()
{
    stack<int> arr;
    arr.push(30);
    arr.push(-1);
    arr.push(13);
    arr.push(10);
    arr.push(5);
    arr.push(15);
    arr.push(0);
    sortStack(arr);
    for(;!arr.empty();)
    {
        cout << arr.top() << endl;
        arr.pop();
    }
}
