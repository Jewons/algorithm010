//利用map来实现，很耗时
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        std::map<char,int> statisticMap1;
        statisticMap1.clear();
        for(int i = 0; i < s.length(); i++)
        {
            if(statisticMap1.find(s[i]) == statisticMap1.end())
                statisticMap1[s[i]] = 1;
            else
                statisticMap1[s[i]]++;
        }
       // std::map<char,int> statisticMap2;
       // statisticMap2.clear();
        for(int i = 0; i < t.length(); i++)
        {
            if(statisticMap1.find(t[i]) == statisticMap1.end())
                statisticMap1[t[i]] = 1;
            else
                statisticMap1[t[i]]--;
        }
        std::map<char,int>::iterator iter = statisticMap1.begin();
        for(;iter != statisticMap1.end();++iter)
        {
            if(iter->second != 0)
                return false;
        }
        return true;
    }
};
//用数组实现的hash，效率要比上一个快
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        int hash[26] = {0};

        for(char n : s)
            hash[n - 'a']++;
        for(char n : t)
            hash[n - 'a']--;
        for(int n : hash)
        {
            if(n != 0)
                return false;
        }
        return true;
    }
};