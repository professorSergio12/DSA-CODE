/*                        Egg Dropping Puzzle         */

#include <bits/stdc++.h>
using namespace std;

int eggDrop(int e, int f)
{
    if (f == 0 || f == 1)
    {
        return f;
    }

    if (e == 1)
    {
        return f;
    }

    int mini = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int temp = 1 + max(eggDrop(e - 1, k - 1), eggDrop(e, f - k)); // here we use maximum because  we asked to take worse case scenerio
        mini = min(mini, temp);                                       // here  we use minimum because we need to find minimum attempts
    }
    return mini;
}

int main()
{
    int e = 2, k = 10;
    cout << "Minimum number of trials in worst case with " << e << " eggs and " << k << " floors is " << eggDrop(e, k) << endl;
    return 0;
}