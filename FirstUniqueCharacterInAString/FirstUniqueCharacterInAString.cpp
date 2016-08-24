//
// Created by lam on 16-8-24.
//

// Question: First Unique Character in s String

//Given a string, find the first non-repeating character in it
//and return it's index. If it doesn't exist, return -1.


// Discuss and Solution

class Solution {
public:
    int firstUniqChar(string s) {
        int alphabet[26] = {0};

        // alphabet数组统计各个字母的个数
        for (int i = 0; i < s.size(); ++i)
        {
            ++alphabet[s[i] -'a'];
        }

        // alphabet[s[i]-'a']为s的第i个元素的数量
        // 若数量大于1，说明重复，i+1
        // 否则，返回i
        int i = 0;
        while (i < s.size() && alphabet[s[i]-'a'] > 1)
        {
            ++i;
        }

        // 若是i等于s.size，则说明该字符串无重复，返回-1
        return i == s.size() ? -1 : i;
    }
};

// My solution
class Solution {
public:
    // 删除字符串的所有指定字符
    string helpDeleter(char deleteChar, string str){
        for(string::iterator it = str.begin(); it != str.end(); ++it){
            if(*it == deleteChar){
                str.erase(it);
                it--;
            }
        }
        return str;
    }

    // 找到该元素对应的索引
    int findIndex(char character, string str){
        for(int i = 0; i < str.length(); i++){
            if(str[i] == character){
                return i;
            }
        }

        return -1;
    }

    int firstUniqChar(string s) {
        // 复制字符串s以便待会找出编号
        string str(s);

        // 便利字符串，若发现重复，则在返回删除该字符的字符串
        for(int i = 0; i < s.length(); i++){
            for(int j = i + 1; j < s.length(); j++){
                if(s[i] == s[j]){
                    s = helpDeleter(s[i], s);
                    i--;
                    break;
                }
            }
        }

        // 若最终返回的字符串为空字符串，则返回-1，否则返回首字符的索引
        if(s.length() != 0){
            return findIndex(s[0], str);
        }

        return -1;
    }
};

