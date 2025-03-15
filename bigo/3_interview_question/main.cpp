/*
	bigo 3面的算法题
	滑动窗口
*/

#include<iostream>
#include<vector>
using namespace std;
int MaximumCopy(const std::vector<int> &s, int C, int &start_index, int &end_index);

int main(){
	vector<int> s = {1,2,3,4,5};
	int C = 7;
	int start_index = -1;
	int end_index = -1;
	int ans = MaximumCopy(s, C, start_index, end_index);
	cout<<"ans: "<<ans<<endl;
	cout<<"start_index: "<<start_index<<endl;
	cout<<"end_index: "<<end_index<<endl;
	return 0;
}

int MaximumCopy(const std::vector<int> &s, int C, int &start_index, int &end_index){	
	int n = s.size();
	int left = 0;
	int right = 0;
	int ans = 0;
	int tmp = 0;
	while(left < n && right < n) {
		tmp = 0;
		for(int i=left; i<=right; i++){
			tmp += s[i];
		}
		if (tmp <= C){
			if (tmp > ans){
				ans = tmp;
				start_index = left;
				end_index = right;
			}
			right++;
		}
		else{
			left++;	
		}
		
	}
	return ans;
}
