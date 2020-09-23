#include<iostream>
#include<vector>
using namespace std;
int n,m;
int dp(int i,int j,vector<vector<int> > &memo,vector<vector<bool>  > &sign)
{
	if(sign[i][j])
		return memo[i][j];
	if(i==0&&j==0)
		memo[i][j]=1;
	else if(i==0)
		memo[i][j]=dp(i,j-1,memo,sign);
	else if(j==0)
		memo[i][j]=dp(i-1,j,memo,sign);
	else memo[i][j]=dp(i,j-1,memo,sign)+dp(i-1,j,memo,sign);
	sign[i][j]=1;
	return memo[i][j];
}
int main()
{
	int n,m;
	cout<<endl<<"ENTER THE TOTAL NO OF ROWS  :  ";
	cin>>n;
	cout<<endl<<endl<<"ENTER THE TOTAL NO OF COLUMNS  :  ";
	cin>>m;
	vector<vector<int> > memo(n,vector<int> (m));
	vector<vector<bool> > sign(n,vector<bool> (m,0));
	cout<<endl<<endl<<"TOTAL NO OF WAYS TO REACH BOTTOM RIGHT ARE  :  "<<dp(n-1,m-1,memo,sign);
	cout<<endl<<endl;
}
