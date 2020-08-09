class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(),s.end());
        int n = s.length();
        int index = 0;
        for(int start = 0;start < n;start++){
            if(s[start] != ' '){
                if(index != 0)
                    s[index++] = ' ';
                
                int end = start;
                while( end < n && s[end] != ' ')
                    s[index++] = s[end++];
                
                reverse(s.begin() + index - (end - start),s.begin() + index);

                start = end;
            }
        }
        s.erase(s.begin() + index,s.end());
        return s;
    }
};