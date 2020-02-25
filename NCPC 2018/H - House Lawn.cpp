/*
* @Author: KevinMcblack
* @Date: 2018-10-30 19:04:56
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-30 20:41:56
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
struct lawn
{
    string name;
    int price;
    int rete;
    int work;
    int recharge;
} robot, success[150];
bool cmp(const lawn &aa, const lawn &bb)
{
    return aa.price < bb.price;
}
void getName()
{
    char c;
    robot.name = "";
    for (;;)
    {
        c = getchar();
        if (c == ',')
            break;
        robot.name += c;
    }
}
int main(int argc, char const *argv[])
{
    int l, m;

    while (cin >> l >> m)
    {
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            getchar();
            getName();
            scanf("%d,%d,%d,%d", &robot.price, &robot.rete, &robot.work, &robot.recharge);
            int once=robot.rete*robot.work;
            double sum=l/once*robot.work+l/once*robot.recharge+((l%once)*1.0)/robot.rete;
            if(l%once!=0)
            {
                sum+=((l%once)*1.0)/(once*robot.recharge);
            }
            if (sum <=10080)
                success[cnt++] = robot;
        }
        sort(success, success + cnt, cmp);
        if (cnt != 0)
        {
            cout << success[0].name << endl;
            for (int i = 1; i < cnt; i++)
            {
                if (success[i].price == success[i - 1].price)
                {
                    cout << success[i].name << endl;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            cout << "no such mower" << endl;
        }
    }
    return 0;
}
