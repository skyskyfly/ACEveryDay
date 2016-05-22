#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=50000+100;
__int64 a[maxn];
int n,m;
bool check(__int64 x)
{
    int t=0;
    int i;
    __int64 len;
    __int64 now=a[0],next;
    __int64 sum=0;
    for(i=n;i>=0;i--)
    {
        if(a[n+1]-a[i]<x) t++;
        else break;
    }
    int h=i;
    for(i=1;i<=h;i++)
    {
       next=a[i];
       len=next-now;
       if(len<x)
       {
           t++;
           if(t>m) return false;
       }
      else now=a[i];
    }
    return true;
}
int main()
{
    __int64 L;
    while(scanf("%I64d%d%d",&L,&n,&m)!=EOF)
    {
        a[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        a[n+1]=L;
        sort(a,a+n+2);
        __int64 l=0,r=L;
        __int64 ans=0;
        while(l<=r)
        {
            __int64 mid=(l+r)>>1;
            //cout<<mid<<endl;
            if(check(mid)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        //cout<<check(4)<<endl;
        printf("%I64d\n",ans);
    }
    return 0;
}
