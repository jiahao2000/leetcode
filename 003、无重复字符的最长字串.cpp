//字串要求字符是连续的，而子序列可以不是连续的
//维护一个滑动窗口，滑动窗口中不可能出现两个相同的字符
//窗口的左边界维护依赖于新加入的字符上一次出现的位置，如果出现在窗口外，左边界就不需要变化，否则就要将左边界更新为该字符上次出现位置的下一个位置，因此在遍历的同时需要记录上一次字符出现的位置
//建立一个长度为128的数组来存储，下标就是每一个字符的ASCII值
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(128,-1);//pos记录出现的字符上一次出现的位置，
        int ans = 0;
        for(int i = 0 , j = 0 ;i<s.length();i++){
            j = max(j,pos[s[i]]+1); //j为左边界，i为右边界
            ans = max(ans,i-j+1);//更新当前的窗口的最大值
            pos[s[i]] = i;//更新当前字符出现的最后一个位置
        }
        return ans;
    }
};