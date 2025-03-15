#include<iostream>
#include<vector>
#include<algorithm>

// 典型错误方法，cmp()就错了，反例[1,10],[2,3],[3,5]

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals); 
bool isOverlap(vector<int>& a, vector<int>& b);
static bool cmp(vector<int>& a, vector<int>& b);

int main() {
	vector<vector<int>> intervals = {{0,2},{1,3},{2,4},{3,5},{4,6}};
	vector<vector<int>> intervals = {{-52,31},{-73,-26},{82,97},{-65,-11},{-62,-49},{95,99},{58,95},{-31,49},{66,98},{-63,2},{30,47},{-40,-26}};
	int res = eraseOverlapIntervals(intervals);
	cout<<res<<endl;
	return 0;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    int ans = 0;
    int cur_idx = 0;
    for(int i=1; i<intervals.size(); i++){
		cout<<intervals[cur_idx][0]<<","<<intervals[cur_idx][1]<< "-----"<<intervals[i][0]<<","<<intervals[i][1]<<endl;
		cout<<isOverlap(intervals[cur_idx], intervals[i])<<endl;;
        if (isOverlap(intervals[cur_idx], intervals[i])){
            ans++;
        }
        else{
            cur_idx=i;
        }
		cout<<i<<", "<<ans<<", "<<cur_idx<<endl;
		cout<<endl;
    }
    return ans;
}

bool isOverlap(vector<int>& a, vector<int>& b){
    // a，b需要符合 cmp(a,b) == true
    if(a[1] > b[0])
        return true;
    return false;
}

static bool cmp(vector<int>& a, vector<int>& b){
    if (a[0] < b[0])
        return true;
    else if(a[0] == b[0])
        return a[1] < b[1];
    return false;
}
