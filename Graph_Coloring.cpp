#include<iostream>
#include<vector>
using namespace std;
int m,n,e,count=0;
int x[10001]={0};
char arr[10001];
vector<int> v[10001];
void nextval(int k)
{
	int i;
	x[k]=(x[k]+1)%(m+1);
	while(x[k]!=0)
	{
		for(i=0;i<v[k].size();i++)
			if(x[v[k][i]]==x[k])    //x[v[k][i]]==x[k] is enabling backtracking 
				break;
		if(i==v[k].size())
			return;
		x[k]=(x[k]+1)%(m+1);
	}
}
void print()
{
	for(int i=1;i<=n;i++)
		cout<<arr[x[i]]<<" ";
	cout<<endl<<endl;
}
void mcoloring(int k)
{
	nextval(k);
	while(x[k]!=0)
	{
		if(k==n)
		{
			if(count==0)
				cout<<endl<<endl<<"\nPOSSIBLE WAYS FOR GRAPH COLORING ARE  :  \n\n";
			print();
			count++;
		}
		else mcoloring(k+1);
		nextval(k);
	}
}
int main()
{
	int a,b;
	cout<<"ENTER THE NO OF VERTICES  :  ";
	cin>>n;
	cout<<endl<<"ENTER THE TOTAL NO EDGES  :  ";
	cin>>e;
	cout<<endl<<"ENTER THE EDGE DETAILS  :  ";
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout<<endl<<endl<<"ENTER THE TOTAL NO OF COLORS  :  ";
	cin>>m;
	cout<<endl<<"ENTER THE COLORS  :  ";
	for(int i=1;i<=m;i++)
		cin>>arr[i];
	mcoloring(1);
	if(count==0)
		cout<<endl<<endl<<"THERE IS NO POSSIBLE WAY TO COLOR THE GRAPH !!";
	else cout<<"TOTAL POSSIBLE WAYS  :  "<<count;
}
