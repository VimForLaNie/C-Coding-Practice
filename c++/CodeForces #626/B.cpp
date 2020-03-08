#include <bits/stdc++.h>
using namespace std;

int main()
{
    short n, m;
    int k;
    cin >> n >> m >> k;
    int a[n];
    int b[m];
    int c[n][m];
    for (short i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (short i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (short i = 0; i < n; i++)
    {
        for (short j = 0; j < m; j++)
        {
            c[i][j] = a[i] * b[j];
        }
    }
    int cnt = 0;
    short r,col = 0;
    short i,j = 1;
    short x,y = 0;
    for ( r = 0; r < n; r++)
    {
        for ( col = 0; col < m; col++)
        {
            for ( i = 1; i <= n; i++)
            {
            up:
                for ( j = 1; j <= m; j++)
                {
                next:
                    if (i * j == k && r + i <= n && col + j <= m)
                    {
                        for ( x = r; x < r + i; x++)
                        {
                            for ( y = col; y < col + j; y++)
                            {
                                if (c[x][y] == 0)
                                {
                                    j++;
                                    if (j > m)
                                    {
                                        i++;
                                        if (i > n)
                                        {
                                            goto ans;
                                        }
                                        goto up;
                                    }
                                    goto next;
                                }
                            }
                        }
                        cnt++;
                    }
                }
            }
        }
    }

ans:
    cout << cnt << endl;
    return 0;
}