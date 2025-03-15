#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>

using namespace std;

// 用快排思想

vector<int> smallestK(vector<int>& arr, int k);
void rand_select(vector<int>& arr, int k, int left, int right);
int rand_partition(vector<int>& arr, int left, int right);

int main() {
	vector<int> arr = {10,3,12,9,7,8,20};
	auto ans = smallestK(arr, 4);
	for(auto num : ans)
		cout<<num<<endl;

	return 0;
}


vector<int> smallestK(vector<int>& arr, int k){		
	// 不随机化种子，每次重新执行，rand()随机的数的顺序是一样的
	srand((unsigned)time(nullptr));
	rand_select(arr, k, 0, arr.size()-1);
	return vector<int>(arr.begin(), arr.begin() + k);
}

void rand_select(vector<int>& arr, int k, int left, int right){
	if (left >= right)
		return;
	int pivot = rand_partition(arr, left, right);
	int num = pivot - left + 1;
	if (num == k)
		return;
	else if(num > k)
		rand_select(arr, k, left, pivot-1);
	else
		rand_select(arr, k-num, pivot+1, right);
}

int rand_partition(vector<int>& arr, int left, int right){
	// 随机一个下标做pivot，防止本来顺序的arr将算法退化成O(n^2)
	int pivot = rand() % (right - left + 1) + left;
	swap(arr[pivot], arr[right]);
	
	int idx = left; //idx指向比right大的数
	for(int i=left; i<=right-1; i++){
		if (arr[i] > arr[right])
			continue;
		swap(arr[i], arr[idx]);
		idx++;
	}
	// 最后idx指向的数比right的大，交换
	swap(arr[idx], arr[right]);
	return idx;
}
