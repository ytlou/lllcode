//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
//有序数组，同时题目还强调数组中无重复元素

//对区间的定义没有想清楚，区间的定义就是不变量。要在二分查找的过程中，保持不变量，就是在while寻找中每一次边界的处理都要坚持根据区间的定义来操作，这就是循环不变量规则
//左闭右闭即[left, right]，或者左闭右开即[left, right)
//while (left <= right)
//if (nums[middle] > target) right 要赋值为 middle - 1 大点 比大的更小找
//if (nums[middle] < target) { left = middle + 1      小点 

//while (left < right)
//if (nums[middle] > target) right 要赋值为 middle 大点 比大的更小找
//if (nums[middle] < target) { left = middle + 1      小点 

//区别在于 一个等号 和右边界+1

// 版本一
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};
//int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
//边界统一

//logn




//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

//class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
        // 分别处理如下三种情况
        // 目标值在数组所有元素之前
        // 目标值等于数组中某一个元素
        // 目标值插入数组中的位置
            if (nums[i] >= target) { // 一旦发现大于或者等于target的num[i]，那么i就是我们要的结果
                return i;
            }
        }
        // 目标值在数组所有元素之后的情况
        return nums.size(); // 如果target是最大的，或者 nums为空，则返回nums的长度
    }
};  暴力法 n

12 34
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle;
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [0, -1]
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right]，return  right + 1 = left
        // 目标值在数组所有元素之后的情况 [left, right]， 因为是右闭区间，所以 return right + 1
        return right + 1;
    }
};


//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
12  34
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)  return {-1,-1};
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int mid = (l+r)>>1;
            if(nums[mid]>=target) r = mid;
            else l = mid +1;
        }
        if(nums[l]!=target) return {-1,-1};
        else {
            int l1 = l;
            int l = 0;
            int r = nums.size()-1;
            while(l<r){
                int mid = (l+r+1)>>1;// +++++1
                if(nums[mid]<=target) l = mid;
                else r = mid -1;
            }
            
        return{l1,l};
        }
        return {-1,-1};}
};

唯一的 我们用 l<=r mid>target r = m - 1 else if mid<target l= m+1 else return
            l< r            r = m

非唯一的。   l<r  mid>=target r = m else l=mid +1; 左边界
                mid<=target l = m else r = mid -1 右边界



x 的平方根 3
    class Solution {
public:
    bool check(long long mid, int x) {
    return mid * mid > x;  // 注意这里的条件变为了 mid * mid > x
}

int mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }

    int l = 1, r = x;
    while (l < r) {
        int mid = (l + r)>>1;  // 向下取整
        if (check(mid, x)) {
            r = mid;  // 如果mid不满足条件（即 mid * mid > x），向左侧搜索
        } else {
            l = mid + 1;  // 否则向右侧搜索
        }
    }
    return l - 1;  // 返回 l - 1，因为我们需要的是最大的 n 使得 n^2 <= x
}
};

小数 3 +4
#include<iostream>
#include<iomanip>
using namespace std;
double n,l,r,mid;
bool flag;
double q(double a){return a*a*a;}
int main(){
    cin>>n;
    l=-10000,r=10000;
    while(r-l>=1e-7){
        mid=(l+r)/2;
        if(q(mid)>=n) r=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(6)<<l;
    return 0;
}


唯一的 
class Solution {
public:
    bool isPerfectSquare(int num) {
            int l = 0, r= num;
            while (l<=r){
                int mid = (r-l)/2+l;
                long square = (long )mid*mid;
                if(square <num) l = mid+1;
                else if(square >num) r= mid -1;
                  else return true;           }
   return false;}  1 + 2 num +1 longlong 
    
};
