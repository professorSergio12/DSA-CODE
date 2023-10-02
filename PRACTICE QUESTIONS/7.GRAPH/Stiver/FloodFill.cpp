/*                                 Flood Fill
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> &image, int newColor, int x, int y, int oldcolor)
    {
        if (i < 0 || j < 0 || i >= x || j >= y)
            return;

        if (visited[i][j] || image[i][j] != oldcolor)
            return;

        visited[i][j] = 1;
        image[i][j] = newColor;
        dfs(i + 1, j, visited, image, newColor, x, y, oldcolor);
        dfs(i - 1, j, visited, image, newColor, x, y, oldcolor);
        dfs(i, j + 1, visited, image, newColor, x, y, oldcolor);
        dfs(i, j - 1, visited, image, newColor, x, y, oldcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int x = image.size();
        int y = image[0].size();
        vector<vector<int>> visited(x, vector<int>(y, 0));
        int oldcolor = image[sr][sc];
        dfs(sr, sc, visited, image, newColor, x, y, oldcolor);
        return image;
    }
};