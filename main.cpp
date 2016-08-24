#include <iostream>
#include <string>

using namespace std;

struct chars{
    char character;
    int index;
};

string helpDeleter(char deleteChar, string str){
    for(string::iterator it = str.begin(); it != str.end(); ++it){
        if(*it == deleteChar){
            str.erase(it);
            it--;
        }
    }
    return str;
}

int findIndex(char character, string str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] == character){
            return i;
        }
    }

    return -1;
}

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

int main() {
    string str="loveleetcode";

    cout << firstUniqChar(str) << endl;
}
