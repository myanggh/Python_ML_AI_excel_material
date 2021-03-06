/*

为了帮助大家理解本题贪心和动态规划的区别，
下面给出一个例子加以说明。

有一个3*3的方格，每个格子有一个正整数，
规定从左下角出发，每次只能向上或向右移动一格，
现在要求找出一条路径使得从左下角到达右上角所经过的格子中的数字之和最大，
求最大值。

20   9   8
 6   7   5
 3  14  12

贪心：一直选择局部最优解
3→14→12→5→8=42

最优解：3→6→20→9→8=46

如果是动态规划，会怎么做
动态规划是全局的找规律，
这个规律就是对于一个格子，只有向上和向右可以到达它，
通过这个规律，思考状态和状态转移方程
状态：f[i][j]表示走到第i行第j列位置的路径数字和的最大值
状态转移方程：
f[i][j]=max(f[i-1][j] , f[i][j-1])+a[i][j]
f[i-1][j]表示向上走
f[i][j-1]表示向右走

而对应到本题中
贪心只是考虑到了当前对于a[i]最优的情况，
是选择s[i-1]还是不选择s[i-1]来得到局部最优解

动态规划却是在全局的基础上，
找到了规律：
以第i个数结尾的最大连续子序列的和，只存在两种选择：
情形1：只包含a[i]
情形2：包含a[i]和以a[i-1]结尾的最大连续和序列

通过规律设置好了状态，找到状态转移的方程
状态：f[i]表示以第i个元素结尾的子序列的最大值 
状态转移方程：f[i]=max(f[i-1]+n[i],n[i]) (2<=i<=n)
本题解：Answer=max{f[i]|1<=i<=n}

总结：
最大字段和的贪心解法就是只考虑当前对于a[i]最优的情况，是选择s[i-1]还是不选择s[i-1]来得到局部最优解
最大字段和的动态规划解法就是在全局统筹的基础上，找到规律，通过规律设置好状态，找到状态转移的方程

*/



