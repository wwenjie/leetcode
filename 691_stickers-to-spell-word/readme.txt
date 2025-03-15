法1 dfs.cpp         dfs + 记忆化搜索                   超时   500ms
法2 bfs.cpp         bfs + 记忆化搜索 + 状态压缩         成功   1.5ms
法3 dp.cpp          动态规划 + 状态压缩 （实际还是dfs）  成功   20ms
法4 dfs2_wrong.cpp  dfs + 记忆化搜索 + 状态压缩         错误   17ms      
    在法1的基础上改造，把vector<int> 状态 改成 int，耗时降了10倍，但是错误。
    错误原因是，不同层次上可能计算到相同的结果，而dfs在非最优的层次上记忆化了，后续用了非最优的记忆化结果
法5 dfs3.cpp        dfs + 记忆化搜索 + 状态压缩         成功但超时
     在法4基础上，把memo3[state] 改成 memo3[make_pair(cur_cnt, state)]