#include<iostream>
#include<vector>
using namespace std;
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
	vector<vector<int> > ans(n+1,vector<int> (m+1,0));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans[i][j]=arr[i-1][j-1]+ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
			
	cout<<endl<<endl<<"ENTER THE POSITION OF TOPLEFT CORNER  :  ";
	cin>>r1>>c1;
	cout<<endl<<endl<<"ENTER THE POSITION OF BOTTOM RIGHT CORNER  :  ";
	cin>>r2>>c2;
	int val=ans[r2][c2]-ans[r2][c1-1]-ans[r1-1][c2]+ans[r1-1][c1-1];
	cout<<endl<<endl<<"SUM OF SUBRECTANGLE FORMED IS  :  "<<val<<endl<<endl;
}
	
