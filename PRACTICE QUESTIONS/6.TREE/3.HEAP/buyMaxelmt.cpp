/*                                               Maximize Toys

Given an array arr[ ] of length N consisting cost of N toys and an integer K depicting the amount with you. Your task is to find maximum number of toys you can buy with K amount.

Example 1:

Input:
N = 7
K = 50
arr[] = {1, 12, 5, 111, 200, 1000, 10}
Output: 4
Explaination: The costs of the toys
you can buy are 1, 12, 5 and 10.*/

class Solution
{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            pq.push(arr[i]);
        }

        while (!pq.empty())
        {
            if (K - pq.top() >= 0)
            {
                K = K - pq.top();
                pq.pop();

                res++;
            }
            else
            {
                break;
            }
        }
        return res;
    }
};