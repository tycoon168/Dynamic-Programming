#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string s;
	cout<<endl<<"ENTER THE STRING  :  ";
	cin>>s;
	int n=s.length();
	vector<vector<int> > ans(n,vector<int> (n,0));
	int mx=0,storei,storej;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(i==0)
				ans[j][j+i]=1;
			else
			{
				if(s[j]==s[j+i]&&(ans[j+1][j+i-1]!=-1))
					ans[j][j+i]=ans[j+1][j+i-1]+2;
				else ans[j][j+i]=-1;
			}
			if(ans[j][j+i]>mx)
			{
				mx=ans[j][j+i];
				storei=j;
				storej=j+i;
			}
		}
	}
	cout<<endl<<endl<<"LENGTH OF LONGEST PALINDROMIC SUBSTRING IS  :  "<<mx;
	cout<<endl<<endl<<"LONGEST PALINDROMIC SUBSTRING IS  :  ";
	for(int i=storei;i<=storej;i++)
		cout<<s[i]<<",";
	cout<<endl<<endl;
}
