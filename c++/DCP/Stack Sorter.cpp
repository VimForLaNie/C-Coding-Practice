#include <bits/stdc++.h>
using namespace std;

void StackSort(stack<int> s)
{
    stack<int> temp;
    // temp.push(s.top());
    // s.pop();
    int mark_top;
    temp.push(0);
    int recent_temp = 0;
    while (!s.empty())
    {
        mark_top = s.top();
        if (mark_top >= recent_temp)
        {
            while (temp.top() != recent_temp)
            {
                s.push(temp.top());
                temp.pop();
            }
            temp.push(mark_top);
            recent_temp = mark_top;
            while (s.top() != mark_top)
            {
                temp.push(s.top());
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (temp.top() != recent_temp)
            {
                s.push(temp.top());
                temp.pop();
            }
            s.push(recent_temp);
            temp.pop();
            temp.push(mark_top);
            recent_temp = mark_top;
            while (s.top() != mark_top)
            {
                temp.push(s.top());
                s.pop();
            }
            s.pop();
        }
    }
    s.swap(temp);
}

int main()
{
    int size, x;
    stack<int> s;
    scanf("%d", &size);
    for (size_t i = 0; i < size; i++)
    {
        s.push(rand() % 14717);
    }
    StackSort(s);
    for (size_t i = 0; i < size; i++)
    {
        x = s.top();
        printf("%d\t", x);
        s.pop();
    }
}