139. 单词拆分
https://leetcode-cn.com/problems/word-break/

思路：
	1.dp，记忆化搜素
		bool wordBreak(string s, vector<string>& wordDict)
		把wordDict放到unordered_set里（记忆化）
		maxLen = wordDict中的最长字符串的长度
		vector<bool> dp
		for(end = 1 .. s.size())
			for(start = end-1 .. end-maxLen)
				if(dp[start] && s[start .. end] in wordDict)
					dp[end] = true;
					break
	2.字典树

抄的，有空再写一遍
leetcode上max()为啥报错

2021.12.12重新看，发现用dp很简单
