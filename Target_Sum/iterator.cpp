// 自己写的迭代法
int findTargetSumWays(vector<int>& nums, int target) {
	int size = nums.size();
	vector<int> sum = {0};
	for(int i=0; i<size; i++){
		vector<int> tmp;
		int num = nums[i];
		for(int s: sum){
			tmp.push_back(s+num);
			tmp.push_back(s-num);
		}
		swap(sum, tmp);
	}
	int ans = 0;
	for(int n: sum){
		if (n == target)
			ans++;
	}
	return ans;
}
