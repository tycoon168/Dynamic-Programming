#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
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
	vector<pair<int,int> > ans(3*n,make_pair(0,0));
	for(int i=0;i<3*n;i++)
	{
		ans[i].first=temp[i][2];
		ans[i].second=i;
	}
	int mx=0,storei;
	for(int i=3*n-1;i>=0;i--)
	{
		for(int j=3*n-1;j>i;j--)
		{
			if(temp[j][0]>temp[i][0]&&temp[j][1]>temp[i][1]&&ans[j].first+temp[i][2]>ans[i].first)
			{
				ans[i].first=temp[i][2]+ans[j].first;
				ans[i].second=j;
			}
		}
		if(ans[i].first>mx)
		{	
			mx=ans[i].first;
			storei=i;
		}
	}
	cout<<endl<<endl<<"MAXIMUM HEIGHT THAT COULD BE ATTAINED IS  :  "<<mx;
	cout<<endl<<endl<<"ARRANGEMENT OF BOXES ARE  :  ";
	while(storei!=ans[storei].second)
	{
		cout<<endl<<temp[storei][0]<<" "<<temp[storei][1]<<" "<<temp[storei][2];
		storei=ans[storei].second;
	}
	cout<<endl<<temp[storei][0]<<" "<<temp[storei][1]<<" "<<temp[storei][2];
	cout<<endl<<endl;
}
