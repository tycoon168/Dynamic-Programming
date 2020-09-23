#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int dp(int i,vector<pair<int,int> > &memo,vector<bool> &sign,vector<vector<int> >&temp)
{
	if(sign[i])
		return memo[i].first;
	for(int j=3*n-1;j>i;j--)
	{
		if(temp[j][0]>temp[i][0]&&temp[j][1]>temp[i][1]&&(dp(j,memo,sign,temp)+temp[i][2])>memo[i].first)
		{
			memo[i].first=temp[i][2]+dp(j,memo,sign,temp);
			memo[i].second=j;
		}
	}
	sign[i]=1;
	return memo[i].first;
}
int main()
{
	cout<<endl<<"ENTER THE TOTAL NO OF BOXES  :  ";
	cin>>n;
	vector<vector<int> > arr(n,vector<int> (3)),temp(3*n,vector<int> (3));
	cout<<endl<<endl<<"ENTER THE DIMENSIONS OF BOXES  :  "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	for(int i=0;i<3*n;i+=3)
	{
		temp[i][2]=arr[i/3][0];
		temp[i][0]=max(arr[i/3][1],arr[i/3][2]);
		temp[i][1]=min(arr[i/3][1],arr[i/3][2]);
		temp[i+1][2]=arr[i/3][1];
		temp[i+1][0]=max(arr[i/3][0],arr[i/3][2]);
		temp[i+1][1]=min(arr[i/3][0],arr[i/3][2]);
		temp[i+2][2]=arr[i/3][2];
		temp[i+2][0]=max(arr[i/3][0],arr[i/3][1]);
		temp[i+2][1]=min(arr[i/3][0],arr[i/3][1]);
	}
	sort(temp.begin(),temp.end());
	vector<pair<int,int> > memo(3*n,make_pair(0,0));
	vector<bool> sign(3*n,0);
	for(int i=0;i<3*n;i++)
	{
		memo[i].first=temp[i][2];
		memo[i].second=i;
	}
	int mx=0,storei;
	for(int i=3*n-1;i>=0;i--)
	{
		int a=dp(i,memo,sign,temp);
		if(a>mx)
		{
			mx=a;
			storei=i;
		}
	}
	cout<<endl<<endl<<"MAXIMUM HEIGHT THAT COULD BE ATTAINED IS  :  "<<mx;
	cout<<endl<<endl<<"ARRANGEMENT OF BOXES ARE  :  ";
	while(storei!=memo[storei].second)
	{
		cout<<endl<<temp[storei][0]<<" "<<temp[storei][1]<<" "<<temp[storei][2];
		storei=memo[storei].second;
	}
	cout<<endl<<temp[storei][0]<<" "<<temp[storei][1]<<" "<<temp[storei][2];
	cout<<endl<<endl;
}
