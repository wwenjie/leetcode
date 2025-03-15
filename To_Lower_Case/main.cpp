// https://leetcode-cn.com/problems/to-lower-case/


// 1 值得一抄
// A~Z  65~90
// a~z  97~122
string toLowerCase(string s) {
    for (char& ch: s) {
        if (ch >= 65 && ch <= 90) {
            ch |= 32;
        }
    }
    return s;
}


// 2 正常easy
string toLowerCase(string s) {
    for(auto& ch: s){
        ch = tolower(ch);
    }
    return s;
}

// 3 朴实easy
string toLowerCase2(string s) {
    string ans = s;
    for(auto& ch: ans){
        char n = ch - 'A';
        if (0 <= n && n < 26){
            ch = ch - 'A' + 'a';
        }
    }
    return ans;
}
