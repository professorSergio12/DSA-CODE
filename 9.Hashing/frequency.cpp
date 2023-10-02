#include <bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(N)
void frequency(int arr[], int size)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
        mp[arr[i]]++;
    }
    for (auto x : mp)
    {
        cout << "frequency of " << x.first << " is: " << x.second << endl;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    frequency(arr, size);
    return 0;
}