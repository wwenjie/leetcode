#include<iostream>
#include<map>
#include<vector>

using namespace std;

class A{
public:
	int num =0;
	A():num(0) {}
	A(int n):num(n) {}
};

int main() {
	vector<A> ve;
	A a;
	a.num=11;
	ve.push_back(a);
	
	map<int, A> m;
	for (auto& v: ve){
		m[v.num] = v;

	}
	cout<<m[11].num<<endl;
	return 0;
}
