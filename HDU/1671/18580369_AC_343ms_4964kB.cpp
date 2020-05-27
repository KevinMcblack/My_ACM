#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//判断一个字符串是否出现在另一个字符串的前缀中
struct node
{
    node *child[10];
    bool final;
    node()
    {
        memset(child, 0, sizeof(child));
        final = false;
    }
};
node *root;
int flag;
void insert(string s)
{
    node *current, *newNode;
    int len = s.size();
    if (!len)
        return;
    current = root;
    for (int i = 0; i < len; i++)
    {
        if (current->child[s[i] - '0'] != 0)
        {
            if (i == len - 1)
                flag--;
            current = current->child[s[i] - '0'];
        }
        else
        {
            if (current->final == true)
            {
                flag--;
                current->final = false;
            }
            newNode = new node();
            current->child[s[i] - '0'] = newNode;
            current = newNode;
            if (i == len - 1)
            {
                current->final = true;
            }
        }
    }
}
void del(node *root)
{
    if (root == 0)
    {
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (root->child[i] != 0)
        {
            del(root->child[i]);
        }
    }
    delete root;
}
int main()
{
    int n, t;
    scanf("%d", &t);
    while (t--)
    {
        root = new node();
        scanf("%d", &n);
        flag = n;
        string temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            insert(temp);
        }
        if (flag != n)
            printf("NO\n");
        else
            printf("YES\n");
        del(root);
    }
    return 0;
}
