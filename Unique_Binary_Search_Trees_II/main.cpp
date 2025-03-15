#include<iostream>
#include<vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> generateTrees(int n);
vector<TreeNode*> generateTrees(int start, int end);

int main() {
	int n = 2;
	vector<TreeNode*> res = generateTrees(n);

	for (TreeNode* node: res) {
		cout<<&node<<endl;
	}
	cout<<"-----"<<endl;
	for (auto node: res) {
		cout<<&node<<endl;
	}
	cout<<"-----"<<endl;
	for (auto* node: res) {
		cout<<&node->val<<endl;
	}
	cout<<"-----"<<endl;
	for (auto& node: res) {
		cout<<&node->val<<endl;
	}
	return 0;
}

vector<TreeNode*> generateTrees(int n) {
	if (n == 0)
		return {};
	return generateTrees(1, n);
}

vector<TreeNode*> generateTrees(int start, int end) {
	if (start > end) {
		return {nullptr};
	}
	vector<TreeNode*> res;
	for(int i=start; i<=end; i++) {
		vector<TreeNode*> left = generateTrees(start, i-1);
		vector<TreeNode*> right = generateTrees(i+1, end);
		
		for(TreeNode* l: left) {
			for (TreeNode* r: right) {
				TreeNode* head = new TreeNode(i);
				head->left = l;
				head->right = r;
				res.emplace_back(head);
				// res.push_back(head);
				// TODO 这里用这个都一样吧，保存的只是指针
			}
		}
	}
	return res;
}
