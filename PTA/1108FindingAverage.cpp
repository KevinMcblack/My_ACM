/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-07 19:09:51 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-07 20:06:20
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n)
    {
        string s;
        int cnt=0;
        double sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            char *pos;
            double value=strtod(s.c_str(),&pos);
            bool flag=true;
            if(*pos!='\0')
                flag=false;
            if(value>1000||value<-1000)
                flag=false;
            int lpos=s.find_last_of(".");
            if(lpos!=string::npos)
                if(s.size()-lpos>3)
                    flag=false;
            if(flag)
            {
                cnt++;
                sum+=value;
            }else{
                cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
            }
        }
        if(cnt!=0)
        {
            if(cnt==1)
            {
                printf("The average of 1 number is %.2lf\n",sum);
            }
            else
            {
                 printf("The average of %d numbers is %.2lf\n",cnt,sum/cnt);
            }
        }
        else
        {
             cout<<"The average of 0 numbers is Undefined"<<endl;
        }
    }
    return 0;
}
