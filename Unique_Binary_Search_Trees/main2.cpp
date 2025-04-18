#include<iostream>
#include<vector>

using namespace std;

int numTrees(int n);

int main() {
    int n = 3;
    int res = numTrees(n);
    cout<<res<<endl;
    return 0;
}

int numTrees(int n) {
	vector<int> G(n+1, 0);
	G[0] = 1;
	G[1] = 1;
	for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++) {
            G[i] += G[j-1] * G[i-j];
        }
	}
	return G[n];
}
