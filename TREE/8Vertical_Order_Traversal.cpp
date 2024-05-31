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
vector<vector<int>> verticalTraversal(Node *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        Node *temp = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(temp->data);
        if (temp->left)
        {
            todo.push({temp->left, {x - 1, y + 1}});
        }
        if (temp->right)
        {
            todo.push({temp->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> res;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        res.push_back(col);
    }
    return res;
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

    return 0;
}