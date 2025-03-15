#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

void wiggleSort(vector<int>& nums) {
    vector<int>::iterator mid_iter = nums.begin() + nums.size() / 2;
    nth_element(nums.begin(), mid_iter, nums.end());
    int mid_num = *mid_iter;

    // nth_element只保证mid_iter下标的值是中位数，需要3分法，把和mid_num相等值放中间

    // 3-way-partition 3分法
    // i指向<= mid_num的数
    // k指向>= mid_num的数
    // j用来遍历
    int i = 0, j = 0, k = nums.size() - 1;
    while(j < k){
        if(nums[j] < mid_num){
            swap(nums[j], nums[i]);
            i++;
            j++;
        }
        else if (nums[j] > mid_num){
            swap(nums[j], nums[k]);
            k--;
        }
        else
            j++;
    }

	cout<<"test ---->> "<<(mid_iter - nums.begin())<<endl;
    vector<int> tmp1(nums.begin(), mid_iter);
    vector<int> tmp2(mid_iter, nums.end());
	for(int n:nums)
		cout<<n<<",";
	cout<<endl;
	for(int n:tmp1)
		cout<<n<<",";
	cout<<endl;
	for(int n:tmp2)
		cout<<n<<",";
	cout<<endl;
    for(int i=0; i<tmp2.size(); i++){
        nums[2 * i] = tmp2[tmp2.size() - 1 - i];
		printf("nums[%d] = tmp2[%ld] = %d\n", 2*i, tmp2.size()-1-i, nums[2*i]);
	}
    for(int i=0; i<tmp1.size(); i++){
        nums[2 * i + 1] = tmp1[tmp1.size() - 1 - i];
		printf("nums[%d] = tmp1[%ld] = %d\n", 2*i+1, tmp1.size()-1-i, nums[2*i+1]);
	}
}

int main(){
	vector<int> nums = {1,2,2,1,2,2,1};
	//vector<int> nums = {1,5,1,1,6,4};

	wiggleSort(nums);
	cout<<endl;
	cout<<"nums:"<<endl;
	for(int n: nums){
		cout<<n;
	}
	cout<<endl;
	return 0;
}
