#include <stdio.h>
#include <algorithm>
using namespace std;

struct Bank
{
    int money;
    double p;
} bank[10005];

int main()
{
    int n,t;
    double p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%d",&p,&n);
        p = 1-p;
        int i,j,sum = 0;
        for(i = 0; i<n; i++)
        {
            scanf("%d%lf",&bank[i].money,&bank[i].p);
            bank[i].p = 1-bank[i].p;
            sum+=bank[i].money;
        }
        double dp[10005]= {1.0};
        for(i = 0; i<n; i++)
        {
            for(j = sum; j>=bank[i].money; j--)
            {
                dp[j] = max(dp[j],dp[j-bank[i].money]*bank[i].p);
            }
        }
        for(i = sum; i>=0; i--)
        {
            if(dp[i]-p>0.000000001)
            {
                printf("%d\n",i);
                break;
            }
        }
    }

    return 0;
}
