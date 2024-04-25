#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<int> value;
    TreeNode* levelConstruct(vector<int> value)
    {
        TreeNode* root = new TreeNode(0);
        queue<TreeNode*> tmp;

        tmp.push(root);
        for (int i : value) {
            TreeNode* cur_node = tmp.front();
            cur_node->left = new TreeNode();
            cur_node->right = new TreeNode();

            tmp.pop();
            if (i) {
                cur_node->val = i;
                tmp.push(cur_node->left);
                tmp.push(cur_node->right);
            }
            else {
                cur_node = NULL;
            }
        }
        return root;
    }

    vector<int> postTravel(TreeNode* root)
    {
        if (root == NULL)
            return { 0,0 };
        vector<int> left = postTravel(root->left);
        vector<int> right = postTravel(root->right);
        int val0 = max(left[0], left[1]) + max(right[0], right[1]); // 当前节点不偷时，值为 = max（左子树不偷， 左子树偷）+ max（右子树不偷，右子树偷）
        int val1 = root->val + left[0] + right[0]; // 当前节点偷时，值为 = 当前节点值 + 左子树不偷 + 右子树不偷
        return { val0, val1 };
    }

    int rob(TreeNode* root)
    {
        vector<int> dp = postTravel(root);
        return max(dp[0], dp[1]);
    }
};
int main()
{
    Solution so;
    struct TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(6);
    // root->left->left->left = new TreeNode(4);

    vector<int> nums = { 3,2,3,0,3,0,1,0,0,0,0 };
    // so.rob(root);
    cout << so.rob(root) << endl;
    return 0;
}