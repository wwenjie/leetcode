#include<iostream>
#include<stack>
#include<vector>
#include<tuple>
#include<unordered_map>

// 自己根据递归法，改的栈迭代法，跟标准答案不一样，NB！

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

enum sub_tree_type {
    NotSubTree = 0,
    LeftSubTree = 1,
    RightSubTree = 2,
};

unordered_map<int, int> in_index;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    std::stack<std::tuple<TreeNode*, sub_tree_type, int,int,int,int>> stk;
    int size = inorder.size();
    for(int i=0;i<size; i++){
        in_index[inorder[i]] = i;
    }
    //int root_val = postorder[size-1];
    //TreeNode* root = new TreeNode(root_val);
    TreeNode* root = nullptr;
    stk.push(std::make_tuple(nullptr, NotSubTree, 0, size-1, 0, size-1));
    
    while(!stk.empty()) {
        tuple<TreeNode*, sub_tree_type, int,int,int,int> tup = stk.top();
        stk.pop();
        TreeNode* parent = std::get<0>(tup);
        sub_tree_type typ = std::get<1>(tup);
        int in_left = std::get<2>(tup);
        int in_right = std::get<3>(tup);
        int post_left = std::get<4>(tup);
        int post_right = std::get<5>(tup);

        if(in_left > in_right)
            continue;

        int node_val = postorder[post_right];
        int in_node_index = in_index[node_val];
        int left_tree_size = in_node_index - in_left;

        TreeNode* node = new TreeNode(node_val);
        if (parent)
            if (typ == LeftSubTree)
                parent->left = node;
            else
                parent->right = node;
        else
            root = node;
        
        auto left = make_tuple(node, LeftSubTree, in_left, in_left + left_tree_size - 1, 
                post_left, post_left + left_tree_size - 1);
        auto right = make_tuple(node, RightSubTree, in_node_index + 1, in_right, 
                post_left + left_tree_size, post_right - 1);
        stk.push(left);
        stk.push(right);
    }

    return root;
}

int main() {
	vector<int> inorder = {9,3,15,20,7};
	vector<int> postorder = {9,15,7,20,3};
	auto root = buildTree(inorder, postorder);
	return 0;
}
