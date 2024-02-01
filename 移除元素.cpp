class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int f = 0, s = 0;
        for(f = 0;f<nums.size();f++){
            if(nums[f]!=nums[s]){
                nums[++s]=nums[f];
            }
        }
        return s+1;
    }
};

class Solution {
public:
    bool backspaceCompare(string s, string t) {
            change(s);
            change(t);
            cout<<s<<" "<<t;
            if(s==t){
                return true;
            }
            return false;
    }
    void change(string &a){
        int f = 0,s=0;
        for(f=0;f<a.length();f++){
            if(a[f]!='#'){
                a[s++] = a[f];
            }
            else{
                if(s != 0)
                s--;
            }
        }
        a = a.substr(0,s);
        }
    class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> n (nums.size(),0);
        int l =0,r=nums.size()-1;
        int p = nums.size();
        while(p--){
            if(nums[l]*nums[l]>=nums[r]*nums[r]) {
n[p] = nums[l]*nums[l];
l++;
            }
            else {
                    n[p] = nums[r]*nums[r];
                    r--;
            }
        }
        return n;
    }
};
