#include<iostream>
#include<vector>

using namespace std;

bool exist(vector<vector<char>>& board, string word);
bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& step, int idx, int i, int j);

int main() {
	vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	string word("ABCCED");
	bool res = exist(board, word);
	cout<<res<<endl;
	return 0;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
	// 可优化成在board上修改字符，以记录路径
    vector<vector<bool>> step(m, vector<bool>(n, false));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            bool res = dfs(board, word, step, 0, i, j);
            if (res) return true;
        }
    }
    return false;
}

bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& step, int idx, int i, int j){
    if (idx >= word.length()) return true;
    if(i < 0 || i >= board.size()) return false;
    if(j < 0 || j >= board[0].size()) return false;
    if (step[i][j]) 
        return false;
    if (board[i][j] != word[idx])
        return false;
    step[i][j] = true;
    idx++;

    bool res = dfs(board, word, step, idx, i-1, j) || 
            dfs(board, word, step, idx, i+1, j) ||
            dfs(board, word, step, idx, i, j-1) ||
            dfs(board, word, step, idx, i, j+1);
    if (!res) 
        step[i][j] = false;
    return res;
}
