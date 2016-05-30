#include <iostream>
#include <cstdio>
#include  <cstring>
#include  <algorithm>
using namespace std;
const int maxn=70000;
int a[maxn];
int x,y;
struct nod
{
    int mi;
    int ma;
};
nod tree[4*maxn];
void build(int p,int l,int r)
{
    if(l==r) {tree[p].mi=a[l];tree[p].ma=a[l];return;}
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);
    tree[p].mi=min(tree[p<<1].mi,tree[(p<<1)+1].mi);
    tree[p].ma=max(tree[p<<1].ma,tree[(p<<1)+1].ma);
}
int find1(int p,int l,int r,int x,int y)
{
    if(x<=l&&r<=y) {return tree[p].ma;}
    int mid=(l+r)>>1;
    if(y<=mid) return find1(p<<1,l,mid,x,y);
    else if(x>mid) return find1((p<<1)+1,mid+1,r,x,y);
    else return max(find1(p<<1,l,mid,x,mid),find1((p<<1)+1,mid+1,r,mid+1,y));
}
int find2(int p,int l,int r,int x,int y)
{
    if(x<=l&&r<=y) {return tree[p].mi;}
    int mid=(l+r)>>1;
    if(y<=mid) return find2(p<<1,l,mid,x,y);
    else if(x>mid) return find2((p<<1)+1,mid+1,r,x,y);
    else return min(find2(p<<1,l,mid,x,mid),find2((p<<1)+1,mid+1,r,mid+1,y));
}
int main()
{
    int n,q;
    int x,y;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        build(1,1,n);
        while(q--)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",find1(1,1,n,x,y)-find2(1,1,n,x,y));
        }
    }
    return 0;
}
