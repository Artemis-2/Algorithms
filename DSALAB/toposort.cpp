#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#include<bits/stdc++.h>
queue<int>q;
vector<int> adj[20];
bool test[20];
int indeg[20];
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
//		adj[b].push_back(a);
		indeg[b]++;
	}
	for(int it=1;it<=m;it++)
		test[it]=false;

	int ctr=0;

	int i;
	for( i=1;i<=m;i++)
	{
		if(indeg[i]==0)
			q.push(i);
	}

	int x;

	while(q.size()!=0)
	{
		x=q.front();
			for (auto ir = adj[x].rbegin(); ir != adj[x].rend(); ir++)
			{
				indeg[*ir]--;
				if(test[*ir]==false&&indeg[*ir]==0)
				{
					q.push(*ir);
					test[*ir]=true;
				}
			}

			test[x]=true;
		
		printf("%d\n",q.front());
		q.pop();

	}
	return 0;
	
}
