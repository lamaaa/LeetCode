//
// Created by lam on 16-8-24.
//

// Question: Intersection of Two Array

// Given two arrays, write a function to compute their intersection.


// Discuss and Solution
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s(nums1.begin(), nums1.end());
    vector<int> out;
    for (int x : nums2)
        if (s.erase(x))
            out.push_back(x);
    return out;
}

// My solution
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 对nums1和nums2排序以便后面二分查找
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // intersectArr存放交叉数据
        vector<int> intersectArr;

        // 遍历nums1，对nums2进行二分查找查看是否有重复数据
        for(int i = 0; i < nums1.size(); i++){
            if(binary_search(nums2.begin(), nums2.end(), nums1[i])){
                // 若intersectArr里面没有该数字，则添加
                if(!binary_search(intersectArr.begin(), intersectArr.end(), nums1[i])){
                    intersectArr.push_back(nums1[i]);
                }
            }
        }

        return intersectArr;
    }
};