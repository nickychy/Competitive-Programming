/*
Lowest Common Ancestor of a tree
                                1
                              / \
                              2  3
                                / \
                               4   6
                               /    \
                               5     7
                               /      \
                               9       8
        LCA of (9,8)=3
        LCA of(2,7)=1
*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        data = k;
        left = right = NULL;
    }
};
Node *lowestCommonAncestor(Node *root, int p, int q)
{
    if (root == NULL || root->data == p || root->data == q)
    {
        return root;
    }
    Node *leftTree = lowestCommonAncestor(root->left, p, q);
    Node *rightTree = lowestCommonAncestor(root->right, p, q);
    if (leftTree == NULL)
    {
        return rightTree;
    }
    else if (rightTree == NULL)
    {
        return leftTree;
    }
    else
    {
        return root;
    }
}
/*T.C O(N)
S.C O(N)*/
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right = new Node(60);
    root->left->right->left = new Node(70);
    root->left->right->left->right = new Node(70);
    Node *ans = lowestCommonAncestor(root, 20, 70);
    cout << ans->data;
    return 0;
}