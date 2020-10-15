#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s1,s2;
	cout<<"ENTER THE FIRST STRING  :  ";
	cin>>s1;
	cout<<endl<<endl<<"ENTER THE SECOND STRING  :  ";
	cin>>s2;
	int l1,l2;
	l1=s1.length();
	l2=s2.length();
	vector<vector<int> > v(l1+1,vector<int> (l2+1,0));
	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(s1[i-1]==s2[j-1])
				v[i][j]=v[i-1][j-1]+1;
			else v[i][j]=max(v[i-1][j],v[i][j-1]);
		}
	}
	cout<<endl<<endl<<"LENGTH OF LONGEST COMMON SUBSEQUENCE BETWEEN THEM  :  "<<v[l1][l2];
	int a=l1,b=l2;
	vector<bool> flag(l1+1,0);
	while(a&&b&&v[a][b])
	{
		if(v[a][b]!=v[a-1][b]&&v[a][b]!=v[a][b-1])
		{
			flag[a-1]=1;
			a--;
			b--;
		}
		else if(v[a][b]==v[a][b-1])
			b--;
		else 
			a--;
	}
	cout<<endl<<endl<<"LONGEST COMMON SUBSEQUENCE IS  :  ";
	for(int i=0;i<l1;i++)
		if(flag[i])
			cout<<s1[i]<<" ";
}					
