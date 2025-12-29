#include<iostream>
#include<vector>
using namespace std;
void mergesort_recursion(vector<int>&result,vector<int>&arr,int l,int r)
{
    if(l>=r)
    return;
    int mid=(l+r)>>1;
    mergesort_recursion(result,arr,l,mid);
    mergesort_recursion(result,arr,mid+1,r);
    int i=l;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=r)
    {
        if(result[i]<=result[j])
        arr[k++]=result[i++];
        else
        arr[k++]=result[j++];
    }
    while(i<=mid)arr[k++]=result[i++];
    while(j<=r)arr[k++]=result[j++];
    for(int i=l,k=0;i<=r;i++,k++)
    {
        result[i]=arr[k];
    }
}
void mergesort(vector<int>&result)
{
    vector<int> arr(result.size());//千万别忘了分配空间，不然必崩，除非你后续只需要push_back
    mergesort_recursion(result,arr,0,result.size()-1);
}
int main()
{
    vector<int> result={6,1,2,7,9,3,4,5,10,8};
    mergesort(result);
    for(auto&e:result)
    {
        cout<<e<<' ';
    }
}