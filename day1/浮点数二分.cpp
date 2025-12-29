#include<iostream>
using namespace std;
//本题旨在求一个数的三次方根
int main()
{
    const double num=1e-8;//注意写法
    int n;
    cin>>n;
    int l=-10000;
    int r=10000;
    while(r-l>num)//注意写法
    {
        double mid=(l+r)/2;//不能用>>1
        if(mid*mid*mid>n)
        r=mid;//为什么不用>=,因为可能根本不存在精确地数，控制在可接受范围内即可
        else
        l=mid;//不是mid+1哦
    }
    cout<<l;
}