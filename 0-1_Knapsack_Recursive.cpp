#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool mark[100][100]={0};
int memo[100][100];
bool ans[100]={0};
int dp(int n,int m,vector<pair<int,int> > &v)
{
	if(mark[n][m])
		return memo[n][m];
	int ans;
	if(m==0||n==0)
		ans=0;
	else if(v[n].first>m)
		ans=dp(n-1,m,v);
	else 
		ans=max(dp(n-1,m,v),v[n].second+dp(n-1,m-v[n].first,v));
	mark[n][m]=1;
	memo[n][m]=ans;
	return ans;
}
void recurse(int n,int m,vector<pair<int,int> > &v)	
{
	while(m!=0&&n>0)
	{
		if(dp(n-1,m,v)!=dp(n,m,v))
		{
			ans[n]=1;
			m-=v[n].first;
		}
		n--;
	}
}	
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
	cout<<endl<<endl<<"MAXIMUM PROFIT GENERATED IS  :  "<<dp(n,m,v);
	recurse(n,m,v);
	cout<<endl<<endl<<"MAXIMUM PROFIT IS OBTAINED BY  :   ";
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<"  ";
	cout<<endl<<endl;
}
