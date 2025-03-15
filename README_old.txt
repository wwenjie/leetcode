# dp					
	动态规划

# knapsack_problem	
	背包问题

# scrolling_array
	滚动数组

# BestTimeToBuyAndSellStock	
	股票问题，1和2简单；3难，用动态规划+局部最优和全局最优解法
	第二次看12简单，3搞不定，写不出状态转移方程
	#TODO

# maximum_subarray
	53. 最大子序和
	动态规划，局部最优解和全局最优解法
	local[i] = max(local[i-1] + nums[i], nums[i])
	global[i] = max(global[i-1], local[i])

# Partition_Equal_Subset_Sum 
	分隔等和子集，动态规划

# Intersection_of_Two_Linked_Lists
	相交链表的相交节点

# Add_Strings
	数字字符串相加

# The_K_Weakest_Rows_in_a_Matrix
	排序topk，简单，用到swap，pair，accumulate，sort
	据说还可用topK快排，小根堆

# quick_sort
	快排，查找前k大的数

# Merge_Sorted_Array
	合并有序数组，简单题

# Next_Permutation
	下一个排列，考验找规律
# Merge_Intervals
	合并区间，先排序后合并比较简单
# pack_box
	打包箱子，微信面试的第5题
# Palindrome_Partitioning
	分割回文串，好难，回溯法，动态规划
# postorder_traversal
	二叉搜索树，后续遍历
# SubSets
	回溯dfs，凡是dfs递归都可以改成非递归
# Subsets II
	回溯，和上面类似
# Word_Search
	回溯dfs，递归
# Largest_Number
	贪心
# Unique_Binary_Search_Trees_II
	回溯，递归
# Unique_Binary_Search_Trees
	动态规划，递归
# Increasing_Subsequences
	回溯,有空看下它的循环数组优化
# Remove_Linked_List_Elements
	递归/迭代
# Remove_K_Digits
	贪心，栈，这题不会
# Remove_Duplicate_Letters
	贪心，单调栈，和上面做法几乎一样
# Increasing_Triplet_Subsequence
	334. 递增的三元子序列
	贪心，找规律
# Non-overlapping_Intervals
	435. 无重叠区间
	贪心O(nlogn)，动态规划O(n^2)
# Longest Palindrome
	409.最长回文串 
	贪心，简单
# Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal
	105. 从前序与中序遍历序列构造二叉树
	递归，通过前序和中序排列，不断找到左右子树的根节点，递归构造
# Reorder_List
	143. 重排链表
# Maximum_Product_Subarray
	152. 乘积最大子数组
	动态规划
	下次重写一遍 TODO
	再重做一遍局部最优和全局最优解的题
# Validate_Binary_Search_Tree
	98.验证二叉搜索树
	1递归，2中序遍历
# Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal
	106. 从中序与后序遍历序列构造二叉树
	1递归
	2迭代，自己写的，跟标准答案不一样。用到enum,stack,tuple
	笔记：任何递归都可以改用迭代实现
	跟前面105题差不多
# Network_Delay_Time
	743. 网络延迟时间
	迪杰斯特拉算法，单源最短路径算法
	云笔记总结了5种最短路径算法
# Compare_Version_Numbers
	165. 比较版本号
	法1：字符串处理
	法2：双指针
# Smallest_K_LCCI
	面试题 17.14. 最小K个数
	1排序，2堆，3快排
	用到priority_queue，srand()，rand()，time()
# NP问题是什么
	1. P问题，可用确定算法在多项式时间内判定和解决的问题。
	2. NP问题，一个问题的解可以在多项式时间证实或证伪，但不确定能否多项式时间找到答案，求解可能O(a^n),O(n!)阶乘的复杂度。
	如tsp问题，完全子图问题。
	目前没法证明P=NP，假设P=NP成立，那目前加密技术就没前途了。
	3. NPC问题，没有多项式复杂度解法，只能穷举法检验，比如围棋博弈问题，国际象棋n皇后问题，密码学大素数分解问题。
# 状态压缩动态规划
	将动态规划种状态数组进行压缩，利用位运算简化优化代码
# 记忆化搜索和dp
	记忆化搜素是自顶向下，dp是自底向上
# Climbing_Stairs
	70.跑楼梯
	easy，dp
# Word_Break
	139.单词拆分
	1. dp，Memoization(记忆化搜索)
	2. 字典树
	TODO，抄的，有空可以再写
	第二次做还是抄的
	2021.12.12第三次看，发现用dp很简单
# Integer_Replacement
	397. 整数替换
	1.dp，2.找规律,位运算 
# Can_I_Win
	464. 我能赢吗
	回溯，状态压缩，dp，记忆化搜索
# 不同算法区别，联系和适用情况
	分治法、动态规划法、贪心法、回溯法、分支限界法的区别、联系以及适用情况	
	https://blog.csdn.net/woniu0929/article/details/90576801
	important!!!!!
#  Find_Minimum_in_Rotated_Sorted_Array
	剑指 Offer 11. 旋转数组的最小数字
	二分查找
# LRU_Cache
	146. LRU 缓存机制
	unordered_map + 双向链表
# KMP算法
	TODO， 字符串匹配算法，O(n+m)时间复杂度实现字符串匹配
	Brute-Force传暴力算法则要O(nm)
# Valid_Parenthesis_String
	678. 有效的括号字符串
	1.dp    时间O(n^3),空间O(n^2)
	2.栈    时间O(n),空间O(n)
	3.贪心  时间O(n),空间O(1)
	# TODO，有空可以再做一次，涉及挺广的
# House_Robber
	198. 打家劫舍
	dp 滚动数组
# House_Robber_II
	213. 打家劫舍 II
	dp 滚动数组
# Wiggle_Sort_II
	324. 摆动排序 II
	法1：排序，中间分割为A和B，AB均反向（以保证A尾部和B头部相同的数不相邻），插入到摆动数组即可
		时间O(nlogn),空间O(n)
	法2：快速选择算法，将数组分为ABC3部分，A<中位数，B=中位数，C>中位数
		时间O(n),空间O(n)
	法3：没看，貌似复杂，时间O(n),空间O(1)
	TODO 不知道哪里写错了
# QuickSelect
	快速选择算法
	nth_element()
	vector<int>::iterator迭代器
# Arranging_Coins
	441. 排列硬币
	并查集，后缀数组(标签是这个，不过没看出来)
	等差数列求和
# Longest_Consecutive_Sequence
	128. 最长连续序列
	并查集
	unordered_set
# Surrounded_Regions
	130. 被围绕的区域
	并查集
	dfs、bfs
# Maximum_Length_of_Repeated_Subarray
	718. 最长重复子数组
	1.dp
	2.滑动窗口
	3.滚动哈希 TODO Rabin-Karp算法
# Longest_Duplicate_Substring
	1044. 最长重复子串
	TODO
	https://leetcode-cn.com/problems/longest-duplicate-substring/solution/zui-chang-zhong-fu-zi-chuan-by-leetcode/ Rabin-Karp算法解释的很好

# Repeated_DNA_Sequences
	187. 重复的DNA序列
	滑动哈希，Rabin-Karp算法
	unordered_set
	可以再看下标准答案的位运算
# Range_Addition_II
	598. 范围求和 II
	扫描线，简单，没看出来扫描线是什么算法技巧
# Subarray_Sum_Equals_K
	560. 和为 K 的子数组
	前缀和
# Map_Sum_Pairs
	677. 键值映射
	字典树
# Minimum_Size_Subarray_Sum
	209. 长度最小的子数组
	前缀和 + 二分查找
	滑动窗口
# Contains_Duplicate_II
	219. 存在重复元素 II
	滑动窗口，窗口内元素用哈希维护
# Valid_Palindrome
	125. 验证回文串
	双指针，或翻转后比较是否一样
	isalnum(),isdigit(),isalpha()
# Random_Flip_Matrix
	519. 随机翻转矩阵
	unordered_map，考察思路
# Pascals_Triangle
	118. 杨辉三角
	easy
	vector::resize()
# Longest_Valid_Parentheses
	32. 最长有效括号
	dp，难，抄的
	下次再做一次 TODO ！！！
# Longest_Increasing_Subsequence
	300. 最长递增子序列
	dp, O(n^2), TODO，再做一次
	贪心+二分查找, O(nlogn), TODO！！不会
# Counting_Bits
	338. 比特位计数
	easy,dp
	i%1 == i&1
# Target_Sum
	494. 目标和
	medium
	迭代，回溯
	dp, TODO!!
# Palindrome_Number
	9. 回文数
	easy
# Maximum_Depth_of_Binary_Tree
	104. 二叉树的最大深度
	easy,dfs,bfs
# Remove_Duplicates_from_Sorted_List
	83. 删除排序链表中的重复元素
	easy
# Single_Number
	136. 只出现一次的数字
	easy，异或
		a ^ 0 = a
		a ^ a = 0
		异或满足交换律
# Majority_Element
	169. 多数元素
	easy
	法1.unordered_map，
	法2.排序，取第n/2的元素
	法3.Boyer-Moore投票算法 
	(也有一个Boyer-Moore查找字符串算法，比KMP算法快5倍,GNU grep命令就是用该算法)
	引申：
		paper 分布式并行算法，找出多数元素
		http://www.crm.umontreal.ca/pub/Rapports/3300-3399/3302.pdf
# Same_Tree
	100. 相同的树
	https://leetcode-cn.com/problems/same-tree/
	easy, dfs, bfs
# 递归和回溯的区别：
    递归是算法结构，自己调用自己；
    回溯是算法思想，用递归来实现，回溯类似穷举，但回溯有剪枝功能。
    剪枝常用在dfs、bfs搜索算法中，剪枝策略是寻找过滤条件，减少不必要的搜索路径。
	剪枝算法按判断思路，分2大类：
		1.可行性剪枝，判断继续搜索能否得出答案，不能则直接回溯；
		2.最优性剪枝，又称上下界剪枝，记录当前最优值，如果当前节点已经无法产生更优解，提前回溯。
# Search_a_2D_Matrix_II
	240. 搜索二维矩阵 II
	medium
	1. 二分查找，时间log(m)*log(n)
	2. 从右上角开始查找，时间O(m+n) best
# Super_Egg_Drop
	887. 鸡蛋掉落
	hard
	dp, 不会，太TM难了
# Implement_Trie_Prefix_Tree
	208. 实现 Trie (前缀树)
	medium
	字典树
# Word_Search_II
	212. 单词搜索 II
	hard
	还没做，看了下答案
	1.字典树，同上
	2.删除被匹配的单词，没看
# Coin_Change
	322. 零钱兑换
	dp，完全背包问题
	这个题解比较好：
		https://leetcode-cn.com/problems/coin-change/solution/wan-quan-bei-bao-wen-ti-de-san-bu-you-hu-7oh8/
		刚开始答案跟我差不多，经过空间优化后，跟标准答案一样。
# Pow
	50. Pow(x,n)
	medium
	快速幂算法，递归，迭代
# Super_Pow
	372. 超级次方
	medium
	快速幂算法+迭代,数学
	取模满足分配律
        (a * b) % m = [(a % m) * (b % m)] % m
    指数计算也满足
        (a^b)^10 = a^(b*10) 
# Maximum_Average_Subarray_I
	643. 子数组最大平均数 I
	easy,滑动窗口
# Reverse_String_II
	541. 反转字符串 II
	easy，for(int i=0; i<n; i+=k),关键在于后面i+=k
# Student_Attendance_Record_I
	551. 学生出勤记录 I
	easy，没什么好说的
# Longest_Continuous_Increasing_Subsequence
	674. 最长连续递增序列
	easy，简单的让人绝望
# Assign_Cookies
	455. 分发饼干
	easy, 贪心
# Reverse_Bits
	190. 颠倒二进制位
	easy, 移位操作，O(logn)，还有一个O(1)的方法，有空看看 TODO
# K_Closest_Points_to_Origin
	973. 最接近原点的 K 个点
	medium
	priority_queue，最大堆，快速选择topk
# Sort_an_Array
	912. 排序数组
	medium
	合并排序，快排，其实很简单
# To_Lower_Case
	709. 转换成小写字母
	easy，但是根据ascii码的值，按位|=的方法值得抄一下
# Stock_Price_Fluctuation 
	2034. 股票价格波动
	medium
	multimap<int,int,greater<int>>
	TODO，本地跑正常，lc上跑溢出了
# 64_horse
	64匹马，8条赛道，不能记成绩，决出前4名，至少跑多少次
	10或11次
# Range_Sum_Query-Mutable
	307. 区域和检索 - 数组可修改
	medium
	线段树
# Number_of_Longest_Increasing_Subsequence
	673. 最长递增子序列的个数
	medium
	dp，还没做，TODO
	是"300.最长递增子序列"的进阶版本
# 树状数组 TODO!!!
# bigo
	bigo的面试题
	滑动窗口
# Next_Greater_Element_I
	496. 下一个更大元素 I
	单调栈
# Next_Greater_Element_II
	503. 下一个更大元素 II
	单调栈 medium
# Largest_Rectangle_in_Histogram
	84. 柱状图中最大的矩形
	单调栈，hard
# Maximal_Rectangle
	85. 最大矩形
	单调栈，hard，做法和84题差不多，在84题的基础上多了一维
# Trapping_Rain_Water
	42. 接雨水
	单调栈，hard
# 1-bit_and_2-bit_Characters
	717. 1比特与2比特字符
	easy
	法1 正序遍历，法2 倒序遍历找规律，法2没看
