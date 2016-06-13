#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=27;
int indegree[maxn],ans[maxn],graph[maxn][maxn];
int n,m;
int topsort()
{
    int flag=0;
    int in[maxn];
    int j=0;
    memcpy(in,indegree,sizeof(indegree));
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(in[i]==0) q.push(i);//将入度为0的点放入队列
    }
    while(!q.empty())
    {
        if(q.size()>1)  flag=1;
        int t=q.front();
        q.pop();//记得弹出
        ans[j++]=t;
        for(int i=0;i<n;i++)
        {
            if(graph[t][i])
            {
                in[i]--;
                if(in[i]==0) q.push(i);
            }
        }
    }
    if(j!=n)//不能拓扑排序 ,存在环
        return 1;
    else if(flag==1) return 2;
    else return 0;
}
int main()
{
    char s[5];
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        int incon=0,detmin=0;
        memset(graph,0,sizeof(graph));
        memset(indegree,0,sizeof(indegree));
        for(int i=1;i<=m;i++)
        {
            scanf("%s",s);
            if(detmin||incon) continue;
            int a=s[0]-'A';
            int b=s[2]-'A';
            if(graph[a][b]==0)
            {
                graph[a][b]=1;
                indegree[b]++;
            }
            int res=topsort();
            if(res==0)
            {
                detmin=1;
                printf("Sorted sequence determined after %d relations: ",i);
                for(int i=0;i<n;i++)
                printf("%c",ans[i]+'A');
                printf(".\n");
            }
            if(res==1)
            {
                incon=1;
                printf("Inconsistency found after %d relations.\n",i);
            }
        }
        if(!incon&&!detmin) printf("Sorted sequence cannot be determined.\n");
    }

}
