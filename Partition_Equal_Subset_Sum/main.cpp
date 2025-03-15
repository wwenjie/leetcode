#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool canPartition(vector<int>& nums);

int main() {
	vector<int> nums = {1,5,11,5};
	bool res = canPartition(nums);
	cout<<res<<endl;
	return 0;
}

bool canPartition(vector<int>& nums){
	int size = nums.size();
    if (size == 0)
        return false;
    int sum = 0;
    for (int num : nums)
        sum += num;
    if (sum%2 == 1) 
        return false;
    sum /= 2;

    bool dp[size][sum+1];
    memset(dp, 0, sizeof(dp));

    if(nums[0] <= sum)
        dp[0][nums[0]] = true;

    memset(dp, 0, sizeof(dp));
    for (int i=1; i<size ; i++) {
        for (int j=0; j<=sum; j++){
            if (nums[i] > j){
                dp[i][j] = dp[i-1][j];
            }
            else if(nums[i] == j){
                dp[i][j] = true;
            }
            else{ // nums[i] < j
                dp[i][j] = dp[i-1][j- nums[i]] || dp[i-1][j];
            }
        }
    }
    return dp[size-1][sum];
}
