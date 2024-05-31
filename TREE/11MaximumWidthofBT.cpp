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

int maxWidth(Node *root)
{

    if (!root)
        return 0;
    long long ans = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        long long minidx = q.front().second;
        long long first = 0, last = 0;
        for (int i = 0; i < size; i++)
        {
            long long curridx = q.front().second - minidx;
            Node *temp = q.front().first;
            q.pop();
            if (i == 0)
                first = curridx;
            if (i == size - 1)
                last = curridx;
            if (temp->left)
            {
                q.push({temp->left, 2 * curridx + 1});
            }
            if (temp->right)
            {
                q.push({temp->right, 2 * curridx + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}
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
    root->right->right->right->right = new Node(80);
    cout << "Maximum Width of Binary Tree is " << maxWidth(root);
    return 0;
}