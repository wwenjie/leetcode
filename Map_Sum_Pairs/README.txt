677. 键值映射
https://leetcode-cn.com/problems/map-sum-pairs/

最优法：字典树
	n是key长度，m是键值对数目，c是常数
	
	时间复杂度：
		insert() O(n)
		sum()	 O(n)

	空间复杂度： O(cnm) 
	
法2：将每个insert的字符串的前缀加到hash里
	n是key长度，m是键值对数目

	时间复杂度：
		insert() O(n^2)，将长度为n的key的所有前缀都插入插入哈希表中
		sum()	 O(1)

	空间复杂度：
		O(nm)

法3：insert插入哈希表，sum遍历所有key
	
	时间复杂度：
		insert() O(1)
		sum()	 O(nm)
	空间复杂度：
		O(nm)

