#include <bits/stdc++.h>
using namespace std;

/*                                        NAIVE APPROACH                                   */
// TIME COMPLEXITY:- O(N^2)
// SPACE COMPLEXITY:-O(1)
int StockBuySell(int price[], int start, int end)
{
    if (end <= start)
        return 0;

    int profit = 0;
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (price[j] > price[i])
            {
                int curr_prft = price[j] - price[i] + StockBuySell(price, start, i - 1) + StockBuySell(price, j + 1, end);
                profit = max(profit, curr_prft);
            }
        }
    }
    return profit;
}

/*                                        EFFICIENT APPROACH                                   */
// TIME COMPLEXITY:- O(N)
// SPACE COMPLEXITY:-O(1)
int StockBuySell(int price[], int start, int end)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (price[i] > price[i - 1])
        {
            profit += (price[i] - price[i - 1]);
        }
    }
    return profit;
}

int main()
{
    int arr[] = {30, 10, 8, 2};
    int n = 4;

    cout << StockBuySell(arr, 0, n - 1);

    return 0;
}
