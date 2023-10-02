
#include <bits/stdc++.h>
using namespace std;

// NAIVE APPROACH
void nextGreater(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                cout << arr[j] << " ";
                break;
            }
        }
        if (j == n)
        {
            cout << -1 << " ";
        }
    }
}

// EFFICIENT APPROACH
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long int> s;
    vector<long long int> v(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }

        v[i] = (s.empty()) ? -1 : s.top();
        s.push(arr[i]);
    }
    return v;
}


// NEXT SMALLEST ELEMENT
vector<int> nextSmaller(vector<int> arr, int n)
{
    stack<int> s;
    vector<int> v(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] <= s.top())
        {
            s.pop();
        }

        v[i] = (s.empty()) ? -1 : s.top();
        s.push(arr[i]);
    }
    return v;
}

int main()
{
    vector<long long> arr = {5, 15, 10, 8, 6, 12, 9, 18};
    int n = 8;
    vector<long long> res = nextLargerElement(arr, n);
    for (long long i : res)
    {
        cout << i << " ";
    }

    printf("\n");
    vector<int> arr1 = {20, 30, 10, 5, 15};
    vector<int> ans = nextSmaller(arr1, n);
    for (long long i : ans)
    {
        cout << i << " ";
    }
}
