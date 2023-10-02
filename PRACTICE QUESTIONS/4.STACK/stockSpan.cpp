/*                                               The Stock Span Problem
The stock span problem is a financial problem where we have a series of N daily price quotes for a stock and we need to calculate the span of the stock's price for all N days. The span Si of the stock's price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than its price on the given day.

Examples:-
Input: N = 7, price[] = [100 80 60 70 60 75 85]
Output: 1 1 1 2 1 4 6
Explanation: Traversing the given input span for 100 will be 1, 80 is smaller than 100 so the span is 1, 60 is smaller than 80 so the span is 1, 70 is greater than 60 so the span is 2 and so on. Hence the output will be 1 1 1 2 1 4 6.

*/

#include <bits/stdc++.h>
using namespace std;

// NAIVE APPROACH

// Time complexity:- O(n^2)
void stockSpan(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int span = 1;
        for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--)
        {
            span++;
        }
        cout << span << " ";
    }
}

int main()
{
    int arr[] = {18, 12, 13, 14, 11, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    stockSpan(arr, n);
}
