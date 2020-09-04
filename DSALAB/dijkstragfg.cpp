// Program to find Dijkstra's shortest path using 
// priority_queue in STL  adj
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 
vector<pair<long int,long int>> adj[5000010];
vector<pair<long int,long int>> adj2[5000010];
int vis[100000];
int dist[100000];

priority_queue<pair<int, int> > q1;


void shortestPath(int src) 
{ 


	q1.push(make_pair(0, src)); 
	dist[src] = 0; 
	printf("HERE\n");

	while (!q1.empty()) 
	{ 
		int u = q1.top().second; 
		q1.pop(); 
		printf("***\n");
		// 'i' is used to get all adjacent vertices of a vertex 

		for (auto i = adj[u].begin(); i < adj[u].end();i++) 
		{ 
			printf("####\n");
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = (*i).first; 
			int weight = (*i).second; 

			// If there is shorted path to v through u.
			//  If there is shorted path to v through u. 
			if (dist[v] > dist[u] + weight) 
			{ 
				// Updating distance of v 
				dist[v] = dist[u] + weight; 
				pair<int,int>a;
				a.first=dist[v];
				a.second=v;
				printf("OOO\n");
				q1.push(a);
			} 
		} 
	}  

} 

// Driver program to test methods of graph class 
int main() 
{ 
	// create the graph given in above fugure 
	int m, n;
	scanf("%d%d",&n,&m);
	int a,b,x;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&x);
		adj[a].push_back(make_pair(b,x));
		adj2[b].push_back(make_pair(a,x));
	}
	for(int d=1;d<=n;d++)
		dist[d]=INF;



	shortestPath(1); 
	for(int f=1;f<=n;f++)
		printf("%d	",dist[f]);


	return 0; 
} 

