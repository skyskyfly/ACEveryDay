#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
const int maxn=100000+100;
int a[maxn];
int n,k;
bool check(int t)
{
    int sum=0;
    if(k==1&&a[n-1]>t) return false;
    for(int i=0;i<n;i++)
    {
            if(a[i]<=t) continue;
            else
            {
            int b=(a[i]-t+k-2)/(k-1);
            sum+=b;
            if(sum>t) return false;
            }
    }
    return true;
}
int main()
{
    int ans;
   while(scanf("%d",&n)!=EOF)
   {
       for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
       sort(a,a+n);
       scanf("%d",&k);
       int l=1,r=a[n-1];
       while(l<=r)
       {
           int mid=(l+r)/2;
           if(check(mid)) ans=mid,r=mid-1;
           else l=mid+1;
       }
       printf("%d\n",ans);
   }
}
