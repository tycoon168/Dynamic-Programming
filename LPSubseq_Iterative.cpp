#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string s;
	cout<<endl<<"ENTER THE STRING  :  ";
	cin>>s;
	int len=s.length();
	vector<vector<int> > ans(len,vector<int> (len,0));
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len-i;j++)
		{
			if(i==0)
				ans[j][j+i]=1;
			else 
			{
				if(s[j]==s[j+i])
					ans[j][j+i]=2+ans[j+1][j+i-1];
				else ans[j][j+i]=max(ans[j+1][j+i],ans[j][j+i-1]);
			}
		}
	}
	cout<<endl<<endl<<"LENGTH OF LONGEST PALINDROMIC SUBSEQUENCE IS  :  "<<ans[0][len-1];
	cout<<endl<<endl<<"LONGEST PALINDROMIC SUBSEQUENCE IS  :  ";
	int i=0,j=len-1;
	vector<bool> flag(len,0);
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
			if(ans[i][j-1]>ans[i+1][j])
				j--;
			else i++;
		}
	}
	for(i=0;i<len;i++)
		if(flag[i])
			cout<<s[i]<<",";
	cout<<endl<<endl;
}
