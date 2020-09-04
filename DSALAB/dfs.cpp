#include <iostream> 
#include <vector> 
  
using namespace std; 
//#include<stdio.h>
#include<bits/stdc++.h>

vector<int> adj[6];
bool test[7];
int ctr=0;

void print(int x)
{
printf("ctr:%d\n",ctr);
if(test[x]==false)
{
printf("%d	%d\n",x,ctr);
ctr++;
test[x]=true;
for (auto ir = adj[x].rbegin(); ir != adj[x].rend(); ++ir) 
        print(*ir);
}
else
return;
return;
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
for (auto ir = adj[1].rbegin(); ir != adj[1].rend(); ir++) 
{
//printf("value passed:%d\n", *ir);
        print(*ir);
}
return 0;
}



