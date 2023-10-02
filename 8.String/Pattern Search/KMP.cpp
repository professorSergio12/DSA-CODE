/*                       KMP Algorithm for Pattern Searching
 */

#include <bits/stdc++.h>
using namespace std;

void LPS(char *pat, int m, int *lps)
{
    lps[0] = 0;
    int len = 0;
    int i = 1;

    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

void KMPSearch(char *pat, char *txt)
{
    int n = strlen(txt);
    int m = strlen(pat);

    int lps[m];
    int i = 0, j = 0;
    LPS(pat, m, lps);

    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }

        else if (i < n && pat[j] != txt[i])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
}

int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}