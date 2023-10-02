/*      Given a sorted array and a sum , find if there is a pair with a given sum
 */

#include <bits/stdc++.h>
using namespace std;

bool isPair(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        if (arr[left] + arr[right] == x)
            return true;

        else if (arr[left] + arr[right] > x)
            right--;

        else
            left++;
    }
    return false;
}

/*      Given a sorted array and a sum , find if there is a triplet with a given sum
*/

bool isPair(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        if (arr[left] + arr[right] == x)
            return true;

        else if (arr[left] + arr[right] > x)
            right--;

        else
            left++;
    }
    return false;
}



int main()
{
}
