#include<iostream>
#include<vector>

using namespace std;

bool verifyPostorder(vector<int>& postorder); 
bool isOK(vector<int>& a, int l, int r);

int main() {
	vector<int> postorder = {7, 4, 6, 5};
	bool res = verifyPostorder(postorder);
	cout<<res<<endl;
	return 0;
}

bool verifyPostorder(vector<int>& postorder) {
    int n = postorder.size();
    if (n<=2) return true;
    return isOK(postorder, 0, n-1);
}

bool isOK(vector<int>& a, int l, int r) {
    if(r-l <= 2)
        return true;
    int idx = 0;
    // 根节点是a[r]，所以找到第一个右子树的节点
    while(idx < r && a[idx] < a[r])
        ++idx;
    if (idx== r)
        // 没有右子树
        return isOK(a, l, r-1);
    else {
        // 检查右子树是否符合要求
        for(int i= idx+1; i<= r-1; ++i){
            // idx ~ r-1之间的元素必须全大于a[r]
            if(a[i] < a[r])
                return false;
        }
    }
    // 检查左子树 && 右子树
    return isOK(a, l, idx-1) && isOK(a, idx, r-1);
}
