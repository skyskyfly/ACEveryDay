/*
 hdu1258
dfs，小数据，dfs暴力搜一遍即可，之前一直做一些图的题目，这算是做的
第一道比较抽象的dfs题目，dfs最重要的思想是递归与回溯来实现状态的转移，是
一种暴力的搜索手段，适用于小数据的情况
*/
#include<iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
const int maxn=15;
const double epi=1e-8;
const double pi=acos(-1.0);
int a[maxn],b[maxn];
bool v[maxn];//标记数组，避免在一次搜索中重复搜索
int tar,n;
bool flag;
void dfs(int sum,int pos,int ans)//三个参数,sum代表当前层计数总和，判断递归是否结束的标志，pos储存下一次从哪一个位置开始搜索
{
    int i;
    if(sum>tar) return;
    if(sum==tar)
    {
        flag=true;
        for(int i=1;i<=ans;i++)
      printf((i==ans)?"%d\n":"%d+",b[i]);//输出注意格式
    }
    int last=-1;
    for(i=pos+1;i<=n;i++)
    {
        if(!v[i]&&a[i]!=last)
        {
            b[ans+1]=a[i];
            last=a[i];
            v[i]=true;
            dfs(sum+a[i],i,ans+1);
            v[i]=false;
        }
    }
}
int main()
{
    while(scanf("%d%d",&tar,&n)&&(tar||n))
    {
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        memset(v,false,sizeof(v));
        cout<<"Sums of "<<tar<<":"<<endl;
        flag=false;//判断是否找到答案
        dfs(0,0,0);
        if(!flag)
            cout<<"NONE"<<endl;
    }
}
