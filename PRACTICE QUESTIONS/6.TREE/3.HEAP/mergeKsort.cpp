/*                           Merge k sorted arrays 

1. Create a min Heap and insert the first element of all the K arrays.
2. Run a loop until the size of MinHeap is greater than zero.
    +)Remove the top element of the MinHeap and print the element.
    +)Now insert the next element from the same array in which the removed element belonged.
    +)If the array doesn't have any more elements, then replace root with infinite. After replacing the root, heapify  the tree.
3. Return the output array

*/

#include <bits/stdc++.h>
using namespace std;

struct Triplet
{
    int val, aPos, vPos;

    Triplet(int v, int aP, int vP)
    {
        val = v;
        aPos = aP;
        vPos = vP;
    }
};

struct Mycmp
{
    bool operator(Triplet &t1, Triplet &t2)
    {
        return t1.val > t2.val;
    }
};

// Time Complexity: O(N * K * log K), Insertion and deletion in a Min Heap requires log K time.
// Auxiliary Space: O(K), If Output is not stored then the only space required is the Min-Heap of K elements.
vector<int> mergeArr(vector<int> &arr)
{
    vector<int> ans;
    priority_queue<Triplet, vector<Triplet>, Mycmp> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        Triplet t(arr[i][0], i, 0);
        pq.push(t);
    }

    while (!pq.empty())
    {
        Triplet curr = pq.top();
        pq.pop();
        ans.push_back(curr.val);

        int ap = curr.aPos;
        int vp = curr.vPos;

        if (vp + 1 < arr[ap][vp + 1].size())
        {
            Triplet t(arr[ap][vp + 1], ap, vp + 1);
            pq.push(t);
        }
    }

    return ans;
}

int main()
{
}