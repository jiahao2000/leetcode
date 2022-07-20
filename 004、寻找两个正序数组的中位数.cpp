#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if(n%2 == 0){
            int left = find(nums1,0,nums2,0,n/2);
            int right = find(nums1, 0, nums2, 0,n/2 + 1);
            return (left+right)/2.0;
        }
        else{
            return find(nums1, 0, nums2, 0, n/2+1);
        }

    }
    int find(vector<int>& nums1,int i,vector<int>& nums2,int j, int k){
        //为了处理方便，我们要保证nums1的长度不超过nums2的长度，因此要先进行一下转换
        if(nums1.size()-i>nums2.size()-i){
            return find(nums2,0,nums1,0,k);
        }
        if(nums1.size() == i) return nums2[j+k-1];
        if(k == 1) return min(nums1[i],nums2[j]);

        int idx1 = min(i+k/2,(int)nums1.size());
        int idx2 = j + k - k/2;
        if(nums1[idx1-1]<nums2[idx2-1]){
            return find(nums1,idx1,nums2,j,k-(idx1-i));
        }else{
            return find(nums1,i,nums2,idx2,k-(idx2-j));
        }

    }
};