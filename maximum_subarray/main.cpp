#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int maxSubArray(vector<int>& nums);
int maxSubArray2(vector<int>& nums);

int main() {
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	int res1 = maxSubArray(nums);
	cout<<"res1: "<<res1<<endl;
	int res2 = maxSubArray2(nums);
	cout<<"res2: "<<res2<<endl;
	return 0;
}

/*
局部最优解：local[i] = max(local[i-1] + nums[i], nums[i]);
全局最优解：global[i] = max(local[i], global[i-1]);
*/
int maxSubArray(vector<int>& nums) {
    if (nums.empty())
        return 0;
    int size = nums.size();
    int global[size];
    int local[size];
    memset(global, 0, sizeof(global));
    memset(local, 0, sizeof(local));

    global[0] = nums[0];
    local[0] = nums[0];
    for(int i=1; i<size; i++){
        local[i] = max(local[i-1] + nums[i], nums[i]);
        global[i] = max(local[i], global[i-1]);
    }

    return global[size-1]; 
}

/*
空间优化：（滚动数组）
local = max(local + nums[i], nums[i])
global = max(local, global)
*/ 

int maxSubArray2(vector<int>& nums) {
    if (nums.empty()) return 0;
    int local = nums[0];
    int global = nums[0];
    for (int i=1; i<nums.size(); i++){
        local = max(local + nums[i], nums[i]);
        global = max(local, global);
    }
    return global;
}
