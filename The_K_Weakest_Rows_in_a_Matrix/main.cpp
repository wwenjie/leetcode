#include <iostream>
#include <vector>
#include <numeric>		//accumulate
#include <algorithm>	//sort函数

using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k); 

int main() {
	vector<vector<int>> ve = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
	int k= 3;
	vector<int> res = kWeakestRows(ve, k);
	for (int num: res)
		cout<<num<<endl;

	return 0;
}


vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    vector<pair<int, int>> sums;

    for(int i=0; i<m; i++){
        vector<int> row = mat[i];
        int acc = accumulate(mat[i].begin(), mat[i].end(), 0);
        sums.push_back(make_pair(acc, i));
    }

	// 冒泡k次
    for(int i=0; i<k; i++){
        for (int j=m-1; j>=1; j--){
            if (sums[j-1].first > sums[j].first) {
                swap(sums[j-1], sums[j]);
            }
            else if(sums[j-1].first == sums[j].first && sums[j-1].second > sums[j].second){
                swap(sums[j-1], sums[j]);
            }
        }
    }
	// 可用sort，但不是topK排序，复杂度较高
    //sort(sums.begin(), sums.end());

    vector<int> res;
    for (int i=0; i<k; i++)
        res.push_back(sums[i].second);
    return res;
}
