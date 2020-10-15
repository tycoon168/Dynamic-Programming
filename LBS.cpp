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
	vector<int> ansf(n,1),ansb(n,1);
	vector<int> indexf(n),indexb(n);
	for(int i=0;i<n;i++)
		indexf[i]=indexb[i]=i;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i]&&ansf[j]+1>ansf[i])
			{
				ansf[i]=ansf[j]+1;
				indexf[i]=j;
			}
		}	
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=n-1;j>i;j--)
		{
			if(arr[j]<arr[i]&&ansb[j]+1>ansb[i])
			{
				ansb[i]=ansb[j]+1;
				indexb[i]=j;
			}
		}	
	}
	int mx=0,storei;
	for(int i=0;i<n;i++)
	{
		if(ansf[i]+ansb[i]-1>mx)
		{
			mx=ansf[i]+ansb[i]-1;
			storei=i;
		}
	}
	cout<<endl<<endl<<"LENGTH OF LONGEST BITONIC SUBSEQUENCE IS  :  "<<mx;
	cout<<endl<<endl<<"LONGEST BITONIC SUBSEQUENCE IS  :  ";
	stack<int> st;
	int i=storei;
	while(ansf[storei])
	{
		st.push(arr[i]);
		i=indexf[i];
		ansf[storei]--;
	}
	while(!st.empty())
	{
		cout<<st.top()<<",";
		st.pop();
	}
	ansb[storei]--;
	i=indexb[storei];
	while(ansb[storei])
	{
		cout<<arr[i]<<",";
		i=indexb[i];
		ansb[storei]--;
	}
	cout<<endl<<endl;
}
