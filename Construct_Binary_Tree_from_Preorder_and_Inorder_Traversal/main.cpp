#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder); 
TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right);

int main() {
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};
	buildTree(preorder, inorder);
	return 0;
}

// 中序遍历，值->下标
unordered_map<int, int> in_index;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int size = inorder.size();
	for(int i=0; i<size; i++){
		in_index[inorder[i]] = i;
	}
	return myBuildTree(preorder, inorder, 0, size-1, 0, size-1);
}

TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
	if (pre_left > pre_right)
		return nullptr;
	// 根节点值
	int root_val = preorder[pre_left];
	// 前序遍历的根节点下标
	int in_root_idx = in_index[root_val];
	// 左子树节点数
	int size_left_tree = in_root_idx - in_left;
	TreeNode* left = myBuildTree(preorder, inorder, 
								pre_left+1, pre_left+size_left_tree,
								in_left, in_root_idx-1);
	TreeNode* right = myBuildTree(preorder, inorder,
								pre_left+1+size_left_tree, pre_right,
								in_root_idx+1, in_right);

	TreeNode* root = new TreeNode(root_val, left, right);
	return root;
}
