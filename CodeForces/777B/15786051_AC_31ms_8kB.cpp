#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1e6+ 5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    string s1,s2;
    while(cin>>n){
        cin>>s1>>s2;
        int x=0,y=0;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i=0,j=0;j<n;j++){
            if(s2[j]>=s1[i]){
                i++;
            }else{
                x++;
            }
        }
        for(int i=n-1,j=n-1;i>=0&&j>=0;i--){
            if(s1[i]<s2[j]){
                y++;
                j--;
            }
        }
        cout<<x<<endl<<y<<endl;
    }
	return 0;
}
