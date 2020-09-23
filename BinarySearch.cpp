#include<iostream>
#include<algorithm>
using namespace std;
int binsrch(int *arr,int n,int key)
{
    int l=0,h=n,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr[mid])
            return mid;
        if(key<arr[mid])
            h=mid-1;
        else l=mid+1;
    }
    return -1;
}
int binsrchrec(int *arr,int l,int h,int key)
{
    if(l>h)
        return -1;
    int mid=(l+h)/2;
    if(key==arr[mid])
        return mid;
    if(key<arr[mid])
        return binsrchrec(arr,l,mid-1,key);
    else return binsrchrec(arr,mid+1,h,key);
}
int main()
{
	int n,key;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
    cout<<endl<<endl<<"Enter the key to be searched  :  ";
    cin>>key;
    int ans=binsrch(arr,n-1,key);
    if(ans==-1)
        cout<<endl<<endl<<key<<" not found!!";
    else cout<<endl<<endl<<key<<" found at position "<<ans+1;
    ans=binsrchrec(arr,0,n-1,key);
    if(ans==-1)
        cout<<endl<<endl<<key<<" not found!!";
    else cout<<endl<<endl<<key<<" found at position "<<ans+1;
}
