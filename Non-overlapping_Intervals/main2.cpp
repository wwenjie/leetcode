#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals); 

int main() {
	//vector<vector<int>> intervals = {{0,2},{1,3},{2,4},{3,5},{4,6}};
	vector<vector<int>> intervals = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}}; //正确答案8
	int res = eraseOverlapIntervals(intervals);
	cout<<res<<endl;
	return 0;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
		return a[1] < b[1];
	});
	int size = intervals.size();
	int right = intervals[0][1];
    int need = 0;
    for(int i=1; i<size; i++){
		if (right <= intervals[i][0]){
			need++;
			right = intervals[i][1];
		}
    }
    return size - need;
}

