#include<iostream>
#include<vector>
#include<queue>

// 大根堆

using namespace std;

vector<int> smallestK(vector<int>& arr, int k);

int main() {
	vector<int> arr = {10,8,12,9,7,3,20};
	auto ans = smallestK(arr, 4);
	for(auto num : ans)
		cout<<num<<endl;

	return 0;
}


vector<int> smallestK(vector<int>& arr, int k){
	vector<int> ans(k);
	if(k == 0)
		return ans;
	priority_queue<int> heap; //大根堆
	
	// 插入前k个数到大根堆
	for(int i=0; i<k; i++){
		heap.push(arr[i]);
	}

	for(int i=k; i< arr.size(); i++){
		if(heap.top() > arr[i]){
			heap.pop();
			heap.push(arr[i]);
		}
	}

	for(int i=0; i<k; i++){
		ans[i] = heap.top();
		heap.pop();
	}
	return ans;
}
