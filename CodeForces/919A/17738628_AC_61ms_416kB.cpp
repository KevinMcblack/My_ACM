/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-16 08:53:47 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-16 08:59:48
 */

#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m;
    while(cin>>n>>m){
        double a,b;
        double minn=1000;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            minn=min(minn,a/b);
        }
        printf("%.8lf\n",minn*m);
    }
    return 0;
}
