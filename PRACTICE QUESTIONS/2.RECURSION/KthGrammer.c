/*In the problem, we build a table of n rows (1-indexed). We start by using writing zero within the 1st row. Now in every subsequent row, we observe the preceding row and replace each occurrence of zero with 01, and every incidence of one with 10.
As an example,for n = 4,the 1st row is 0,the second row is 01,the 3rd row is 0110,and the 4th row is 01101001.
we will take n and k as input and return K-th symbol in nth row of table.*/

#include <stdio.h>
#include <math.h>

int kthGrammar(int n, int k)
{
    if (n == 1 && k == 1)
    {
        return 0;
    }

    else
    {
        int mid = pow(2, n - 1) / 2;
        if (k <= mid)
        {
            return kthGrammar(n - 1, k);
        }
        else
        {
            return !kthGrammar(n - 1, k - mid);
        }
    }
}

int main()
{
    int n = 4;
    int k = 5;
    printf("The output is %d ", kthGrammar(n, k));
}
