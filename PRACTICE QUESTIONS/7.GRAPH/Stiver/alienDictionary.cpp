/*                                  Alien Dictionary

Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.


Example 1:

Input:
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is
'b', 'd', 'a', 'c' Note that words are sorted
and in the given language "baa" comes before
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int src, vector<vector<int>> &g, vector<int> &visited, string &ans)
    {
        visited[src] = 1;

        for (auto x : g[src])
        {
            if (!visited[x])
            {
                dfs(x, g, visited, ans);
            }
        }
        char ch = src + 'a';
        ans = ch + ans;
    }

    string findOrder(string dict[], int n, int k)
    {
        vector<vector<int>> g(k);

        for (int i = 0; i < n - 1; i++)
        {
            string w1 = dict[i];
            string w2 = dict[i + 1];

            for (int j = 0; j < min(w1.length(), w2.length()); j++)
            {
                if (w1[j] != w2[j])
                {
                    g[w1[j] - 'a'].push_back(w2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> visited(k, 0);
        string ans = "";

        for (int i = 0; i < k; i++)
        {
            if (!visited[i])
            {
                dfs(i, g, visited, ans);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// topological sort
vector<int> topoSort(int V, vector<int> adj[])
{
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        // node is in your topo sort
        // so please remove it from the indegree

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return topo;
}

string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        for (int ptr = 0; ptr < len; ptr++)
        {
            if (s1[ptr] != s2[ptr])
            {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(K, adj);
    string ans = "";
    for (auto it : topo)
    {
        ans = ans + char(it + 'a');
    }
    return ans;
}

int main()
{

    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    Solution obj;
    string ans = obj.findOrder(dict, N, K);

    for (auto ch : ans)
        cout << ch << ' ';
    cout << endl;

    return 0;
}

/*
when the order is not possible 
For example: 

dict = {abcd","abc"}

If everything is matching then it doesn't matter, if we are following aline dict or not. But shorter string should have been before the longer string

Cyclic dependency :- Not possible
*/

