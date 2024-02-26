/*Given a tree Calculate the Maximum Path sum
path need not pass from the root. We need to find the path with the maximum sum in the binary tree.
*/
#include <bits/stdc++.h>
using namespace std;
/*Approach
Do a simple tree traversal. At each node, find  recursively its leftMaxPath and its rightMaxPath.
Calculate the maxPath & update maxi accordingly.
Return the maxPath  as val + max(leftMaxPath, rightMaxPath).
Ignore te left right path which gives negative sum as negative values will not maximize the ans.*/

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
int maxSum(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;
    // Calculate left  subtree's maxPath
    int ls = max(0, maxSum(root->left, maxi));
    // Calculate Right Subtree's maxPath
    int rs = max(0, maxSum(root->right, maxi));

    maxi = max(maxi, root->data + ls + rs);

    return root->data + max(ls, rs);
}
int main()
{

    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    int maxi = INT_MIN;
    maxSum(root, maxi);
    cout << maxi;

    return 0;
}