// 递归

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

unordered_map<int, int> index;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int size = inorder.size();
    for(int i=0; i<size; i++){
        index[inorder[i]] = i;
    }
    return buildTree(inorder, postorder, 0, size-1, 0, size-1);
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int in_left, int in_right, int post_left, int post_right){
    if (in_left > in_right)
        return nullptr;
    int root_val = postorder[post_right];
    int in_root_index = index[root_val];
    int left_tree_size = in_root_index - in_left;
    int right_tree_size = in_right - in_left + 1 - left_tree_size;
    TreeNode* left_tree = buildTree(inorder, postorder, 
            in_left, in_left + left_tree_size - 1, 
            post_left, post_left + left_tree_size - 1);
    TreeNode* right_tree = buildTree(inorder, postorder, 
            in_root_index + 1, in_right,
            post_left + left_tree_size, post_right-1);
    TreeNode* root = new TreeNode(root_val, left_tree, right_tree);
    return root;
}
