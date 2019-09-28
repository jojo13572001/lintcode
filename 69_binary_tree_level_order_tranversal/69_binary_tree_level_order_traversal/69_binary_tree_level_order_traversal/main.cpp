//
//  main.cpp
//  69_binary_tree_level_order_traversal
//
//  Created by Mac on 2019/9/29.
//  Copyright © 2019年 Mac. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/**
 * Definition of TreeNode:
 */
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
      this->val = val;
      this->left = this->right = NULL;
    };
};

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        queue<TreeNode*> levelNodes;
        vector<vector<int>> result;
        vector<int> levelResult;
        if (root == NULL) {
            return result;
        }
        levelNodes.push(root);
        levelNodes.push(NULL);
        
        while (levelNodes.size() != 0) {
            TreeNode* cur = levelNodes.front();
            levelNodes.pop();
            
            if (cur == NULL) {
                result.push_back(levelResult);
                levelResult.clear();
                if (levelNodes.size() !=0) {
                    levelNodes.push(NULL);
                }
            }
            else {
                levelResult.push_back(cur->val);
                if (cur->left) {
                    levelNodes.push(cur->left);
                }
                if (cur->right) {
                    levelNodes.push(cur->right);
                }
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
