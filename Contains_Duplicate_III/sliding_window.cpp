#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>

using namespace std;


int getPucketId(int num, long long wide);
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t); 

int main(){
	// vector<int> nums = {2,0,-2,2};
	// int k = 2, t = 1;
	vector<int> nums = {2147483647, -1, 2147483647};
	int k = 1, t = 2147483647;
	bool ans = containsNearbyAlmostDuplicate(nums, k, t);
	cout<<"ans--->> "<<ans<<endl;

	return 0;
}


// 法1：滑动窗口 + 窗口内二分查找 (略)
// 法2：滑动窗口 + 窗口内桶排序, 因为每个桶只能一个元素，所以hash表一个键值对表示一个桶
int getPucketId(int num, long long wide){
    // 获取桶id
    //      num = (t+1) * id + b, (0 <= b <= t)
    // (若t==INT_MAX，则wide溢出，所以wide类型是long, 下面1LL强转long long也是同理)
    // 桶的宽度 wide = t+1, 则t=9, wide=10
    //      num      id
    //   -10 ~ -1    -1
    //     0 ~ 9     0
    //    11 ~ 19    1
    return num >= 0 ? num / wide : (num + 1LL) / wide - 1;
}
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    unordered_map<int,int> mp;
    long long size = nums.size(); // 这里必须为long或long long，不然后面abs(-1-2147483647)依然== -2147483648 == INT_MIN
    for(int i=0; i<size; i++){
        int num = nums[i];
        int id = getPucketId(num, t + 1LL);
        // 一个桶只能有一个元素，否则返回true
        if(mp.count(id))
            return true;
        else if(mp.count(id-1) && abs(num - mp[id-1]) <= t)
            return true;
        else if(mp.count(id+1) && abs(num - mp[id+1]) <= t)
            return true;
        mp[id] = num;
        if(i >= k){
            int erase_id = getPucketId(nums[i-k], t+1LL);
            mp.erase(erase_id);
        }
    }
    return false;
}
