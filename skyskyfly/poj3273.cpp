#include <iostream>
#include<algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
const int maxn=100000+100;
int a[maxn];
int n,k;
bool check(__int64 x)
{
    int t=0;
    __int64 sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>x)
        {
            sum=a[i];
            t++;
        }
    }
    if(t+1>k) return false;
    else return true;
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        __int64 sum=0;
        int ma=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(ma<a[i])ma=a[i];
            sum+=a[i];
        }
        __int64 l=ma,r=sum;
        __int64 ans;
        while(l<=r)
        {
            __int64 mid=(l+r)>>1;
            if(check(mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
