//
// Created by lam on 16-8-26.
//

// Question: Guess Number Higher or Lower

// We are playing the Guess Game. The game is as follows:
//
// I pick a number from 1 to n. You have to guess which number I picked.
//
// Every time you guess wrong, I'll tell you whether the number is higher or lower.
//
// You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
// -1 : My number is lower
// 1 : My number is higher
// 0 : Congrats! You got it!


// Discuss and Solution



// My Solution

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

// 二分搜索，没啥好说的
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long int low, high, mid;

        low = 1;
        high = n;
        while(low <= high){
            mid = (low + high) / 2;
            if(guess(mid) == 1){
                low = mid + 1;
            }else if(guess(mid) == -1){
                high = mid - 1;
            }else if(guess(mid) == 0){
                return mid;
            }
        }
        return mid;
    }
};