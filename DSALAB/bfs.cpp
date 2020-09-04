#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
#include<bits/stdc++.h>
queue<int>q;
vector<int> adj[6];
bool test[7];
int ctr=0;

void print(int x)
{
//printf("jere\n");
	if(test[x]==false)
	{
		for (auto ir = adj[x].rbegin(); ir != adj[x].rend(); ir++)
		{

			q.push(*ir);
                       

		}
		printf("%d	%d\n",x,ctr);
		ctr++;
                test[x]=true;

	}
	q.pop();
        if(q.size()>0)
	print(q.front());

}
int main(void)
{
	adj[1].push_back(5);
	adj[2].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);
	adj[3].push_back(2);
	adj[3].push_back(5);
	adj[4].push_back(2);
	adj[5].push_back(1);
	adj[5].push_back(2);
	adj[5].push_back(3);
	for(int it=0;it<7;it++)
		test[it]=false;
	//printf("here\n");
	int ctr=0;
	q.push(adj[1][0]);
	print(q.front());
	return 0;
}

