/**/

#include <bits/stdc++.h>
using namespace std;

int permutationCoeff(int n, int k)
{
    int dp[n + 1];
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = i * dp[i - 1];
    }
    int ans = dp[n] / dp[n - k];
    return ans;
}


//A O(n) time and O(1) Extra Space Solution 
int permutation(int n, int k)
{
    int ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans = ans * (n - i);
    }
    return ans;
}

int main()
{
    int n = 10, k = 2;
    printf("Value of P(%d, %d) is %d ", n, k, permutationCoeff(n, k));
    printf("Value of P(%d, %d) is %d ", n, k, permutation(n, k));
    return 0;
}