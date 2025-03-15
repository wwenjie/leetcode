#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals);
static bool cmp(const vector<int>& a, const vector<int>& b);

int main() {
	vector<vector<int>> intervals = {{1,2},{5,8}, {1,4}, {1,3}};

	//试一下这样写，是拷贝，还是引用
	//vector<int> temp = intervals[0];
	//temp[0] = 3;
	//cout<<temp[0]<<"-"<<temp[1]<<endl;

	auto res = merge(intervals);

	cout<<"sort -->"<<endl;
	for(auto ve : intervals) {
		cout<<ve[0]<<"-"<<ve[1]<<endl;
	}
	cout<<"merge -->"<<endl;
	for(auto ve : res) {
		cout<<ve[0]<<"-"<<ve[1]<<endl;
	}
	return 0;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty())
        return intervals;
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), cmp);

    vector<int> temp = intervals[0];

    res.push_back(temp);

    for(int i=1; i<intervals.size(); i++){
        int cnt = res.size()-1;
        if(res[cnt][1] >= intervals[i][0]) {
            if (res[cnt][1] <= intervals[i][1]) {
                res[cnt][1] = intervals[i][1];
            }
        }
        else{
            temp = intervals[i];
            res.push_back(temp);
        }
    }
    return res;
}

static bool cmp(const vector<int>& a, const vector<int>& b){
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}
