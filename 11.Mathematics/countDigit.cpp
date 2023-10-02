
#include <bits/stdc++.h>
using namespace std;

int Count(int x)
{
    int cnt = 0;

    while (x > 0)
    {
        x = x / 10;
        cnt++;
    }
    return cnt;
}

int main()
{
    int x = 9879;
    int ans = Count(x);
    cout << ans;
}