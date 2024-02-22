/*Diameter Of a Binary tree-- Longest Path between Any two Nodes
This path need not to be pass via root Node
                                1
                              / \
                              2  3
                                / \
                               4   6
                               /    \
                               5     7
                               /      \
                               9       8

Diameter of this tree will be 7 i.e( 9->5->4->3->6->7->8)
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

/*Naive Approach
Calculate  leftHeight and righHeight considering that every node as the curve point. CurrDiameter=leftHeight+righHeight
Max of all this will give the diameter of the tree
T.C O(N^2)*/
int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return max(height(root->left), height(root->right)) + 1;
}
int maxi = 0;
void Diameter_of_BT(Node *root)
{
    if (root == NULL)
        return;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    maxi = max(maxi, leftHeight + rightHeight);
    Diameter_of_BT(root->left);
    Diameter_of_BT(root->right);
}

//-------------------EFFICIENT SOLUTION--------------------------
/*Start traversing the tree recursively and do work in Post Order.
calculate diameter and height of the current node.
If current diameter is maximum then update the variable used to store the maximum diameter.
Return height of current node to the previous recursive call.*/
int diameterBT(Node *root, int &maxi2)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = diameterBT(root->left, maxi2);
    int right = diameterBT(root->right, maxi2);
    maxi2 = max(maxi2, left + right);
    return 1 + max(left, right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);
    root->right->left->left->left = new Node(9);
    root->right->right->right = new Node(7);
    root->right->right->right->right = new Node(8);
    Diameter_of_BT(root);
    cout << maxi << endl;
    int diameter = 0;
    diameterBT(root, diameter);
    cout << diameter;
    return 0;
}