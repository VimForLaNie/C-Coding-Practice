#include <bits/stdc++.h>
#define il inline
#define int long long
#define N 100
using namespace std;

signed main()
{
    int i, j, input, zero_i = 0, sum;
    int n, m, k, cnt[N], ans = 0;
    memset(cnt,0,sizeof(cnt));
    scanf("%lld%lld%lld", &n, &m, &k);
    for (i = 1; i <= n; i++)
    {
        scanf("%lld", &input);
        if (!input)//if input == 0
        {
            for (j = 1; j < i - zero_i; j++)//loop sub-array '0' [1,1,1,...] '0' ...*end*
                cnt[j] += i - zero_i - j; //count how many '1' in the sub-array,sub-sub-array...
            zero_i = i; //move index to recent 0 | aka curr_position
        }
    }
    for (j = 1; j <= n - zero_i; j++)//loop remaining '1' | '0' [1,1,1,...] *end*
        cnt[j] += n - zero_i - j + 1;//count how many '1' in the sub-array,sub-sub-array... +1 to offset to '1'
    for (i = 1, zero_i = sum = 0; i <= m; i++)
    {
        scanf("%lld", &input);
        if (!input)//if input == 0
            zero_i = i, sum = 0; //reset sum & move '0''s index
        //if exceed
        else if(i - zero_i <= k &&  // if dist(zero_i,i) not exceed the area | width not exceed width_max (m)
                k % (i - zero_i) == 0 &&  // if dist(zero_i,i) divide area perfectly | height is int (not fraction)
                k / (i - zero_i) <= n)//if dist(zero_i,i) divide area not exceed n | height not exceed height_max (n)
            sum += cnt[k / (i - zero_i)];//num_1 in the sub-array.size[height] | sum += width
        ans += sum;
    }
    printf("%lld", ans);

    return 0;
}