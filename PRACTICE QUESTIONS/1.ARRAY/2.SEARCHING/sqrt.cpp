
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        long int low = 0;
        long int high = x;
        int res;
        while (low <= high)
        {
            long int mid = (low + high) / 2;
            long int mySrt = mid * mid;

            if (mySrt == x)
                return mid;

            else if (mySrt > x)
                high = mid - 1;

            else
            {
                low = mid + 1;
                res = mid;
            }
        }
        return res;
    }
};
