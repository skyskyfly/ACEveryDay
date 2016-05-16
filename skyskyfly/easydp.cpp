#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;
__int64 a[50];
int kase=0;
int main()
{
	a[0]=1,a[1]=2;
	for(int i=2;i<=45;i++)
        a[i]=a[i-1]+a[i-2];
    int T,n;
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        printf("Scenario #%d:\n",++kase);
        printf("%d\n",a[n]);
        if(T) cout<<endl;
    }
	return 0;
}
