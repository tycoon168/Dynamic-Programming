#include<bits/stdc++.h>
#include<stdio.h>
typedef long long ll;
typedef double llf;
#define mod 1000000007
#define cin1(a) scanf("%lld",&a)
#define cin2(a,b) scanf("%lld%lld",&a,&b)
#define cin3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define cin4(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define cinc(x) scanf("%c",&x)
#define cinf(x) scanf("%lf",&x)
#define cins(x) scanf("%s",x)
#define cinl(x) getline(cin,x)
#define mp make_pair
#define pb push_back
-------------------------------------x---------------------------------------------

//FAST MATRIX EXPONENTIATION
long long int ans[2][2];
long long int a[2][2];
long long int brr[2][1];
long long mod=1000000007;
a[0][0]=a[0][1]=a[1][0]=1;
a[1][1]=0;
ans[0][0]=ans[1][1]=1;
ans[0][1]=ans[1][0]=0;
brr[0][0]=1;
brr[1][0]=0;
void mul()
{
    long long int prr[2][1]={0};
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            prr[i][0]=(prr[i][0]+(ans[i][j]*brr[j][0])%mod)%mod;
    brr[0][0]=prr[0][0];
    brr[1][0]=prr[1][0];
}
void matmul(bool flag)
{
    long long int temp[2][2]={0};
    if(flag)
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    temp[i][j]=(temp[i][j]+(ans[i][k]*a[k][j])%mod)%mod;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                ans[i][j]=temp[i][j];
    }
    else
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    temp[i][j]=(temp[i][j]+(a[i][k]*a[k][j])%mod)%mod;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                a[i][j]=temp[i][j];
    }
}
void powermod(long int n)
{
	while(n)
    {
        if(n&1)
            matmul(1);
        matmul(0);
        n>>=1;
    }
    mul();
}
--------------------------------------------x------------------------------------------------

//MODULAR EXPONENTIATION + LUCAS THEOREM
ll fact[1000001],modfact[1000001];
void fs(ll &number)
{
	bool negative=false;
    register ll c;
    number=0;
    c=getchar();
    if (c=='-')
    {
        negative=true;
        c=getchar();
    }
    for (;(c>47&&c<58);c=getchar())
        number=number*10+c-48;
    if (negative)
        number*=-1;
}
ll power(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1)
			res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}
ll powermod(ll x,ll y)
{
	x=x%mod;
	ll res=1;
	while (y)
	{
		if (y&1)
			res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
void factorial()
{
	fact[0]=1;
	modfact[0]=power(1,mod-2)%mod;
	for(ll i=1;i<=1000000;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		modfact[i]=(modfact[i-1]*powermod(i,mod-2))%mod;
	}
}
------------------------------------------x-----------------------------------------------

//SEGMENT TREE (MINVALUE)
ll st[400004],dif[100000];
ll minVal(ll x, ll y) { return (x < y)? y: x; }

ll conST(ll ss, ll se, ll si)
{
    if (ss == se)
    {
        st[si] = dif[ss];
        return st[si];
    }
    ll mid =  ss+(se-ss)/2;
    st[si] =  minVal(conST( ss, mid, si*2+1),
                     conST(mid+1, se, si*2+2));
    return st[si];
}

ll MQ(int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];

    if (se < qs || ss > qe)
        return -1;

    int mid = ss+(se-ss)/2;
    return minVal(MQ(ss, mid, qs, qe, 2*index+1),
                  MQ(mid+1, se, qs, qe, 2*index+2));
}
---------------------------------------------x--------------------------------------------------

//SLIDING WINDOW(MAXIMUM VALUE)
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	priority_queue<pair<int,int> > pq;
		for(int i=0;i<n-3;i++)
		{
			for(int j=i;j<=i+3;j++)
				pq.push(make_pair(arr[j],j));
			while((pq.top()).second<i)
				pq.pop();
			cout<<"Maximum no between "<<i+1<<" to "<<i+4<<" is  :  "<<(pq.top()).first<<endl;
		}
--------------------------------------------x---------------------------------------------------

//SIEVE OF ERATOSTHENES
void sieve(int n)
{
	bool arr[n+1];
	memset(arr,1,sizeof(arr));
	for(int i=2;i*i<=n;i++)
	{
		if(arr[i])
		{
			for(int j=i*i;j<=n;j+=i)
					arr[j]=0;
		}
	}
	cout<<endl<<endl<<"Primes under "<<n<<" are  :  ";
	for(int i=2;i<=n;i++)
		if(arr[i])
			cout<<i<<" ";
}
-------------------------------------------x-----------------------------------------------------

//SEGMENTED SIEVE
void segmentedsieve(long long n)
{
	vector<int> prime;
	int s=floor(sqrt(n))+1;
	bool arr[s+1];
	memset(arr,1,sizeof(arr));
	for(int i=2;i*i<=s;i++)
	{
		if(arr[i])
		for(int j=i*i;j<=s;j+=i)
			arr[j]=0;
	}
	for(int i=2;i<=s;i++)
		if(arr[i])
			prime.push_back(i);
	int low=s;
	int high=s*2;
	while(low<n)
	{
		if(high>n)
			high=n;
		bool mark[high-low];
		memset(mark,1,sizeof(mark));
		for(int i=0;i<prime.size();i++)
		{
			long long lowrlim=(low/prime[i])*prime[i];
			if(lowrlim<low)
				lowrlim+=prime[i];
			for(long long j=lowrlim;j<high;j+=prime[i])
				mark[j-low]=0;
		}
		for(int i=low;i<high;i++)
		{
			if(mark[i-low])
				cout<<i<<" ";
		}
		low+=s;
		high+=s;
	}
	int i;
	for(i=0;i<prime.size();i++)
		if(n%prime[i]==0)
			break;
	if(i==prime.size())
		cout<<n<<" ";
}
------------------------------------------x------------------------------------------------

//PRIME FACTORIZATION OF N AND CORRESPONDING FREQUENCY + SUM,TOTAL NO OF FACTORS OF N
void printprimefactz1(int n)
{
	map<int,int> mp;
	for(int i=2;i*i<=n;i+=(1+i%2))
	{
		while(n%i==0)
		{
			mp[i]++;
			cout<<i<<" ";
			n/=i;
		}
		if(n==1)
			break;
	}
	if(n>2)
		cout<<n;
}
void printprimefactz2(int n)
{
	map<int,int> mp;
	vector<int> v(100001,0);
	for(int i=2;i<=100001;i++)
		v[i]=i;
	for(int i=2;i*i<=100001;i++)
	{
		if(v[i]==i)
		{
			for(int j=i*i;j<=100001;j+=i)
				if(v[j]==j)
					v[j]=i;
		}
	}
	while(n!=1)
	{
		cout<<v[n]<<" ";
		mp[v[n]]++;
		n/=v[n];
	}
}
void factors1(ll n)
{
	ll res=1,fact=1;
	for(int i=2;i*i<=n;i+=(1+i%2))
	{
		int count=0,sum=1,temp=1;
		while(n%i==0)
		{
			count++;
			temp*=i;
			sum+=temp;
			n/=i;
		}
		res*=sum;
		fact*=(count+1);
		if(n==1)
			break;
	}
	if(n>2)
	{
		res*=(n+1);
		fact*=2;
	}
	cout<<res<<"   "<<fact;
}
void factors2(ll n)
{
	ll res=1,fact=1;
	int arr[100001];
	for(int i=2;i<=100001;i++)
		arr[i]=i;
	for(int i=2;i*i<=100001;i+=(1+i%2))
	{
		if(arr[i]==i)
		{
			for(int j=i*i;j<=n;j+=i)
				if(arr[j]==j)
					arr[j]=i;
		}
	}
	int count=0,temp=1,sum=1;
	while(n!=1)
	{
		temp*=arr[n];
	    sum+=temp;
	    count++;
		if(arr[n]!=arr[n/arr[n]])
		{
			temp=1;
			res*=sum;
			sum=1;
			fact*=count+1;
			count=0;
		}
			n/=arr[n];
	}
	cout<<res<<"   "<<fact;
}
------------------------------------------x------------------------------------------------

//NO OF SUBARRAY WITH GIVEN SUM
int findsubarray(vector<int> &arr,int sum)
{
        int res=0,currsum=0;
        map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
                currsum+=arr[i];
                if(currsum==sum)
                    res++;
                res+=mp[currsum-sum];
                mp[currsum]++;
        }
        return res;
}
--------------------------------------------x-------------------------------------------------

//KEDANE'S ALGORITHM
int kedanes(vector<int> &arr,int n)
{
    int mx,sum=0;
    mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
            sum+=arr[i];
            if(sum>mx)
                mx=sum;
            if(sum<0)
                sum=0;
    }
    return mx;
}
--------------------------------------------x-------------------------------------------------

//SEGMENT TREE + LAZY PROPAGATION
pll tree[4*200010];
ll lazy[4*200010];
vll arr;
pll build(ll s,ll e,ll node)
{
	if(s==e)
	{
		tree[node]=mkp(s,arr[s]);
		lazy[node]=0;
		return tree[node];
	}
	ll mid=(s+e)/2;
	pll a,b;
	a=build(s,mid,2*node);
	b=build(mid+1,e,2*node+1);
	if(a.S<b.S)
		tree[node]=a;
	else tree[node]=b;
	lazy[node]=0;
	return tree[node];
}
 
void update(ll s,ll e,ll node,ll l,ll r,ll val)
{
	if(lazy[node]!=0)
	{
		tree[node].S+=lazy[node];
		if(s!=e)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(s>e||e<l||s>r)
		return;
	if(s>=l&&e<=r)
	{
		tree[node].S+=val;
		if(s!=e)
		{
			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}
		return;
	}
	ll mid=(s+e)/2;
	pll a,b;
	update(s,mid,2*node,l,r,val);
	update(mid+1,e,2*node+1,l,r,val);
	a=tree[2*node];
	b=tree[2*node+1];
	if(a.S<b.S)
		tree[node]=a;
	else tree[node]=b;
}
 
pll query(ll s,ll e,ll node,ll l,ll r)
{
	if(lazy[node]!=0)
	{
		tree[node].S+=lazy[node];
		if(s!=e)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(l>r||e<l||s>r)
		return mkp(-1,(1LL<<40));
	if(s>=l&&e<=r)	
		return tree[node];
	ll mid=(s+e)/2;
	pll a,b;
	a=query(s,mid,2*node,l,r);
	b=query(mid+1,e,2*node+1,l,r);
	//tree[node]=tree[2*node].S<tree[2*node+1].S?tree[2*node]:tree[2*node+1];
	return a.S<b.S?a:b;
}
--------------------------------------------x-------------------------------------------------

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	int val;
	cin>>val;
    double a=pow(val,0.5);
	int b=a;
	if(a==b)
	cout<<1;
	else cout<<0;
}
