#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main()
{
  	int n,e,a,b,c,srt;
	cout<<"ENTER THE NO OF VERTICES IN THE GRAPH  :  ";
	cin>>n;
	vector<pair<int,int> > v[n+1];
	cout<<"\nENTER THE NO OF EDGES IN THE GRAPH  :  ";
	cin>>e;
	cout<<endl<<"ENTER THE EDGE DETAILS  :  ";
	for(int i=0;i<e;i++)
	{
  	 	cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
	}
	vector<long int> dis(n+1,99999);
	vector<int> par(n+1,0);
	cout<<endl<<"ENTER THE STARTING NODE  :  ";
	cin>>srt;
	dis[srt]=0;
	vector<long int> d=dis;
	for(int i=1;i<=n-1;i++)
	{
		vector<long int> mdis=dis;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<v[j].size();k++)
			{
				if(mdis[v[j][k].first]>dis[j]+v[j][k].second)
				{
					mdis[v[j][k].first]=dis[j]+v[j][k].second;
					par[v[j][k].first]=j;
				}
			}
		}
		dis=mdis;
	}
	vector<long int> dis2=dis;
    for(int j=1;j<=n;j++)
		for(int k=0;k<v[j].size();k++)
			if(dis2[v[j][k].first]>dis2[j]+v[j][k].second)
			{
				dis2[v[j][k].first]=dis2[j]+v[j][k].second;
				par[v[j][k].first]=j;
			}
    int i;
    bool flag=0;
    for(i=1;i<=n;i++)
       if(dis[i]!=dis2[i])
			break;
    if(i==n+1)
    {
    	cout<<"\nNODES    DISTANCES      PATH\n";		
		for(int i=1,x;i<=n;i++)
		{
			if(dis[i]!=99999)
			{
				stack<int> pk;
				pk.push(i);
				x=i;
				cout<<i<<"  	    "<<dis[i]<<"	   	"; 
				if(i!=srt)
				{
					while(x!=srt)
					{
						pk.push(par[x]);
						x=par[x];
					}
					while(!pk.empty())
					{
						cout<<pk.top();
						pk.pop();
						if(pk.size())
							cout<<"--->";
					}
				}
				cout<<endl;
			}
			else cout<<i<<"   	UNREACHABLE\n";
		}
   }
   else cout<<"\n\nNEGATIVE CYCLE DETECTED !!";
	cout<<endl<<endl;
}
