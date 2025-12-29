#include<iostream>
#include<string>
using namespace std;
string BigIntAdd(string nums1,string nums2)
{
    reverse(nums1.begin(),nums1.end());
    reverse(nums2.begin(),nums2.end());
    string res;
    int carry=0;//进位
    int i=0;
    while(i<nums1.size()||i<nums2.size()||carry>0)
    {
        int digit1=(i<nums1.size())?(nums1[i]-'0'):0;
        int digit2=(i<nums2.size())?(nums2[i]-'0'):0;
        int sum=digit1+digit2+carry;
        res.push_back(sum%10+'0');
        carry=sum/10;
        i++;
    }
    reverse(res.begin(),res.end());
    return res;
}