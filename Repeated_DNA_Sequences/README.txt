187. 重复的DNA序列
https://leetcode-cn.com/problems/repeated-dna-sequences/

法1：rabin_karp.cpp:

	滑动哈希 Rabin Karp算法

	unordered_map umap;
	if (++umap[num] == 2){   
		// 相当于,
		// 若umap[num]不存在则赋值0，再++变为1，再判断是否==2
		// 若umap[num]存在，则++，再判断是否==2
		...
	}

法2：hash.cpp
	简单哈希
