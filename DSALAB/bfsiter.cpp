#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
#include<bits/stdc++.h>
queue<int>q;
vector<int> adj[20];
bool test[20];
int ctr=0;
int lev[20];
int bip[20];
int main(void)
{
	int n,m;
	printf("Enter the number of edges and vertices\n");
	scanf("%d%d",&n,&m);
	int a,b;
	for(int y=0;y<n;y++)
	{
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int it=0;it<10;it++)
		test[it]=false;

	int ctr=0;
	for(int u=0;u<10;u++)
		bip[u]=0;
	int x=adj[1][0];
        lev[x]=0;
	bip[x]=1;
	int flag=0;
	q.push(x);
	while(q.size()>0)
	{
		x=q.front();
                

		if(test[x]==false)
		{
			for (auto ir = adj[x].rbegin(); ir != adj[x].rend(); ir++)
			{

				q.push(*ir);
                                if(lev[*ir]==0)
                                lev[*ir]=lev[x]+1;
				if(bip[*ir]==0)
				{
				if(bip[x]==1)
					bip[*ir]=2;
				else if(bip[x]==2)
					bip[*ir]=1;
				}
				if(bip[x]==1&&bip[*ir]==1)
					flag=-1;
				
				if(bip[x]==2&&bip[*ir]==2)
				flag=-1;	


			}
//			printf("%d      %d	%d	%d\n",x,ctr,lev[x],bip[x]);
			ctr++;
			test[x]=true;

		}
		q.pop();

	}
	if(flag==-1)
		printf("no\n");
	else 
		printf("yes\n");

	return 0;
}
