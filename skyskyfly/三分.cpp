//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-31-21.36
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<iostream>
#include<algorithm>
#define MAXN 1000010
#define LL long long
using namespace std;
double D, H, h;
double cal(double x)
{
    return D-x+H-(H-h)*D/x;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf%lf%lf", &H, &h, &D);
        double left=(H-h)*D/H, right=D, mid, midmid;
        while(left+1e-9<=right)
        {
            mid=(left+right)/2;
            midmid=(mid+right)/2;
            if(cal(mid)>=cal(midmid))
                right=midmid;
            else
                left=mid;
        }
        printf("%.3lf\n", cal(mid));
    }
    return 0;
}
