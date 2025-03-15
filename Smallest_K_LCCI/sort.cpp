#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> smallestK(vector<int>& arr, int k);

int main() {
	vector<int> arr = {10,8,12,9,7,3,20};
	auto ans = smallestK(arr, 4);
	for(auto num : ans)
		cout<<num<<endl;

	return 0;
}


vector<int> smallestK(vector<int>& arr, int k){
	sort(arr.begin(), arr.end());
	//vector<int> ans(arr.begin)
	return vector<int>(arr.begin(), arr.begin() + k);
}
