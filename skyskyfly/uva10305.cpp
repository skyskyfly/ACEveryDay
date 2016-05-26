#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int maxn=110;
vector<int> tp[maxn];//用来储存依赖关系
int b[maxn];//储存依赖度
queue<int> q,ans;//q队列用来储存入度为0的元素，ans队列用来储存顺序
int m,n;
int main()
{
    int x,y;
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
            tp[i].clear();//初始化！！！
        for(int i=0;i<m;i++)
        {

            scanf("%d%d",&x,&y);
            tp[x].push_back(y);//记录依赖关系。
            b[y]++;//记录y元素依赖度
        }
         for(int i=1;i<=n;i++)
            if(!b[i]) q.push(i);//将入度为0的元素压入队列
         while(!q.empty())//开始剪边
         {
             int t=q.front();
            ans.push(t);
            q.pop();
            for(int i=0;i<tp[t].size();i++)
            {
              b[tp[t][i]]--;//依赖度--；
              if(b[tp[t][i]]==0)//入度为0
              q.push(tp[t][i]);
            }
         }
         while(!ans.empty())
         {
             if(ans.size()>1) printf("%d ",ans.front());
             else printf("%d\n",ans.front());
             ans.pop();
         }
    }
    return 0;
}
