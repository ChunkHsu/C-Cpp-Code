//    1
//  2   3 
// 4 5
# include<iostream>
# include<vector>
# include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /*想着用两个队列来区分不同层的节点*/
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if(root == NULL)
            return ans;

        /*想着用两个队列来区分不同层的节点*/
        queue<TreeNode *> q1, q2, qnow;
        // qn的循环交替两个队列
        queue<queue<TreeNode *>> qn;
        vector<int> lv;
        // 根节点入队: 第一层
        q1.push(root);
        qn.push(q1);
        qn.push(q2);
        qnow = qn.front();
        while(!qnow.empty())
        {
            TreeNode* nowt = qnow.front();
            lv.push_back(nowt->val);
            // 当前节点的子节点放到下一层的队列中
            if(nowt->left)
                qn.back().push(nowt->left);
            if(nowt->right)
                qn.back().push(nowt->right);
            // 如果当前节点所在的队列没元素了
            // 那就进行下一层的队列
            qnow.pop();
            if(qnow.empty())
            {
                ans.push_back(lv);
                lv.clear();
                qn.pop();
                qn.push(qnow);
                qnow = qn.front();
            }
        }
        return ans;
    }
    /*计算每一层的节点数 n , 来循环一次处理一层的节点*/
    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> qNode;
        if(root == NULL)
            return ans;
        qNode.push(root);
        while(!qNode.empty())
        {
            int n = qNode.size();
            ans.push_back(vector<int> ()); //  vector<int> level;
            while(n--)
            {
                TreeNode* nowNode = qNode.front();
                qNode.pop();
                ans.back().push_back(nowNode->val); // level.push_back(nowNode->val);
                if(nowNode->left)
                    qNode.push(nowNode->left);
                if(nowNode->right)
                    qNode.push(nowNode->right);
            }
        }
        return ans;
    }
};

int main()
{
    TreeNode root1(1), root2(2), root3(3), root4(4), root5(5) ;
    root1.left = &root2;
    root1.right = &root3;
    root2.left = &root4;
    root2.right = &root5;

    Solution so;
    vector<vector<int>> nums = so.levelOrder2(&root1);
     for (const auto& subVec : nums) { // 遍历每个子向量
        for (int num : subVec) { // 遍历子向量中的每个整数
            std::cout << num << ' ';
        }
        std::cout << std::endl; // 每个子向量打印完毕后换行
    }
}