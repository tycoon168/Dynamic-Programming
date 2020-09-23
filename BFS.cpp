#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool mark[1001]={0};
vector<int> v[1001];
void bfs(int n)
{
	if(!mark[n])
	{
		mark[n]=1;
		int a;
		queue<int> q;
		q.push(n);
		while(!q.empty())
		{
			a=q.front();
			q.pop();
			for(int i=0;i<v[a].size();i++)
				if(!mark[v[a][i]])
				{
					q.push(v[a][i]);
					mark[v[a][i]]=1;
				}
		}
	}
}
int main()
{
	int n,e,a,b;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		//v[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
	{
		bfs(i);
	}
	for(int i=1;i<=n;i++)
		cout<<mark[i]<<"  ";
}
