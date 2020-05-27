#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    string pre[5];
    while(cin>>s){
        cin>>pre[0]>>pre[1]>>pre[2]>>pre[3]>>pre[4];
        int flag=0;
        for(int i=0;i<5;i++){
            if(pre[i][0]==s[0]||pre[i][1]==s[1]){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}