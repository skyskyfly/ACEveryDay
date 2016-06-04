#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int maxn=105;
char ma[maxn][maxn];
int f[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
int m,n;
int cnt,flag;
void dfs(int x,int y)
{
    if(!flag)
    flag=1,cnt++;
    ma[x][y]='*';
    for(int i=0;i<8;i++)
    {
        int a=x+f[i][0];
        int b=y+f[i][1];
        if(ma[a][b]=='@')
            dfs(a,b);
    }
}
int main()
{
    while(cin>>m>>n&&(m||n))
    {
        cnt=0;
        int i,j;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
            cin>>ma[i][j];
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                flag=0;
                if(ma[i][j]=='@')
                    dfs(i,j);
            }
        }
        cout<<cnt<<endl;
    }
}
