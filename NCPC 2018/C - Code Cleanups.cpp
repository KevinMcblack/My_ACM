/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-29 18:53:58 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-29 20:14:48
 */
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int day[400];
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>day[i];
        int sum=0;
        int temp=0;
        sum=day[0]+19;
        for(int i=1;i<n;i++)
        {
           if(day[i]>sum)
           {
                temp++;
                sum=day[i]+19;
           }
        }
        cout<<temp+1<<endl;
    }
    return 0;
}
