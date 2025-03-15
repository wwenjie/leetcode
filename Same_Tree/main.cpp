// dfs, 执行时间4ms，超过51%
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr)
        return true;
    else if (p == nullptr || q == nullptr)
        return false;
    else if(p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


// bfs, 执行时间0ms，超过100%
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==nullptr && q==nullptr)
        return true;
    else if(p==nullptr || q==nullptr)
        return false;
    else if(p->val != q->val)
        return false;
    
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(p);
    q2.push(q);
    TreeNode* node1;
    TreeNode* node2;
    while(q1.size() > 0 && q2.size() > 0){
        node1 = q1.front();
        node2 = q2.front();
        q1.pop();
        q2.pop();
        
        // 左子树
        if (node1->left && node2->left) {
            if (node1->left->val != node2->left->val)
                return false;
            q1.push(node1->left);
            q2.push(node2->left);
        }
        //else if ((!node1->left && node2->left) || (node1->left && !node2->left)){
        else if ((node1->left == nullptr) ^ (node2->left == nullptr)){
            return false;
        }
        // 右子树
        if (node1->right && node2->right){
            if (node1->right->val != node2->right->val)
                return false;
            q1.push(node1->right);
            q2.push(node2->right);
        }
        //else if((!node1->right && node2->right) || (node1->right && !node2->right)){
        else if ((node1->right == nullptr) ^ (node2->right == nullptr)){
            return false;
        }
    }

    return q1.size() == q2.size() ? true: false;
}
