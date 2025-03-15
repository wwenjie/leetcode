#include<iostream>
#include<vector>
#include<queue>
#include <utility>

using namespace std;


void solve(vector<vector<char>>& board);
void bfs(vector<vector<char>>& board, vector<vector<bool>>& flag, int i, int j);

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> flag(m, vector<bool>(n, false));

    // 从边界开始广度优先搜索
    // bfs用队列，dfs用栈或递归

    // 1左右边界
    for(int i=0; i<m; i++){
        bfs(board, flag, i, 0);
        bfs(board, flag, i, n-1);
    }
    // 2上下边界
    for(int i=1; i<n-1; i++){
        bfs(board, flag, 0, i);
        bfs(board, flag, m-1, i);
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if (board[i][j] == 'O' && flag[i][j] == false){
                board[i][j] = 'X';
            }
        }
    }
}

void bfs(vector<vector<char>>& board, vector<vector<bool>>& flag, int i, int j){
		queue<pair<int, int>> q;
		q.push(make_pair(i, j));
		while(!q.empty()) {
			pair<int,int> p = q.front();
			q.pop();
			int i = p.first;
			int j = p.second;
			if (board[i][j] == 'X')
				continue;
			if (board[i][j] == 'O' && flag[i][j] == true)
				continue;
			flag[i][j] = true;

			if (i-1 >= 0)
				q.push(make_pair(i-1, j));
    		if (i+1 < board.size())
				q.push(make_pair(i+1, j));
    		if (j-1 >= 0)
				q.push(make_pair(i, j-1));
    		if (j+1 < board[0].size())
				q.push(make_pair(i, j+1));
		}
}

int main() {
	vector<vector<char>> board = {{'O', 'O'}, {'O', 'O'}};
	solve(board);
	for(int i=0; i<board.size(); i++) {
		for(int j=0; j<board[0].size(); j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
