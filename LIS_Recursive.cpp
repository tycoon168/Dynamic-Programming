#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> memo(100,1);
bool sign[100]={0};
vector<int> index(100);
int dp(int i,vector<int> &arr)
{
	if(sign[i])
		return memo[i];
	int val=memo[i];
	for(int j=0;j<i;j++)
	{
		if(arr[j]<arr[i]&&val<1+dp(j,arr))
		{
			val=1+dp(j,arr);
			index[i]=j;
		}
	}
	memo[i]=val;
	sign[i]=1;
	return memo[i];
}	
int main()
{
	int n,storei;
	cout<<"ENTER THE NO OF ELEMENTS IN THE SEQUENCE  :  ";
	cin>>n;
	vector<int> arr(n);
	cout<<endl<<endl<<"ENTER THE ELEMENTS OF THE SEQUENCE  :  ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
		index[i]=i;
	int mx=1;
	for(int i=0;i<n;i++)
	{
		if(dp(i,arr)>mx)
		{
			storei=i;
			mx=dp(i,arr);
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
