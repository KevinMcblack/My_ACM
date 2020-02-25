#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1e6+ 5;
int n;
int a[10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin>>n){
		int minn=maxn;
		for(int i=0;i<9;i++){
			cin>>a[i];
			if(a[i]<minn){
				minn=a[i];
			}  
		}
		if(n<minn){
			cout<<-1<<endl;
			continue;
		}
		int cnt=n/minn;
		for(int i=cnt-1;i>=0;i--){
			for(int j=8;j>=0;j--){
				if(n>=a[j]&&(n-a[j])/minn>=i){
					cout<<j+1;
					n-=a[j];
					break;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
