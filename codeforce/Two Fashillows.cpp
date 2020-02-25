#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int d,w,m;
    while(cin>>d>>w>>m){
        if(w>d||d-m>=w){
            cout<<"good luck"<<endl;
            continue;
        }
        cout<<"see you next semester"<<endl;  
    }
    return 0;
}
