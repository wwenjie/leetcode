#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
#include <boost/lexical_cast.hpp>

using namespace std;

class TabInfo{
public:
	TabInfo(){}
	TabInfo(int n): tab_id(n) {
	}
	int tab_id = 0;
};
void cal(vector<TabInfo>& tab_list, map<int,int>& redis_map);

int main() {
	string s1= "1a23";
//	int n = boost::lexical_cast<int>(s1);
	cout<<atoi(string("sdf").c_str())<<endl;
	vector<TabInfo> tab_list = {TabInfo(11), TabInfo(22), TabInfo(33), TabInfo(44), TabInfo(55), TabInfo(66)};
	map<int, int> redis_map;
	redis_map[77] = 1;
	redis_map[33] = 2;
	redis_map[66] = 3;
	redis_map[44] = 4;
	redis_map[88] = 7;
	redis_map[11] = 10;

	for (auto& tab:tab_list){
		cout<<tab.tab_id<<" - "<<&tab<<endl;
	}
	cout<<" -----------------------------"<<endl;

	cal(tab_list, redis_map);

	// test 1-------->>>
	for (auto& tab:tab_list){
		cout<<tab.tab_id<<" - "<<&tab<<endl;
	}
	// test 2-------->>>
}

void cal(vector<TabInfo>& tab_list, map<int,int>& redis_map){

	map<int, TabInfo> tabid_2_info_map;
	vector<pair<int, int>> old_tabid_2_idx;		// tabid,idx
	vector<pair<int, int>> new_tabid_2_rank;	// tabid,rank
	for (int i=0;i<tab_list.size(); ++i) {
		int tab_id = tab_list[i].tab_id;
		if (redis_map.find(tab_id) == redis_map.end())
			continue;
		tabid_2_info_map[tab_id] = tab_list[i]; //copy
		old_tabid_2_idx.push_back(make_pair(tab_id, i));
		new_tabid_2_rank.push_back(make_pair(tab_id, redis_map[tab_id]));
	}
	

	sort(new_tabid_2_rank.begin(), new_tabid_2_rank.end(), [](pair<int,int>& a, pair<int,int>& b)->bool{
		return a.second < b.second;
	});

	for(int i=0; i<old_tabid_2_idx.size(); i++){
		if (old_tabid_2_idx[i].first != new_tabid_2_rank[i].first) {
			tab_list[old_tabid_2_idx[i].second] = tabid_2_info_map[new_tabid_2_rank[i].first];
		}
	}

}
