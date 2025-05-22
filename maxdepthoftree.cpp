#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode * right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode * left, TreeNode*right): val(x), left(left), right(right){}
    
};
// solution 1: DFS
int maxDepth(TreeNode* root) {

    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// solution 2 : BFS
int maxDepth2(TreeNode* root)
{
    if(!root) return 0;
    int level = 0;
    queue<TreeNode*> q;

    if(root)
    {
        q.push(root);
    }

    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if(node->left)
            {
                 q.push(node->left);
            }

            if(node ->right)
            {
                q.push(node->right);
            }
        }
        level++;
    }

    return level;
}

int maxDepth3(TreeNode* root)
{
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    int res = 0;
    while(!st.empty())
    {
        pair<TreeNode*, int> cur = st.top();
        st.pop();
        TreeNode *curnode = cur.first;
        int depth = cur.second;

        if(curnode)
        {
            res = max(res, depth);
            st.push({curnode->left, depth + 1});
            st.push({curnode->right, depth + 1});
        }

    }

    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    

}