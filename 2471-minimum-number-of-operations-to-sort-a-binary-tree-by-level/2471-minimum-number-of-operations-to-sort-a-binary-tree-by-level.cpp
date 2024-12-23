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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int totalSwaps = 0;

        
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<int> levelValues(levelSize);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                levelValues[i] = node->val;

                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);
            }

           
            totalSwaps += getMinSwaps(levelValues);
        }
        return totalSwaps;
    }

private:
    
    int getMinSwaps(vector<int>& original) {
        int swaps = 0;
        vector<int> target = original;
        sort(target.begin(), target.end());

        
        unordered_map<int, int> pos;
        for (int i = 0; i < original.size(); i++) {
            pos[original[i]] = i;
        }

        
        for (int i = 0; i < original.size(); i++) {
            if (original[i] != target[i]) {
                swaps++;

                // Update position of swapped values
                int curPos = pos[target[i]];
                pos[original[i]] = curPos;
                swap(original[curPos], original[i]);
            }
        }
        return swaps;
    }
};