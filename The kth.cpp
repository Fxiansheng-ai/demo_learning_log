//本题旨在利用快排算法求出第k小的数，虽然这个貌似用堆更好一点
#include<iostream>
#include<vector>
using namespace std;
void quicksort_recursion(vector<int>&arr,int l,int r,int k)
{
    if(l>=r)
    return;
    int i=l-1;
    int j=r+1;
    int x=arr[(i+j)>>1];
    while(i<j)
    {
        do{i++;}while(arr[i]<x);
        do{j--;}while(arr[j]>x);
        if(i<j)swap(arr[i],arr[j]);
    }
    int len=j-l+1;
    if(k<=len)
    quicksort_recursion(arr,l,j,k);
    else
    quicksort_recursion(arr,l+1,r,k);
}
void quicksort(vector<int>&arr,int k)
{
    quicksort_recursion(arr,0,arr.size()-1,k);
}
int main()
{
    vector<int> arr={6,1,2,7,9,3,4,5,10,8};
    int k=3;
    quicksort(arr,k);
    cout<<arr[k-1];
}