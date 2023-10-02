

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    else
    {
        return GCD(b, a % b);
    }
}