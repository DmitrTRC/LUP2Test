//
// Created by Dmitry Morozov on 15/1/23.
//

#include <iostream>
#include <queue>
#include <vector>


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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {

        std::vector<std::vector<int>> res_vec;

        if (root == nullptr) return res_vec;

        std::queue<TreeNode *> nodeQ;

        nodeQ.push(root);

        bool lr_flag = true;

        while (not nodeQ.empty()) {

            int current_size = nodeQ.size();

            std::vector<int> layer;

            while (current_size--) {
                TreeNode *node = nodeQ.front();
                nodeQ.pop();
                layer.push_back(node->val);
                if (node->left) nodeQ.push(node->left);
                if (node->right) nodeQ.push(node->right);

            }

            if (not lr_flag) {
                std::reverse(layer.begin(), layer.end());

            }

            lr_flag = !lr_flag;
            res_vec.push_back(layer);

        }


        return res_vec;
    }

};

