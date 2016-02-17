/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()) return -1;
        if(needle.empty()) return 0;
        int end = haystack.size() - needle.size() + 1;
        for(int i = 0; i < end; i++){
            int j = i;
            int k = 0;
            while(j < haystack.size() && k < needle.size() && haystack[j] == needle[k]){
                j++; k++;
            }
            if(k == needle.size()){
                return i;
            }
        }
        return -1;
    }
};

