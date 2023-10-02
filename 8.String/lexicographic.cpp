

#include <bits/stdc++.h>
using namespace std;
#define a 256

int factorial(int n)
{
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int lax(char *st)
{
    int n = strlen(st);
    int res = 1;

    int mal = factorial(n);
    int count[a] = {0};

    for (int i = 0; i < n; i++)
    {
        count[st[i]]++;
    }

    for (int i = 1; i < a; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n - 1; i++)
    {
        mal = mal / (n - i);
        res = res + count[st[i] - 1] * mal;

        for (int j = st[i]; j < a; j++)
        {
            count[j]--;
        }
    }
    return res;
}

int main()
{
    char str[] = "string";
    cout << lax(str);

    return 0;
}
