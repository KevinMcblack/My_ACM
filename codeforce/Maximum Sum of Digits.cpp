/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-20 12:46:13 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-20 15:58:30
 */
#include <iostream>
using namespace std;
//一个数分成两个数的和 求这个两个数个个位数相加最大
//hint有误导 只要先计算这个数的位数len 求出len-1位最大的数 就是结果了
long long big[15];
void getEdge()
{
    long long num=1;
    for(int i=0;i<=11;i++)
    {
        num=num*10;
        big[i]=num-1;
    }
}
int main(int argc, char const *argv[])
{
    long long n;
    long long a;
    long long b;
    getEdge();
    while(cin>>n)
    {
        long long temp=n;
        int len=0;
        while(temp)
        {
            temp/=10;
            len++;
        }
        //cout<<len<<endl;
        a=big[len-2];
        b=n-a;
        int sum=0;
         while(a)
        {
            sum+=(a%10);
            a/=10;
        }
        while(b)
        {
            sum+=(b%10);
            b/=10;
        }
        cout<<sum<<endl;
    }
    return 0;
}
