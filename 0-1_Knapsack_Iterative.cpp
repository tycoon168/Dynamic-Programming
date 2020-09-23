#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,m,a,b;
	cout<<"ENTER THE TOTAL NO OF ITEMS  :  ";
	cin>>n;
	vector<pair<int,int> > v(n+1);
	cout<<endl<<endl<<"ENTER THE ITEMS DETAILS  :  \n\nWEIGHT    PROFIT\n";
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		v[i]=make_pair(a,b);
	}
	cout<<endl<<endl<<"ENTER THE MAXIMUM CAPACITY OF THE BAG  :  ";
	cin>>m;
	vector<vector<int> > dp(n+1,vector<int> (m+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j<v[i].first)
				dp[i][j]=dp[i-1][j];
			else 
				dp[i][j]=max(dp[i-1][j],v[i].second+dp[i-1][j-v[i].first]);
		}
	}
	cout<<endl<<endl<<"MAXIMUM PROFIT THAT COULD BE GENERATED IS   :    "<<dp[n][m];
	int j=m;
	vector<bool> ans(n+1,0);
	for(int i=n;i>=1&&m!=0;i--)
	{
		if(dp[i][j]!=dp[i-1][j])
		{
			ans[i]=1;
			j-=v[i].first;
		}
	}
	cout<<endl<<endl<<"MAXIMUM PROFIT IS OBTAINED BY  :   ";
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<"  ";
	cout<<endl<<endl;
}
