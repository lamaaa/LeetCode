//
// Created by lam on 16-8-22.
//

// Question:Find Peak Element

// A peak element is an element that is greater than its neighbors.
// Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
// You may imagine that num[-1] = num[n] = -∞.
// For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.


// Discuss and Solution

// Consider that each local maximum is one valid peak.
// My solution is to find one local maximum with binary search.
// Binary search satisfies the O(logn) computational complexity.

//Binary Search: recursion
class Solution {
public:

    int findPeakElement(const vector<int> &num) {
        return Helper(num, 0, num.size()-1);
    }
    int Helper(const vector<int> &num, int low, int high)
    {
        if(low == high)
            return low;
        else
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] > num[mid2])
                return Helper(num, low, mid1);
            else
                return Helper(num, mid2, high);
        }
    }
};

//Binary Search: iteration
class Solution {
public:
    int findPeakElement(const vector<int> &num)
    {
        int low = 0;
        int high = num.size()-1;

        while(low < high)
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};

//Sequential Search:
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        for(int i = 1; i < num.size(); i ++)
        {
            if(num[i] < num[i-1])
            {// <
                return i-1;
            }
        }
        return num.size()-1;
    }
};

//My Solution
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int answer = 0;
        bool flag = false; // 若flag为假，则最后一个元素为答案，否则不是。

        for(int i = 0; i < nums.size()-1; i++){ // 遍历nums
            if(i == 0 && nums[i] > nums[i+1]){ // 若i是首位，则不检查前面元素，只检查后面元素是否小于i元素
                flag = true;
                answer = i;
            }else if(nums[i] > nums[i+1] && nums[i] > nums[i-1]){ // 否则检查前面元素是否小于i元素，并且检查后面元素是否小于i元素
                flag = true;
                answer = i;
            }
        }
        answer = flag ? answer : nums.size()-1;
        return answer;
    }
};