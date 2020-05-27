#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct node
{
    node *child[26];
    bool final;
    node()
    {
        memset(child, NULL, sizeof(child));
        final = false;
    }
};
node *root = new node();
char str[50];
char s[50000][50];

void insert(char *word)
{
    node *current = root;
    node *newNode;
    while (*word != '\0')
    {
        if (current->child[*word - 'a'] == NULL)
        {
            newNode = new node();
            current->child[*word - 'a'] = newNode;
        }
        current = current->child[*word - 'a'];
        word++;
    }
    current->final = true;
}
bool search(char *word)
{
    node *current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (current == NULL || current->child[word[i] - 'a'] == NULL)
        {
            return false;
        }
        current = current->child[word[i] - 'a'];
    }
    return current->final;
}
void del(node *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i] != NULL)
        {
            del(root->child[i]);
        }
    }
    delete root;
}
int main()
{
    int ans = 0;
    while (~scanf("%s", str))
    {
        strcpy(s[ans++], str);
        insert(str);
    }
    for (int i = 0; i < ans; i++)
    {
        int len = strlen(s[i]);
        for (int j = 1; j <= len - 1; j++)
        {
            char temp1[50] = {'\0'};
            char temp2[50] = {'\0'};
            strncpy(temp1, s[i], j);
            strncpy(temp2, s[i] + j, len - j);
            if (search(temp1) && search(temp2))
            {
                printf("%s\n", s[i]);
                break;
            }
        }
    }
    del(root);
    return 0;
}
