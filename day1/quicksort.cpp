#include<iostream>
#include<vector>
using namespace std;
void quicksort_recursion(vector<int>&arr,int left,int right)
{
    if(left>=right)
    return;
    int i=left-1;//从界外开始
    int j=right+1;
    int x=arr[(left+right)>>1];
    while(i<j)
    {
        do{i++;}while(arr[i]<x);
        do{j--;}while(arr[j]>x);
        if(i<j)
        swap(arr[i],arr[j]);
    }//当走出循环，j会走到x应在位置的前一位
    quicksort_recursion(arr,left,j);
    quicksort_recursion(arr,j+1,right);
}
void quicksort(vector<int>&arr)
{
    quicksort_recursion(arr,0,arr.size()-1);
}
int main()
{
    vector<int> arr={6,1,2,7,9,3,4,5,10,8};
    quicksort(arr);
    for(auto&e:arr)
    {
        cout<<e<<' ';
    }
    return 0;
}
