#include <bits/stdc++.h>
using namespace std;
/*Binary Tree --> tree which has atmost 2 children (0,1,2)
 */
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
/*TREE TRAVERSALS
                    10
                   /  \
                20     30
                /  \     \
                40  50    60
                    / \
                   70  80
lEVEL ORDER TRAVERSAL --> 10 20 30 40 50 60 70 80
DFS:
INORDER (left->root->right)    --> 40 20 70 50 80 10 30 60
PREORDER (root->left->right)   --> 10 20 40 50 70 80 30 60
POSTORDER (left->right->root)  --> 40 70 80 50 20 60 30 10
*/

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/*T.C O(N)
S.C O(height) */
void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

vector<vector<int>> levelOrderTraversal(Node *root)
{
    // Create a empty queue
    queue<Node *> q;
    vector<vector<int>> ans;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {

            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}

void print(vector<vector<int>> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
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
    root->left->right->right = new Node(80);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    vector<vector<int>> ans;
    ans = levelOrderTraversal(root);
    print(ans);
    return 0;
}