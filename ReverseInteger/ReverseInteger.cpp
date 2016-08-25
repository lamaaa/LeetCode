//
// Created by lam on 16-8-25.
//

// Question: Reverse Integer

// Reverse digits of an integer.


// Discuss and Solution

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};

// My Solution
class Solution {
public:
    int reverse(int x) {
        vector<int> nums;
        long long int answer = 0;

        // 分别取出x的每位数并倒序排放
        while(x != 0){
            nums.push_back(x % 10);
            x /= 10;
        }

        // 将nums数字组成x的倒序数字
        for(int i = 0; i < nums.size(); i++){
            answer = answer * 10 + nums[i];
        }

        // 若是超出范围，则输出0
        if(answer > 2147483647  || answer < -2147483648){
            answer = 0;
        }

        return answer;
    }
};