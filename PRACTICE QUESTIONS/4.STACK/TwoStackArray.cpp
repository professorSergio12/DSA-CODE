/*   Your task is to implement  2 stacks in one array efficiently.
Example 1:

Input:
push1(2)
push1(3)
push2(4)
pop1()
pop2()
pop2()

Output:
3 4 -1
*/
#include <bits/stdc++.h>
using namespace std;

class TwoStack
{
    int size;
    int *arr;
    int top1, top2;

public:
    TwoStack(int n = 100)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
    }

    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        return -1;
    }

    int pop2()
    {
        if (top2 < size)
        {
            int x = arr[top2];
            top2--;
            return x;
        }
        return -1;
    }
};

int main()
{
    TwoStack ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is: " << ts.pop1() << endl;
    ts.push2(40);
    cout << "Popped element from stack2 is: " << ts.pop2() << endl;
    return 0;
}