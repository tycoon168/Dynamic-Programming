#include<iostream>
#include<vector>
#include<string>
using namespace std;
string s;
int dp(int i,int j,vector<vector<int> > &memo,vector<vector<bool> > &sign)
{
	if(sign[i][j])
		return memo[i][j];
	if(i>j)
		return 0;
	int val;
	if(i==j)
		val=1;
	else if(s[i]==s[j])
		val=2+dp(i+1,j-1,memo,sign);
	else val=max(dp(i+1,j,memo,sign),dp(i,j-1,memo,sign));
	memo[i][j]=val;
	sign[i][j]=1;
	return memo[i][j];
}
int main()
{
	cout<<endl<<"ENTER THE STRING  :  ";
	cin>>s;
	int n=s.length();
	vector<vector<int> > memo(n,vector<int> (n,0));
	vector<vector<bool> > sign(n,vector<bool> (n,0));
	cout<<endl<<endl<<"LENGTH OF LONGEST PALINDROMIC SUBSEQUENCE IS  :  "<<dp(0,n-1,memo,sign);
	cout<<endl<<endl<<"LONGEST PALINDROMIC SUBSEQUENCE IS  :  ";
	int i=0,j=n-1;
	vector<bool> flag(n,0);
	while(i<=j)
	{
		if(s[i]==s[j])
		{
			flag[i]=flag[j]=1;
			i++;
			j--;
		}
		else 
		{
			if(dp(i+1,j,memo,sign)<dp(i,j-1,memo,sign))
				j--;
			else i++;
		}
	}
	for(i=0;i<n;i++)
		if(flag[i])
			cout<<s[i]<<",";
	cout<<endl<<endl;
}
	
