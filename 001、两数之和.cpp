//1、两重循环 时间复杂度O(n^2)

//2、哈希表 O(n)

#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
    vector<int>twoSum(vector<int>& nums, int target){
        unordered_map<int,int> record; //哈希表
        for(int i = 0; i < nums.size(); i++){
            int num = target - nums[i];
            if(record.find(num)!=record.end()){
                return {record[num],i};
            }
            record[nums[i]] = i; 
        }
        return {-1,-1};
    }   
};