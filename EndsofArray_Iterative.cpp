#include<iostream>
#include<vector>
using namespace std;
vector<int> save;
void recurse(int i,int j,vector<vector<int> > &mark,bool flag,vector<int> &arr)
{
	if(i>j)
		return;
	if(flag)
	{
		save.push_back(arr[mark[i][j]]);
		if(mark[i][j]==i)
			recurse(i+1,j,mark,0,arr);
		else	recurse(i,j-1,mark,0,arr);
	}
	else
	{
		if(mark[i][j]==i)
			recurse(i+1,j,mark,1,arr);
		else	recurse(i,j-1,mark,1,arr);
	}
}		
int main()
{
	int n;
	cout<<endl<<"ENTER THE SIZE OF THE ARRAY  :  ";
	cin>>n;
	vector<int> arr(n),sum(n);
	cout<<endl<<endl<<"ENTER THE ELEMENTS OF THE ARRAY  :  ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sum[0]=arr[0];
	for(int i=1;i<n;i++)
		sum[i]=arr[i]+sum[i-1];
	vector<vector<pair<int,int> > > ans(n,vector<pair<int,int> > (n));
	vector<vector<int> > mark(n,vector<int> (n));
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n-i;j++)
		{
			if(i==1)
			{
				ans[j][j+i-1].first=arr[j];
				ans[j][j+i-1].second=0;
				mark[j][j]=j;
			}
			else 
			{
				if(ans[j+1][j+i-1].second+arr[j]>ans[j][j+i-2].second+arr[j+i-1])
				{
					ans[j][j+i-1].first=ans[j+1][j+i-1].second+arr[j];
					mark[j][j+i-1]=j;
				}
				else 
				{
					ans[j][j+i-1].first=ans[j][j+i-2].second+arr[j+i-1];
					mark[j][j+i-1]=j+i-1;
				}
				if(j==0)
					ans[j][j+i-1].second=sum[j+i-1]-ans[j][j+i-1].first;
				else ans[j][j+i-1].second=sum[j+i-1]-sum[j-1]-ans[j][j+i-1].first;
			}
		}
	}
	cout<<endl<<endl<<"MAXIMUM SUM GENERATED BY ENDS OF ARRAY IS  :  "<<ans[0][n-1].first;
	cout<<endl<<endl<<"ELEMENTS NEED TO SELECTED ARE  :  ";
	recurse(0,n-1,mark,1,arr);
	for(int i=0;i<save.size();i++)
		cout<<save[i]<<" ";
	cout<<endl<<endl;
}
