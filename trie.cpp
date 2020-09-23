#include<bits/stdc++.h>
using namespace std;
struct node
{
    node * ptr[26];
    int mx;
};
node * tree;
void create(string str,int w)
{
    node *temp=tree;
    for(int i=0;i<str.length();i++)
    {
        if(temp->ptr[str[i]-'a']==NULL)
        {
            node *p=(node *)(malloc(sizeof(node)));
            p->mx=w;
            for(int k=0;k<26;k++)
                p->ptr[k]=NULL;
            temp->ptr[str[i]-'a']=p;
            temp=p;
        }
        else
        {
            temp=temp->ptr[str[i]-'a'];
            temp->mx=max(temp->mx,w);
        }
    }
}
int findmax(string str)
{
    node *temp=tree;
    int i=0;
    while(i<str.length()&&temp->ptr[str[i]-'a']!=NULL)
    {
        temp=temp->ptr[str[i]-'a'];
        i++;
    }
    if(i!=str.length())
        return -1;
    else return temp->mx;
}
int main()
{
    int n,q,w,ans;
    string str;
    cin>>n>>q;
    tree=(node *)(malloc(sizeof(node)));
    for(int i=0;i<26;i++)
        tree->ptr[i]=NULL;
    for(int i=0;i<n;i++)
    {
        cin>>str>>w;
        create(str,w);
    }
    while(q--)
    {
        cin>>str;
        ans=findmax(str);
        cout<<ans<<endl;
    }
}
