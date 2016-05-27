include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
double x,y,l,w;
const double pi=acos(-1.0);
const double eps=1e-7;
double cal(double a)
{
   double k=x-l*sin(a)-w/cos(a);
   return -k/tan(a);
}
int main()
{
    while(scanf("%lf%lf%lf%lf",&x,&y,&l,&w)!=EOF)
    {
       double l=0.0,r=pi/2;
       if(x<=w|| y<=w) {printf("no\n");continue;}
       while(l+eps<=r)
       {
           double mid=(l+r)/2.0;
           double mmid=(mid+r)/2.0;
           if(cal(mid)<=cal(mmid)) l=mid;
           else r=mmid;
       }
       if(cal(r)<y) printf("yes\n");
       else printf("no\n");
    }
    return 0;
}
