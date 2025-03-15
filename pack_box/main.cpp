#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void merge(vector<vector<int>>& boxes, vector<vector<int>>& res);
static bool cmp(vector<int>& a, vector<int>& b);

int main() {
	vector<vector<int>> boxes = {{1,2,5}, {2,3,4}, {1,3,4}, {3,4,5}};

	vector<vector<int>> res;

	merge(boxes, res);

	// 打印
	for(auto ve: res){
		for(auto num: ve){
			cout<<num<<" ";
		}
		cout<<endl;
	}

	return 0;
}

void merge(vector<vector<int>>& boxes, vector<vector<int>>& res){
	if (boxes.empty()) return;
	// 箱子翻转
	for(auto box: boxes) {
		sort(box.begin(), box.end());
	}

	// 排序
	sort(boxes.begin(), boxes.end(), cmp);
	//reverse(boxes.begin(), boxes.end());

	// 合并

	//for (int i=1; i<boxes.size(); i++) {
	for (auto box: boxes) {
		for (int i=0; i<res.size(); i++) {
			vector<int> temp = res[i];
			if(temp[0] <= box[0] && temp[1] <= box[1] && temp[2] <= box[2]) {
				//这么删除会不会有问题？
				auto it = res.begin() + i; 
				res.erase(it);
				break;
			}
		}
		res.push_back(box);
	}
}

// 2种思路，本题只能a
// a.从小到大排列
// b.从大到小排列
static bool cmp(vector<int>& a, vector<int>& b){
	if (a[0] == b[0]){
		if(a[1] == b[1]) {
			return a[2] <= b[2];
		}
		else{
			return a[1] < b[1];
		}
	}
	return a[0] < b[0];
}
