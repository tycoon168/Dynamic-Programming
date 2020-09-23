#include<iostream>
#include<vector>
using namespace std;
int dp(int i,int j,vector<vector<int> > &memo,vector<vector<bool> > &sign,vector<vector<int> > &arr)
{
	if(sign[i][j])
		return memo[i][j];
	int val;
	if(i==0||j==0)
		val=0;
	else 
		val=arr[i-1][j-1]+dp(i-1,j,memo,sign,arr)+dp(i,j-1,memo,sign,arr)-dp(i-1,j-1,memo,sign,arr);
	memo[i][j]=val;
	sign[i][j]=1;
	return memo[i][j];
}	
int main()
{
	int n,m,r1,c1,r2,c2;
	cout<<endl<<"ENTER THE ROWS AND COLUMNS OF MATRIX  :  ";
	cin>>n>>m;
	vector<vector<int> > arr(n,vector<int> (m));
	cout<<endl<<endl<<"ENTER THE ELEMENTS OF MATRIX  :  "<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
	vector<vector<int> > memo(n+1,vector<int> (m+1,0));
	vector<vector<bool> > sign(n+1,vector<bool> (m+1,0));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			int a=dp(i,j,memo,sign,arr);
			
	cout<<endl<<endl<<"ENTER THE POSITION OF TOPLEFT CORNER  :  ";
	cin>>r1>>c1;
	cout<<endl<<endl<<"ENTER THE POSITION OF BOTTOM RIGHT CORNER  :  ";
	cin>>r2>>c2;
	int val=memo[r2][c2]-memo[r2][c1-1]-memo[r1-1][c2]+memo[r1-1][c1-1];
	cout<<endl<<endl<<"SUM OF SUBRECTANGLE FORMED IS  :  "<<val<<endl<<endl;
}
