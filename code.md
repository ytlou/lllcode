# 牛客网及其他

### 华为

汽水瓶
某商店规定：三个空汽水瓶可以换一瓶汽水，允许向老板借空汽水瓶（但是必须要归还）。
小张手上有n个空汽水瓶，她想知道自己最多可以喝到多少瓶汽水。
数据范围：输入的正整数满足 1≤n≤100 

输入例子：
3
10
81
0
输出例子：
1
5
40

# leetcode hot150

## dp 动态规划

##### 背包问题总结

***顺序***

01背包
**二维**dp数组01背包先遍历物品还是先遍历背包**都是可以**的，且第二层for循环是**从小到大**遍历。

**一维**dp数组01背包**只能先遍历物品再遍历背包**容量，且第二层for循环是**从大到小**遍历。

完全背包

纯完全背包的一维dp数组实现，先遍历物品还是先遍历背包都是可以的，且第二层for循环是从小到大遍历。

如果求组合数就是外层for循环遍历物品，内层for遍历背包。

如果求排列数就是外层for遍历背包，内层for循环遍历物品。

***背包递推公式***

能否能装满背包（或者最多装多少）：dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);

问背包装满最大价值：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]); 

问装满背包所有物品的最小个数：dp[j] = min(dp[j - coins[i]] + 1, dp[j]);





##### 一维dp



###### 70 爬楼梯

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

 

示例 1：

输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶

```cpp
class Solution {
public:
    int climbStairs(int n) {
		vector<int> dp(n+1,0);//1 2 随便用 完全背包+排列 =》先遍历背包再物品 小=》大
        //n+1 是0 时要算1种
        //dpn += dpn-num[i]
        dp[0] = 1;
        for(int j = 1;j<=n;j++){
            for(int i = 1;i<=2;i++){
                if(j>=i) dp[j] += dp[j-i];
            }
        }
        return dp[n];
        
    }
};
```





###### 198 打家劫舍

如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。



```CPP
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
		if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp (n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i<n;i++){
            dp[i] = max(dp[i-2] + nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
};
```



###### 139 单词拆分

给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

 

示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp (n+1,0);
        int n = s.length();
        int m = wordDict.size();
        dp[0]  = true;
        for(int j = 0;j<n+1;j++){
            for(int i = 0;i<m;i++){
                string word = s.substr(i,j-i);
            if(s.substr())
            dp[n] = dp[]}
        }
    }
};
```



###### 322 零钱兑换

给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

 

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1

# 代码随想录

## 数组 

#### 二分查找

## 链表

## 哈希表

## 字符串

## 双指针



## 栈队列

#### 232.用栈实现队列 

使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。

## 二叉树

## 回溯

## 贪心

## dp

## 单调栈



## 图论



## 回文子串

#### 647. 回文子串 个数

https://leetcode.cn/problems/palindromic-substrings/

https://www.programmercarl.com/0647.%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.html#%E6%80%9D%E8%B7%AF

字符串中有多少个回文子串。

输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"



dp 法

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        // 1. dp 定义 dp[i][j] 左闭右闭 true ok false 不ok
        if(s.size() == 0) return 0;
        int result = 0;
		vector<vector<bool>> dp (s.size(), vector<bool>(s.size(),false));// 3.初始化
        for(int i = s.size();i>=0;i-- ){//顺序
            for(int j = i;j<s.size();j++){
                if(s[i]==s[j]){
                    if(j-i<=1) {
                        dp[i][j]= true;//2. 公式
                        result++;}
                    else if (dp[i+1][j-1]){
                        result++ ;
                        dp[i][j] = true;
            }
        }
        
        
    }}
    return result;
        }
};
```

双指针法

一个元素为中心点和两个元素为中心点的情况。

```cpp
class Solution {
public:
    int extend (string &s,int l, int r, int n){
        int result = 0;
        while(l>=0&&r<n&&s[l]==s[r])
        {
            l--;
            r++;
            result++;
        }
            return result;
    }
    int countSubstrings(string s) {
			int n = s.size();
        	int result = 0;
        	for(int i = 0;i<n;i++){
                result += extend(s,i,i,n);
                result +=extend(s,i,i+1,n);
            }
        return result;
    }
};
```

#### 5.最长回文子串

https://www.programmercarl.com/0005.%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.html#%E6%80%9D%E8%B7%AF

https://leetcode.cn/problems/longest-palindromic-substring/

给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案

双指针法

```cpp
class Solution {
public:
    int left =0;
    int maxl = 0;
    void extend (string &s,int l,int r,int n){
        while(l>=0&&r<n&&s[l]==s[r]){
            if(r-l+1>maxl) {
                left= l;
                maxl = r-l+1;
            }
            l--;
            r++;

        }
        
    }
    string longestPalindrome(string s) {
        if(s.size()==0) return 0;
        int result =0;
        for(int i = 0;i<s.size();i++){
            extend(s,i,i,s.size());
            extend(s,i,i+1,s.size());

        }
        return s.substr(left,maxl);
    }
};
```

dp 法 

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
		int left=0;
        int maxl =0;
        int n = s.size(); 
        vector<vector<bool>> dp (n, vector<bool>(n,false));
        for(int i = n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                  if(s[i] == s[j] && (j-i < 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                
                }
                if(dp[i][j]){
                    if(j-i+1>maxl) {
                        maxl = j - i +1;
                        left = i;
                    }
                }
            }
        }
        return s.substr(left,maxl);
    }
};
```

#### 132. 分割回文串 II

给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。

返回符合要求的 最少分割次数 。

示例 1：

输入：s = "aab" 输出：1 解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

示例 2： 输入：s = "a" 输出：0

示例 3： 输入：s = "ab" 输出：1

https://www.programmercarl.com/0132.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2II.html#%E6%80%9D%E8%B7%AF

https://leetcode.cn/problems/palindrome-partitioning-ii/

```cpp
class Solution {
public:


    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isp (s.size(), vector<bool> (s.size(),false));
        for(int i = n-1;i>=0;i--){
            for(int j = i;j<n;j++){
                if(s[i]==s[j]&&(j-i<=1||isp[i+1][j-1])){
                        isp[i][j] = true;
                }
                
            }
        }

        vector<int> dp (n,0);
        for(int i =0;i<n;i++) dp[i] = i;
        for(int i = 1;i<n;i++){
            if(isp[0][i]) {dp[i]= 0; continue;}
            for(int j = 0;j<i;j++){
                if(isp[j+1][i]) { dp[i] = min(dp[i],dp[j]+1);}
               
            }
        }
        return dp[n-1];
    }
};
```



#### 516.最长回文子序列

https://leetcode.cn/problems/longest-palindromic-subsequence/

https://www.programmercarl.com/0516.%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E5%BA%8F%E5%88%97.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE

给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。

示例 1: 输入: "bbbab" 输出: 4 一个可能的最长回文子序列为 "bbbb"。

示例 2: 输入:"cbbd" 输出: 2 一个可能的最长回文子序列为 "bb"。



# 每日一题

# acwings

# 剑指offer