/*                              find duplicate in an array of N+1 Integers                                                  */

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[slow]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
    
    vector<int> nums = { 1, 2, 3, 4, 3 };
 
    cout << "The duplicate element is " << findDuplicate(nums);


    return 0;
}