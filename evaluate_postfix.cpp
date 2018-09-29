#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    float data;
    node *next;
};

class stack
{
    node *head;
    int len;
public:
    stack() { len=0; head=NULL;}
    void push(float data)
    {
        node *temp = new node();
        temp->data = data;
        temp->next = head;
        head = temp;
        len++;
    }
    float pop()
    {
        if(len==0)
            return -1;
        float data = head->data;
        node *temp = head;
        head=head->next;
        free(temp);
        len--;
        return data;
    }
    int get() { return len; }
};

int main()
{
    stack arr;
    string str;
    cin >> str;
    char temp;
    float l,r;
    int i=0;
    int flag = 1;
    while(i<str.length())
    {
        temp = str[i];
        if(isdigit(temp))
            arr.push((float)(temp-'0'));
        else
        {
            if(arr.get()<=1)
            {
                cout <<"Invalid Expression\n";
                flag = 0;
                break;
            }
            r = arr.pop();
            l = arr.pop();
            switch(temp)
            {
                case '/':
                    l/=r;
                    break;
                case '*':
                    l*=r;
                    break;
                case '-':
                    l-=r;
                    break;
                case '+':
                    l+=r;
                    break;
                case '%':
                    l = (int)l % (int)r;
                    break;
            }
            arr.push(l);
        }
        i++;
    }
    if(flag)
    cout << arr.pop();
}
