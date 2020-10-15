#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	int n;
	cout<<"ENTER THE NO OF ELEMENTS IN THE SEQUENCE  :  ";
	cin>>n;
	vector<int> arr(n);
	cout<<endl<<endl<<"ENTER THE ELEMENTS OF THE SEQUENCE  :  ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<int> ans(n,1);
	int mx=1,storei;
	vector<int> index(n);
	for(int i=0;i<n;i++)
		index[i]=i;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i]&&ans[j]+1>ans[i])
			{
				ans[i]=ans[j]+1;
				index[i]=j;
			}
		}
		if(ans[i]>mx)
		{
			mx=ans[i];
			storei=i;
		}	
	}
	cout<<endl<<endl<<"LENGTH OF THE LONGEST INCREASING SUBSEQUENCE IS   :  "<<mx;
	cout<<endl<<endl<<"LONGEST INCREASING SUBSEQUENCE IS  :  ";
	stack<int> st;
	while(mx)
	{
		mx--;
		st.push(arr[storei]);
		storei=index[storei];
	}
	while(!st.empty())
	{
		cout<<st.top()<<"  ";
		st.pop();
	}
}
