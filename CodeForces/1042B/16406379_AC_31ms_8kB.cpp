/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-13 13:58:15 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-13 14:42:08
 */
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
using namespace std;
map<string,int> m;
map<string,int>::iterator it;
int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n)
    {
        m.clear();
        int minn=500000;
        m["A"]=minn;
        m["B"]=minn;
        m["C"]=minn;
        m["AB"]=minn;
        m["AC"]=minn;
        m["BC"]=minn;
        m["ABC"]=minn;
        for(int i=0;i<n;i++)
        {
            int c;
            string s;
            cin>>c>>s;
            sort(s.begin(),s.end());
            m[s]=min(c,m[s]);
        }
        int minn1=m["ABC"];
        int minn2=m["AB"]+m["C"];
        int minn3=m["AC"]+m["B"];
        int minn4=m["BC"]+m["A"];
        int minn5=m["A"]+m["B"]+m["C"];
        int minn6=m["AB"]+m["AC"];
        int minn7=m["BC"]+m["AB"];
        int minn8=m["AC"]+m["BC"];
        minn=min(minn1,min(minn2,min(minn3,min(minn4,min(minn5,min(minn6,minn7))))));
        minn=min(minn,minn8);
        if(minn==500000)
            cout<<-1<<endl;
        else
            cout<<minn<<endl;
    }
    return 0;
}