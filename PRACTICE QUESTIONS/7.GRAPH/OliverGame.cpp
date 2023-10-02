/*                              Oliver and the Game

Problem
Oliver and Bob are best friends. They have spent their entire childhood in the beautiful city of Byteland. The people of Byteland live happily along with the King.
The city has a unique architecture with total N houses. The King's Mansion is a very big and beautiful bungalow having address = 1. Rest of the houses in Byteland have some unique address, (say A), are connected by roads and there is always a unique path between any two houses in the city. Note that the King's Mansion is also included in these houses.

Oliver and Bob have decided to play Hide and Seek taking the entire city as their arena. In the given scenario of the game, it's Oliver's turn to hide and Bob is supposed to find him.
Oliver can hide in any of the houses in the city including the King's Mansion. As Bob is a very lazy person, for finding Oliver, he either goes towards the King's Mansion (he stops when he reaches there), or he moves away from the Mansion in any possible path till the last house on that path.

Oliver runs and hides in some house (say X) and Bob is starting the game from his house (say Y). If Bob reaches house X, then he surely finds Oliver.

Given Q queries, you need to tell Bob if it is possible for him to find Oliver or not.

The queries can be of the following two types:
0 X Y : Bob moves towards the King's Mansion.
1 X Y : Bob moves away from the King's Mansion

INPUT :
The first line of the input contains a single integer N, total number of houses in the city. Next N-1 lines contain two space separated integers A and B denoting a road between the houses at address A and B.
Next line contains a single integer Q denoting the number of queries.
Following Q lines contain three space separated integers representing each query as explained above.

OUTPUT :
Print "YES" or "NO" for each query depending on the answer to that query.

CONSTRAINTS :
1 ≤ N ≤ 10^5
1 ≤ A,B ≤ N
1 ≤ Q ≤ 5*10^5
1 ≤ X,Y ≤ N

NOTE :
Large Input size. Use printf scanf or other fast I/O methods.

Sample Input
9
1 2
1 3
2 6
2 7
6 9
7 8
3 4
3 5

QUERY
5
                         Sample Output
0 2 8                        YES
1 2 8                        NO
1 6 5                        NO
0 6 5                        NO
1 9 1                        YES

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> inTime;
vector<int> outTime;
int timer = 1;

void resize(int n)
{
    inTime.resize(n + 1);
    outTime.resize(n + 1);
}

void dfs(int src, int par, vector<int> g[])
{
    inTime[src] = timer++;
    for (auto x : g[src])
    {
        if (x != par)
        {
            dfs(x, src, g);
        }
    }
    outTime[src] = timer++;
}

bool check(int x, int y)
{
    if (inTime[x] > inTime[y] and outTime[x] < outTime[y])
        return true;
    return false;
}

int32_t main()
{

    int n;
    cin >> n;
    timer = 1;
    resize(n);
    vector<int> g[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, g);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int type, x, y;
        cin >> type >> x >> y;
        if (!check(x, y) and !check(y, x))
        {
            cout << "NO\n";
            continue;
        }
        if (type == 0)
        {
            if (check(y, x))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if (type == 1)
        {
            if (check(x, y))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
