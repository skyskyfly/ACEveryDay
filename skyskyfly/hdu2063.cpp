#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[200000];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int sum,y,k,m;
        scanf("%d%d",&sum,&y);
        int n;
        int wei[10000],val[10000],i,j;
        scanf("%d",&n);
        for(i = 0; i<n; i++)
        {
            scanf("%d%d",&wei[i],&val[i]);
            wei[i]/=1000;
        }
        m = sum;
        for(k = 0; k<y; k++)
        {
            m = sum;
            m/=1000;
            memset(dp,0,sizeof(dp));
            for(i = 0; i<n; i++)
            {
                for(j = wei[i]; j<=m; j++)
                {
                    dp[j] = max(dp[j],dp[j-wei[i]]+val[i]);
                }
            }
            sum+=dp[m];
        }
        printf("%d\n",sum);
    }

    return 0;
}
