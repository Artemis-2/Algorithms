#include <iostream>
#include <vector>
using namespace std;
#include<bits/stdc++.h>
stack<int>q;
stack<int>q2;
vector<int> adj[20];
vector<int> adj2[20];
bool test[20];
bool test2[20];
int indeg[10];
void print(int x)
{

	if(test[x]==false)
	{
		
               test[x]=true;
		for (auto ir = adj[x].rbegin(); ir != adj[x].rend(); ++ir)
			        print(*ir);
		q.push(x);
	}
	else
		return;
	return;
}
void print2(int x)
{
	if(test2[x]==false)
	{
		test2[x]=true;
		printf("%d\n",x);
		for (auto ir = adj2[x].rbegin(); ir != adj2[x].rend(); ++ir)
		                                 print2(*ir);
		printf("emds here\n");
	}
	else
		return;
	return;
}

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
		adj2[b].push_back(a);
		indeg[b]++;
	}
	for(int it=1;it<=m;it++)
		test[it]=false;

	int ctr=0;

	int i;
	for( i=1;i<=m;i++)
	{
		if(indeg[i]==0)
		print(i);
	}
	while(!q.empty())
	{
		print2(q.top());
		q.pop();
	}
	return 0;
	
}
