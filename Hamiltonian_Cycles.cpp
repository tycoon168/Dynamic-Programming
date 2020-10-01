#include<iostream>
#include<vector>
using namespace std;
int n,e,count=0;
bool arr[1001][1001]={0};
int x[10001]={0};
void print()
{
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<x[i]<<"--->";
	cout<<1;
}
void hamiltonian(int k,vector<bool> mark,int val)
{
	mark[k]=1;
	x[val]=k;
	if(val==n&&arr[k][1])
	{
		if(count==0)
			cout<<endl<<endl<<"HAMILTONIAN CYCLES PRESENT ARE  :  ";
		count++;
		print();
	}
	else if(val<n)
	{
		for(int i=1;i<=n;i++)
		{
			if(!mark[i]&&arr[k][i])     //mark[i] is making n!, while arr[k][i] is enabling backtracking 
			{
				arr[i][k]=0;
				hamiltonian(i,mark,val+1);
				arr[i][k]=1;
			}
		}	
	} 
}
int main()
{
	int a,b;
	cout<<"ENTER THE NO OF VERTICES  :  ";
	cin>>n;
	cout<<endl<<endl<<"ENTER THE NO OF EDGES  :  ";
	cin>>e;
	cout<<endl<<endl<<"ENTER THE EDGE DETAILS  :  \n";
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		arr[a][b]=1;
		//arr[b][a]=1;
	}
	vector<bool> mark(n+1,0);
	hamiltonian(1,mark,1);
	if(count==0)
		cout<<endl<<endl<<"NO HAMILTONIAN CYCLES DETECTED !!";
}
