#include<iostream>
using namespace std;
long long fact(int n)
{
   long long int product=1;
   if(n>0)
   {
      for(int i=1;i<=n;i++)
        product*=i;
   }
   return product;
}
long long combination(int a,int b)
{
    long long int p=fact(a);
    long long int q=fact(b);
    long long int r=fact(a-b);
    return (p/(q*r));
}
int main()
{
	int n,e;
	cout<<endl<<endl<<"ENTER THE NO OF NODES  :  "
	cin>>n;
	cout<<endl<<endl<<"ENTER THE NO OF EDGES  :  ";
	cin>>e;
	cout<<endl<<endl<<"ENTER THE EDGE DETAILS  :  ";
	vector<int> g(n,99999);
	vector<vector<int> > v(n,g);
	int a,b,w;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>w;
		arr[a][b]=w;
	}
	if(n==1)
		cout<<endl<<endl<<"NO POSSIBLE PATH !!";
	else 
	{
		long val=pow(2,n);
		long dp[n][val]={0};
		for(int i=0;i<n-1;i++)
		{
			for(int j=1;j<n;j++)
			{
				long long com=combination(n-2,i);
				for(int k=1;k<=com;k++)
				{
					for(int u=
					
	
	
	
	
