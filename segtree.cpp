// Building a segment tree for range queries and updating values.In this case it is addition in a specified range
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
#define MAX 1000000007
lli segtree(vector<lli> &arr,vector<lli> &tree,lli node,lli start,lli end)
{
    lli mid;
    if(start > end)
    	return 0;
    if(start == end)
    {
        tree[node] = (mod(arr[start])*mod(arr[start]))%MAX;
        return tree[node];
    }
    else
    {
        mid = start + (end - start)/2;
        tree[node] = (segtree(arr,tree,2*node+1,start,mid) + segtree(arr,tree,2*node+2,mid+1,end))%MAX;
        return tree[node];
    }
}
lli range_query(vector<lli> &tree,lli node,lli qs,lli qe,lli ss,lli se)  // called as range_query(tree,0,qs,qe,0,n-1)
{
    lli sum = 0,mid;
    mid = ss + (se - ss)/2;
    if(qs <= ss && se <= qe)
        return tree[node];
    if(ss < qs || qe < se)
        return 0;
    sum = range_query(tree,2*node + 1,qs,qe,ss,mid) + range_query(tree,2*node + 2,qs,qe,mid + 1,se);
    return sum; 
}
void update(vector<lli> &tree,lli node,lli i,lli start,lli end,lli diff)
{
     lli mid;
     mid = (start + end)/2;
     if(i < start || end < i)
     return;
     tree[node] = tree[node] + diff;
     if(start <= end)
     {
        update(tree,2*node + 1,i,start,mid,diff);
        update(tree,2*node + 2,i,mid + 1,end,diff);
     } 
}
int main()
{
    lli i,j,n,q,a,t,opt,x,y;
    cin >> t;
    while(t--)
    {
    cin >> n >> q;
    vector<lli> tree(2*n - 1),arr(n);
    for(i=0;i<n;i++)
    cin >> arr[i];
    a = segtree(arr,tree,0,0,n-1);
    cin >> q;
    while(q--)
    {
        
    }
    }
    return 0;
}
