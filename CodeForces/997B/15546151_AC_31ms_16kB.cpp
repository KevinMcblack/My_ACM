#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;
set<long long> s;
const int TRY=50;
long long Try[TRY];
const long long ans[12] = { 0,4,10,20,35,56,83,116,155,198,244,292 };

//long long Get_num(int n)
//{
//    s.clear();
//    for(int i=0;i<=n;i++)
//    {
//        for(int j=0;i+j<=n;j++)
//        {
//            for(int k=0;i+j+k<=n;k++)
//            {
//                int l=n-i-j-k;
//                s.insert(i+j*5+k*10+l*50);
//            }
//        }
//    }
//    return s.size();
//}

int main()
{
	 //   for(int i=0;i<TRY;i++)
	 //       Try[i]=Get_num(i);
		//for (int i = 1; i<TRY; i++)
		//	cout << Try[i]<< endl;
	 //   for(int i=1;i<TRY;i++)
	 //   	cout<<Try[i]-Try[i-1]<<endl;
	long long n;
	cin >> n;
	if (n <= 11)
		cout << ans[n] << endl;
	else
		cout << ans[11] + (n - 11) * 49 << endl;
	return 0;
}
