/*
 * @Author: KevinMcblack 
 * @Date: 2018-09-28 20:43:51 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-09-30 20:53:25
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
struct tree_key
{
    int lkey, rkey;
}key[20];
struct Node
{
    Node *lchild;
    Node *rchild;
    int data;
};
Node *create(int k)
{
    if (k == -1)
    {
        return NULL;
    }
    Node *root = new Node;
    root->data = k;
    root->lchild = create(key[k].lkey);
    root->rchild = create(key[k].rkey);
    return root;
}
void in_traversal(Node *root, int &n)
{
    if (root == NULL)
    {
        return;
    }
    in_traversal(root->rchild, n);
    n--;
    if (n == 0)
        cout << root->data<<endl;
    else
        cout <<root->data<< " ";
    in_traversal(root->lchild, n);
}
void bfs_traversal(Node *root, int n)
{
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        Node *p = que.front();
        n--;
        que.pop();
        if (n == 0)
            cout << p->data<<endl;
        else
            cout << p->data<< " " ;
        if (p->rchild)
            que.push(p->rchild);
        if (p->lchild)
            que.push(p->lchild);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        char left, right;
        bool flag[20];
        int root_key;
        memset(flag, false, sizeof(flag));
        for (int i = 0; i < 20; i++)
        {
            key[i].lkey = -1;
            key[i].rkey = -1;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> left >> right;
            if (left != '-')
            {
                key[i].lkey = left - '0';
                flag[left - '0'] = true;
            }
            if (right != '-')
            {
                key[i].rkey = right - '0';
                flag[right - '0'] = true;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!flag[i])
                root_key = i;
        }
        Node *root = create(root_key);
        bfs_traversal(root, n);
        in_traversal(root, n);
    }
    return 0;
}
