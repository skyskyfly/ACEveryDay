#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
const int maxn=35;
#define eps 1e-8
const int inf=0xfffffff;
const double pi=acos(-1.0);
struct nod
{
    int x;
    int y;
};
nod point[maxn];
int n;
double cul(double a)
{
    double minx=inf,maxx=-inf;
    double miny=inf,maxy=-inf;
    for(int i=0;i<n;i++)
    {
        double xx=point[i].x*cos(a)+point[i].y*sin(a);
        double yy=point[i].y*cos(a)-point[i].x*sin(a);
        minx=min(minx,xx),maxx=max(maxx,xx);
        miny=min(miny,yy),maxy=max(maxy,yy);
    }
    return max(maxx-minx,maxy-miny);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&point[i].x,&point[i].y);
        double l=0.0,r=pi;
        double ans;
        while(l+eps<=r)
        {
            double mid=(l+r)/2;
            double mmid=(mid+r)/2;
            double t1=cul(mid),t2=cul(mmid);
            if(t1<=t2) r=mmid;
            else l=mid;
        }
        printf("%.2lf\n",cul(l)*cul(l));
    }
    return 0;
}
