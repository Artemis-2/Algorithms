#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct edges
{
	long 	int v1;
	long	int v2;
	long	int wt;
};
edges arr[100010];
long int kings[100010];
long int ranks[100010];
long long int len=0;
long long int sizes[100010];
bool comparator(edges x,edges y)
{
	if (y.wt-x.wt>0)
		return 1;
	else return 0;
}
long int find_parent(long int x)
{
	if(kings[x]==x)
		return x;
	else
		return find_parent(kings[x]);
}

bool getmst(edges x)
{
	long int a=find_parent(x.v1);
	long int b=find_parent(x.v2);
	//printf("%d	%d	%d\n",x.v1,x.v2,x.wt);
	if(a!=b)
	{
		len+=x.wt;
		if(ranks[a]>ranks[b])
		  {
		  kings[b]=kings[a];
					ranks[a]++;
		}
		else if(ranks[a]==ranks[b])
		{
		kings[b]=kings[a];
		ranks[a]++;

		}
		else
		{
		kings[a]=kings[b];
					ranks[b]++;
		}
	}
		
		else
			return 1;

	}

	int main(void)
	{
		long    int n,m;

		scanf("%ld%ld",&n,&m);
		long int a,b,x;
		for(long int y=1;y<=m;y++)
		{
			scanf("%ld%ld%ld",&a,&b,&x);

			arr[y].v1=a;
			arr[y].v2=b;
			arr[y].wt=x;

		}
		sort (arr+1,arr+m+1,comparator);
		for(long int g=1;g<=n;g++)
		{
			kings[g]=g;
		}
		for(long int h=1;h<=m;h++)
		{
			getmst(arr[h]);

		}



		printf("%lld\n",(len%1000000000));
		return 0;
	}

