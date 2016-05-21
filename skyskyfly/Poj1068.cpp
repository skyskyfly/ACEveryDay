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
#include <cmath>
#define LL long long
using namespace std;
const int maxn=10000+100;
const double pi=acos(-1.0);
double a[maxn];
int b[maxn];
int n,k;
__int64 sum;
bool check(int x)
{
    if(x==0) return true;
    if(sum<k) return false;
    int t=0;
   for(int i=0;i<n;i++)
   {
      int m=b[i];
      while(m>=x)
      {
          m-=x;
          t++;
      }
      if(t>=k) return true;
   }
   return  false;
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&a[i]);
            b[i]=(a[i]+0.005)*100;//将单位化为整数厘米
            sum+=b[i];
        }
        sort(b,b+n);
        int l=0,r=b[n-1];
        int  ans=0;
        while(l<=r)
        {
          int  mid=(l+r)/2;
          if(check(mid))  ans=mid,l=mid+1;
          else r=mid-1;
        }
         printf("%.2lf\n",ans*0.01);
    }
    return 0;
}
