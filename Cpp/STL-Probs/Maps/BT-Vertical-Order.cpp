#include <iostream>

#include <algorithm>

#include <stack>

#include <vector>

#include <queue>

#include <map>

#include <unordered_map>

#include <string>

#include <set>

using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define MapVecit(it) map<int, vector<int>>::iterator it

struct Node
{
    int key;
    Node *left, *right;
};

Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void getVerticalOrder(Node *root, int hdis, map<int, vi> &m)
{
    if (root == NULL)
    {
        return;
    }
    m[hdis].push_back(root->key);
    getVerticalOrder(root->left, hdis - 1, m);
    getVerticalOrder(root->right, hdis + 1, m);
}

int main()
{
    Node *root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(4);

    root->left->left = newNode(3);
    root->left->right = newNode(11);

    root->right->left = newNode(14);
    root->right->right = newNode(6);

    /*
            10
           /  \
        7       4
       / \     / \
    3      11 14  6
    */

    map<int, vi> m;
    // Horizontal distace if vertical arrangement is considered:
    int hdis = 0;

    getVerticalOrder(root, hdis, m);

    MapVecit(it);
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < (it->second).size(); i++)
        {
            cout << (it->second)[i] << "  ";
        }
        cout << endl;
        // cout << it->first << "  " << it->second << " " << endl;
    }

    return 0;
}

/*

For Input:
Node *root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(4);

    root->left->left = newNode(3);
    root->left->right = newNode(11);

    root->right->left = newNode(14);
    root->right->right = newNode(6);


Output :
3
7
10 11 14
4
6


Reason:
      2  1     0    -1  -2
      '   '    10   '   '
      '   '  /   \  '   '
      '   7        4    '
      '  / \      /  \  '
      3      11 14     6


*/