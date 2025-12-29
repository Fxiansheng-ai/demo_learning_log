//本文旨在实现upper_bound和lower_bound
//lower_bound可以找到左边界,upper_bound可以找到右边界
#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.empty())
    return {-1,-1};//没元素直接返回
    int left=0;int right=nums.size();
    //找左边界
    while(left<right)
    {
        int mid=(left+right)>>1;
        if(nums[mid]>=target)
        right=mid;
        else
        left=mid+1;
    }
    if(nums[left]!=target)
    return {-1,-1};//没有target直接返回
    int first=left;
    left=0;right=nums.size()-1;
    //找右边界多1的位置
    while(left<right)
    {
        int mid=(left+right)>>1;
        if(nums[mid]>target)
        right=mid;
        else
        left=mid+1;
    }
    //如果最后一位也是target的话就会出现这种情况
    int last=(nums[left]==target)?left:left-1;
    return {first,last};
}
//如果只有一位，找到了就返回下标，找不到就返回应插入的位置
//用第一种return nums[left]<target?left+1:left用于处理所有数都比要找的小这种情况