//POJ 1056 IMMEDIATE DECODABILITY
//就是看有没有字符串是另一个的前缀
//立即码(也叫异前置码)

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX = 2;
typedef struct Trie_Node
{
    bool isCode;
    struct Trie_Node *next[MAX];
} Trie;
bool flag;

void insert(Trie *root, char *str)
{
    Trie *p = root;
    int i = 0;
    while (str[i] != '\0')
    {
        if (p->next[str[i] - '0'] == NULL)
        {
            Trie *temp = new Trie;
            for (int j = 0; j < MAX; j++)
                temp->next[j] = NULL;
            temp->isCode = false;
            p->next[str[i] - '0'] = temp;
        }
        else
        {
            if (p->next[str[i] - '0']->isCode)
            {
                flag = false;
                return;
            }
        }
        p = p->next[str[i] - '0'];
        i++;
    }
    p->isCode = true;
}
void del(Trie *root)
{
    for (int i = 0; i < MAX; i++)
        if (root->next[i] != NULL)
            del(root->next[i]);
    free(root);
}
int main()
{
    char str[20];
    int iCase = 0;
    while (scanf("%s", &str) != EOF)
    {
        iCase++;
        Trie *root = new Trie;
        for (int i = 0; i < MAX; i++)
            root->next[i] = NULL;
        root->isCode = false;
        flag = true;
        insert(root, str);
        while (scanf("%s", &str))
        {
            if (strcmp(str, "9") == 0)
                break;
            if (flag)
                insert(root, str);
        }
        if (flag)
            printf("Set %d is immediately decodable\n", iCase);
        else
            printf("Set %d is not immediately decodable\n", iCase);
        del(root);
    }
    return 0;
}