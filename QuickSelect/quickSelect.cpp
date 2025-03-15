#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 用法和nth_element()一样
// 下标为 begin+n的元素，为第n+1小的元素
void quickSelect(vector<int> &nums, int begin, int end, int n){
	int t = nums[end]; // 可优化成随机,不会再数组原本逆序的情况出现最差情况
	int i = begin, j = begin;
	// i指向最前面比t大的数
	// j用来遍历
	while(j < end) {
		if(nums[j] <= t){
			swap(nums[i], nums[j]);
			i++;
		}
		j++;
	}
	swap(nums[i], nums[end]);
	if(i == n)
		return;
	else if(i > n)
		quickSelect(nums, begin, i-1, n);
	else if(i < n)
		quickSelect(nums, i, end, n);

}

int main(){
	//vector<int> nums = {7,2,1,4,8,9,5,3};
	vector<int> nums = {6, 3,4,5,1,3,3,3};
	vector<int> nums2 = nums;
	int k = 3;
	cout<<"k = "<<k<<endl;

	nth_element(nums.begin(), nums.begin()+k, nums.end());
	quickSelect(nums2, 0, nums2.size()-1, k);

	for(int i=0; i< nums.size(); i++){
		cout<<nums[i]<<"--"<<nums2[i]<<endl;
	}
	cout<<"--->>"<<(*nums.begin())<<endl;

	//试下通过iter拷贝vector
	vector<int> nums3(nums.begin(), nums.begin()+2);
	for(int i=0; i< nums3.size(); i++){
		cout<<nums3[i]<<endl;
	}
	return 0;
}
