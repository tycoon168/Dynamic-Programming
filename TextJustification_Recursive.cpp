#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
map<int,int> mp,temp;
vector<int> memo(100);
vector<bool> sign(100,0);
int n,w;
int dp(int i,vector<vector<int> > &cost,vector<pair<string,int> > &str)
{
	if(sign[i])
		return memo[i];
	int temp=str[i].second+i;
	if(temp<=w)
	{
		memo[i]=(w-temp)*(w-temp);
		mp[i]=0;
	}
	else
	{
		int mn=9999999;
		for(int j=i-1;j>=0;j--)
		{
			if(dp(j,cost,str)+cost[j+1][i]<mn)
			{
				mn=dp(j,cost,str)+cost[j+1][i];
				mp[i]=j+1;
			}
		}
		memo[i]=mn;
	}
	sign[i]=1;
	return memo[i];
}
void recurse(int k,int line)
{
	if(k<0)
		return;
	for(int i=mp[k];i<=k;i++)
		temp[i]=line;
	recurse(mp[k]-1,line+1);
}
int main()
{
	cout<<endl<<"ENTER THE TOTAL NO OF STRINGS  :  ";
	cin>>n;
	vector<pair<string,int> > str(n);
	cout<<endl<<endl<<"ENTER THE STRINGS  :  ";
	for(int i=0;i<n;i++)
	{
		cin>>str[i].first;
		str[i].second=(str[i].first).length();
	}
	cout<<endl<<endl<<"ENTER THE WIDTH OF 1 LINE  :  ";
	cin>>w;
	for(int i=1;i<n;i++)
		str[i].second+=str[i-1].second;		
	vector<vector<int> > cost(n ,vector<int> (n,0));
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int fr,bk;
			if(i==0)
				bk=0;
			else bk=str[i-1].second;
			fr=str[j].second;
			int temp=fr-bk+j-i;
			if(temp>w)
				cost[i][j]=9999999;
			else
				cost[i][j]=(w-temp)*(w-temp);
		}
	}
	cout<<endl<<endl<<"MINIMUM SPACE FOR TEXT JUSTIFICATION IS  :  "<<dp(n-1,cost,str);
	recurse(n-1,1);
	cout<<endl<<endl<<"ARRANGEMENT OF STRINGS IS  :  ";
	cout<<endl<<endl<<str[0].first<<" ";
	for(int i=1;i<n;i++)
	{
		if(temp[i]!=temp[i-1])
			cout<<endl;
		cout<<str[i].first<<" ";
	}
	cout<<endl<<endl;
}
