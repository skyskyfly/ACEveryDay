#include <iostream>
#include <algorithm>
#include   <cstring>
#include    <cstdio>
using namespace std;
const int maxn=1010;
int v[maxn],w[maxn];
int f[maxn];
int N,V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&V);
		for(int i=1;i<=N;i++)
			scanf("%d",&v[i]);
		for(int i=1;i<=N;i++)
			scanf("%d",&w[i]);
		memset(f,0,sizeof(f));
		for(int i=1;i<=N;i++)
			for(int j=V;j>=w[i];j--)
				f[j]=max(f[j],f[j-w[i]]+v[i]);
		  printf("%d\n",f[V]);
	}
	return 0;
}
