leetcode: 
	179. Largest Number
	https://leetcode-cn.com/problems/largest-number/

参考：
	https://blog.csdn.net/gao1440156051/article/details/51763347
	几乎没参考，思路基本一样

思路：
	贪心算法

笔记：
	1.
	vector<string> ve = {"aa", "bb"};
	for(string st: ve) 和 for(auto st: ve) 是一样的，要拷贝string
	for(string& st: ve) 是取引用，不用拷贝

	2.
	string 比较，逐个字符按ascii值比较大小

	3.
	string st，st[0] 取的是char字符

	4.
	如果一开始知道vector大小
	先vector<string> ve(len),再for循环给ve[i]赋值
	比一直ve.push_back()要好

TODO：
	不知大为什么51行cmp()，return a>=b; 会有奇怪报错。
	gdb调试crash日志如下


```
	Breakpoint 1, cmp (a="0", b="0") at main.cpp:48
	48          string ab = a+b;
	(gdb) c
	Continuing.
	
	Breakpoint 1, cmp (a="0", b="0") at main.cpp:48
	48          string ab = a+b;
	(gdb) c
	Continuing.
	
	Breakpoint 1, cmp (
	    a=<error reading variable: Cannot create a lazy string with address 0x0, an d a non-zero length.>, b="0") at main.cpp:48
	48          string ab = a+b;
	(gdb) c
	Continuing.
	terminate called after throwing an instance of 'std::logic_error'
	  what():  basic_string::_M_construct null not valid
	
	Program received signal SIGABRT, Aborted.
	__GI_raise (sig=sig@entry=6) at ../sysdeps/unix/sysv/linux/raise.c:50
	50      ../sysdeps/unix/sysv/linux/raise.c: No such file or directory.
```


