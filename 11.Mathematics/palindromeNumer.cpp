
#include <bits/stdc++.h>
using namespace std;

// Time complexity:theta(d) where d is the number of digits
bool palindrome(int n)
{
    int res = 0;
    int temp = n;

    while (temp != 0)
    {
        int ld = temp % 10;
        res = res * 10 + ld;
        temp = temp / 10;
    }
    if (res == n)
        return true;

    return false;
}

int main()
{
    int x = 8668;
    if (palindrome(x) == true)
    {
        cout << "Yes, the number is in palindrome" << endl;
    }
    else
    {
        cout << "No, the number is not a palindrome" << endl;
    }
}