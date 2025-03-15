#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void quicksort(vector<int>& nums, int l, int r);
int partition(vector<int>& nums, int l, int r);

int main() {
	vector<int> nums = {1,7,3,9,10,12,2};
	quicksort(nums, 0, nums.size());

	for(int num:nums)
	 	cout<<num<<endl;

	return 0;
}

void quicksort(vector<int>& nums, int l, int r){
	if (l >= r) return;
	int k = partition(nums, l, r);
	quicksort(nums, l, k-1);
	quicksort(nums, k+1, r);
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
