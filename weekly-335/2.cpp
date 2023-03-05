/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long level(TreeNode *root, int k)
    {
        queue<TreeNode*>q;
        q.push(root);
        priority_queue<long long>pq;
        while(q.size())
        {
            int siz = q.size();
            long long sum = 0;
            for(int i = 0;i<siz;i++)
            {
                auto curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                sum += curr->val;
            }
            pq.push(sum);
        }
        if(k > pq.size()) return -1;
        for(int i = 0;i<k-1;i++)
        {
            pq.pop();
        }
        return pq.top();
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {

        return level(root, k);
    }
};