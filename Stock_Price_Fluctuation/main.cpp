#include<iostream>
#include<map>
using namespace std;

class StockPrice {
private:
    int cur_time = 0;
    int cur_price = 0;
    // 默认是less<int>，需要从大到小排，则加greater<int>
    multimap<int,int> map_price;// <price, time>，key可重复
    map<int, int> map_time;     // <time, price>, key唯一
public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        if (timestamp > cur_time){
            cur_time = timestamp;
            cur_price = price;
        }
        map<int,int>::iterator iter = map_time.find(timestamp);
        if (iter != map_time.end()){
            // 已存在
            map_time.erase(iter);
            map<int, int>::iterator begin, end;
            begin = map_price.lower_bound(iter->second);
            end = map_price.upper_bound(iter->second);
            while(begin != end){
                if (begin->second == iter->first){
                    map_price.erase(begin);
                    break;
                }
                else
                    begin++;
            }
        }
        map_time[timestamp] = price;
        map_price.insert(make_pair(price, timestamp));
    }
    
    int current() {
        return cur_price;
    }
    
    int maximum() {
        return map_price.rbegin()->first;
    }
    
    int minimum() {
        return map_price.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

 int main(){
	StockPrice* obj = new StockPrice();
	int ans;
	obj->update(1,10);
	obj->update(2,5);
 	int param_2 = obj->current();
	cout<<param_2<<endl;
 	int param_3 = obj->maximum();
	cout<<param_3<<endl;
	obj->update(1,3);
 	param_3 = obj->maximum();
	cout<<param_3<<endl;
	obj->update(4,2);
 	int param_4 = obj->minimum();
	cout<<param_4<<endl;
	return 0;
 }
