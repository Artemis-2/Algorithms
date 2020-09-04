#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > pq; 
int dist[20];
bool test[20];
int short1=0;
vector<pair<long int,long int>> adj[5000010];

void dij(int a,int distance)
{
	//	printf("a:%d	%d\n",a,distance);
	if(test[a]==true)
		return;
	if(test[a]==false)
	{
		printf("a:%d    %d\n",a,distance);

		test[a]=true;
		dist[a]=distance;
		pair<int, int> top1 = pq.top();
		distance+=top1.second;
		pq.pop();


		int short1=dist[a]+adj[a][0].second;
		pq.push(adj[a][0]);
		printf("short1 is:%d\n",short1);
		int c=0;
		for (auto ir = adj[a].begin(); ir != adj[a].end(); ++ir)
		{

			pair<int, int>  h= *ir;
			int v=h.first;
			pq.push(h);
			printf("here%d		%d\n",adj[a][c].second,adj[a][c].first);

			if(short1>dist[a]+adj[a][c].second)
			{short1=dist[a]+adj[a][c].second;
			//	dist[adj[a][c].second]=short1;
				pq.push(adj[a][c]);
				printf("###%d\n",adj[a][c].first);
			}
			c++;

		}
		distance+=short1-dist[a];
	}

	/*while(!pq.empty())
	  {
	  printf("***%d          %d\n",pq.top().second,pq.top().first);
	  pq.pop();


	  }*/
	if(!pq.empty())
	{
		dij((pq.top()).first,distance);
	}
	





}

int main(void)
{
	long    int n,m,start;

	scanf("%ld%ld",&n,&m);
	long int a,b,x;
	for(long int y=1;y<=m;y++)
	{
		scanf("%ld%ld%ld",&a,&b,&x);

		adj[a].push_back(make_pair(b,x));
		adj[b].push_back(make_pair(a,x));

	}
	scanf("%ld",&start);
	for(int g=0;g<20;g++)
		test[g]=false;
	pq.push(make_pair(0,start));
	dij(start,0);
	while(!pq.empty())
	{
		dij(pq.top().first,0);
		pq.pop();
	}
	for(int i=1;i<=n;i++)
		printf("%d	",dist[i]);
	printf("\n");
	return 0;
}
