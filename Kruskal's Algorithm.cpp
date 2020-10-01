#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int arr[1000]={0};
void unin(int i,int j)
{
	arr[i]=j;
}
int par(int x)
{
	while(arr[x]!=-1)
	  x=arr[x];
	return x;
}
int main()
{
	int v,e,s,d,w;
	int mincost=0;
	priority_queue < vector<int> ,vector<vector<int> > ,greater<vector<int> > > g;
	vector<pair<int,int> > ans;
	cout<<"ENTER THE NO OF VERTICES IN THE GRAPH  :  ";
	cin>>v;
	for(int i=0;i<v;i++)
	 	arr[i]=-1;
	cout<<endl<<endl<<"ENTER THE NO OF EDGES IN THE GRAPH  :  ";
	cin>>e;
	cout<<endl<<endl<<"ENTER THE EDGE DETAILS    \n";
	for(int i=0;i<e;i++)
	{
		cin>>s>>d>>w;
		vector<int> temp;
		temp.push_back(w);
		temp.push_back(s-1);
		temp.push_back(d-1);
		g.push(temp);
	}
	int sum=0;
	while(!g.empty())
	{
        vector<int> temp=g.top();
        g.pop();
        int i,j,w,pari,parj;
        i=temp[1];
        j=temp[2];
        w=temp[0];
        pari=par(i);
        parj=par(j);
        if(pari!=parj)
        {
			unin(pari,parj);
			sum++;
			mincost+=w;
			ans.push_back(make_pair(i+1,j+1));
		}
		if(sum==v-1)
			break;
	}
	if(sum!=v-1)
		cout<<endl<<endl<<"MINIMUM SPANNING TREE IS NOT POSSIBLE !!";
	else
	{
		cout<<endl<<endl<<"EDGES OF THE MINIMUM SPANNING TREE ARE   \n";
		for(int i=0;i<v-1;i++)
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		cout<<endl<<"MINIMUM COST IS  :  "<<mincost<<endl;
	}
}
