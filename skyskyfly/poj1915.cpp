/*
简单BFS，寻找最短路径长度
*/
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
int m[305][305];//用来标记，避免重复，bfs常见剪枝
int ax,ay,bx,by;
struct nod
{
    int x,y;
    int step;
};
int f[8][2]={{-2,1},{-2,-1},{-1,2},{-1,-2},{1,2},{1,-2},{2,1},{2,-1}};
queue<nod> q;
int ans;
int l;
void  bfs()
{
    nod t;
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t.x==bx&&t.y==by)
        {
            ans=t.step;
           return;
        }
        for(int i=0;i<8;i++)
        {
            int xx=t.x+f[i][0];
            int yy=t.y+f[i][1];
            nod n;
            n.x=xx,n.y=yy,n.step=t.step+1;
            if(xx>=0&&xx<l&&yy>=0&&yy<l&&m[n.x][n.y]==0)
            {q.push(n);m[n.x][n.y]=1;}//在放入队列时就要标记，而不是吧每一次对队列头部进行标记，我又sb了
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&l);
        memset(m,0,sizeof(m));
        scanf("%d%d%d%d",&ax,&ay,&bx,&by);
        nod k;
        k.x=ax,k.y=ay,k.step=0;
        q.push(k);
        m[ax][ay]=1;
        bfs();
        cout<<ans<<endl;
        while(!q.empty())
        q.pop();//对于有多组数据情况，一定要记得清空队列
    }
    return 0;
}
