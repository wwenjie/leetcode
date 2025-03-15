#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int small = INT_MAX, mid = INT_MAX;
    for(int num: nums) {
        if (num > mid) {
            return true;
        }
        else if (small < num && num < mid){
            mid = num;
        }
        else if ( num < small){
			// trick在这里，num在mid后面，为啥可以替换small，想想就明白了
            small = num;
        }
    }
    return false;
}

int main() {
	vector<int> nums = {2,1,5,0,4,6};
	bool res = increasingTriplet(nums);
	cout<<res<<endl;
	return 0;
}
