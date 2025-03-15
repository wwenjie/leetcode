#include<iostream>
#include<vector>

using namespace std;

// 找到前k小的数，并排好序

void findTopK(vector<int>& nums, int k, int l, int r);
int partition(vector<int>& nums, int l, int r);

int main() {
	vector<int> nums = {1,7,30,12,8,10,9,2,20,15,4};
	int k = 4;
	findTopK(nums, k, 0, nums.size());

	// for(int num:nums)
	// 	cout<<num<<endl;

	return 0;
}

void findTopK(vector<int>& nums, int k, int l, int r){
	if (l >= r) return;
	int p = partition(nums, l, r);
	if (p == k){
		cout<<"top "<< k+1<<" num is "<< nums[k]<<endl;
		for(int num: nums){
			cout<< num <<endl;
		}
	}
	else if (p < k)
		findTopK(nums, k, p+1, r);
	else
		findTopK(nums, k, l, p-1);
}

int partition(vector<int>& nums, int l, int r){
	if (l == r) return l;
	int idx = l;
	while(l < r) {
		while(l < r && nums[idx] < nums[r]){
			r--;
		}
		swap(nums[idx], nums[r]);
		idx = r;
		while(l < r && nums[idx] > nums[l]){
			l++;
		}
		swap(nums[idx], nums[l]);
		idx = l;
	}
	return idx;

}
