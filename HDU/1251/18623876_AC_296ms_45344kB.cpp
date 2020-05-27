#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct node
{
    node *child[26];
    int ans=0;
    bool final;
    node()
    {
        memset(child, NULL, sizeof(child));
        final = false;
    }
};
node *root = new node();
char str[50];
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
        current->ans++;
        word++;
    }
    current->final = true;
}
int search(char *word)
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
    return current->ans;
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
    while (gets(str))
    {
        if(strcmp(str,"")==0) break;
        insert(str);
    }
    while (~scanf("%s", str))
    {
        cout<<search(str)<<endl;
    } 
    del(root);
    return 0;
}
