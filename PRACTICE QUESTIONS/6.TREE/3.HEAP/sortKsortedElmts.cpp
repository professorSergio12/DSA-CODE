/*                                      Sort a nearly sorted (or K sorted) array

Given an array of N elements, where each element is at most K away from its target position, devise an algorithm that sorts in O(N log K) time.

Examples: 

Input: arr[] = {6, 5, 3, 2, 8, 10, 9}, K = 3 
Output: arr[] = {2, 3, 5, 6, 8, 9, 10}

Input: arr[] = {10, 9, 8, 7, 4, 70, 60, 50}, k = 4
Output: arr[] = {4, 7, 8, 9, 10, 50, 60, 70}*/

#include<bits/stdc++.h>
using namespace std;

void sortNearlySortedArray(int arr[], int n, int k)
{
    priority_queue<int,  vector<int>, greater<int>>pq;

    for(int i = 0; i <= k; i++)
    {
        pq.push(arr[i]);
    }

    int index = 0 ;
    for(int i = k + 1; i < n; i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while(!pq.empty())
    {
        arr[index++] = pq.top();
        pq.pop();
    }
    
    for(int i=0; i< n; i++)
        cout<<arr[i]<<" ";
    
}

int main()
{
    int A[] = {2, 6, 3, 12, 56, 8};
    int size = 6;
    int k = 3;
    sortNearlySortedArray(A, size, k); 
}


