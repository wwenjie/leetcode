#include<iostream>
#include<vector>

using namespace std;

vector<vector<string>> partition(string s);
void huiwen(string s, int idx, vector<vector<string>> &res, vector<string> &temp, vector<vector<int>> &strHuiwen);
bool isHuiwen(string s);

int main() {
    string s = "aabcb";
    vector<vector<string>> res;
    
    res = partition(s);
    for (auto ve: res){
        for(string st: ve){
            cout<<st<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<vector<int>> strHuiwen(s.length(), vector<int>(s.length(), 0));
    vector<string> temp;
    // 这里计算出所有回文串
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            if (isHuiwen(s.substr(i, j - i + 1)))
                strHuiwen[i][j] = 1;
        }
    }
    // 这里进行组合
    huiwen(s, 0, res, temp, strHuiwen);
    return res;
}

void huiwen(string s, int idx, vector<vector<string>> &res, vector<string> &temp, vector<vector<int>> &strHuiwen)
{
    if (idx == s.length())
    {
        res.push_back(temp);
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        if (strHuiwen[idx][i])
        {
            temp.push_back(s.substr(idx, i - idx + 1));
            huiwen(s, i + 1, res, temp, strHuiwen);
            temp.pop_back();
        }
    }
}

bool isHuiwen(string s)
{
    for (int i = 0; i < s.length() / 2; i++)
        if (s[i] != s[s.length() - i - 1])
            return false;
    return true;
}
