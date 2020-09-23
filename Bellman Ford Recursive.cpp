#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> g(1001,99999);
vector<vector<int> > cost(1001,g);
vector<int> dis(1001,99999);
vector<int> par(1001,0);
int memo[1001][1001];
bool sign[1001][1001];
int srt,n;
int dp(int i,int k)
{
	if(sign[i][k])
	return	memo[i][k];
	int ans,temp;
	if(k==1)
	{
		ans=cost[srt][i];
		par[i]=srt;
	}
	else 
	{
		ans=dp(i,k-1);
		for(int p=1;p<=n;p++)
		{
			temp=dp(p,k-1)+cost[p][i];
			if(temp<ans)
			{
				ans=temp;
				par[i]=p;
			}
		}
	}	
	sign[i][k]=1;
	memo[i][k]=ans;
	return ans;
}
int main()
{
	int e,a,b,c;
	cout<<"ENTER THE NO OF VERTICES IN THE GRAPH  :  ";
	cin>>n;
	cout<<"\nENTER THE NO OF EDGES IN THE GRAPH  :  ";
	cin>>e;
	cout<<endl<<"ENTER THE EDGE DETAILS  :  ";
	for(int i=0;i<e;i++)
	{
  	 	cin>>a>>b>>c;
		cost[a][b]=c;
	}
	cout<<endl<<"ENTER THE STARTING NODE  :  ";
	cin>>srt;
	for(int i=1;i<=n;i++)
		dis[i]=dp(i,n-1);	
		
	bool flag=0;
	for(int i=1;i<=n;i++)
		if(dp(i,n)!=dis[i])
			flag=1;
	if(flag)
		cout<<"\nNEGATIVE CYCLE DETECTED!!";
	else 
	{
		cout<<"\nNODES    DISTANCES      PATH\n";		
		for(int i=1,x;i<=n;i++)
		{
			if(dis[i]!=99999)
			{
				stack<int> pk;
				pk.push(i);
				x=i;
				cout<<i<<"  	    "<<dis[i]<<"	   	"; 
				if(i!=srt)
				{
					while(x!=srt)
					{
						pk.push(par[x]);
						x=par[x];
					}
					while(!pk.empty())
					{
						cout<<pk.top();
						pk.pop();
						if(pk.size())
							cout<<"--->";
					}
				}
				cout<<endl;
			}
			else cout<<i<<"   	UNREACHABLE\n";
		}
	}
}
