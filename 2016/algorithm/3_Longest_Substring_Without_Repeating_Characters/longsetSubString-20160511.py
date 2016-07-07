class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        globalMax = 0
        i = 0
        j = 0
        posDict = dict()
        while j < len(s) :
            if posDict.get(s[j]) is not None:
                i = max(i, 1 + posDict.get(s[j]))
            globalMax = max(globalMax, j - i + 1)
            posDict[s[j]] = j
            j += 1
        return globalMax


concern = "abcabcbbabcd"
sol = Solution()
print 'Length: ', sol.lengthOfLongestSubstring(concern), "\n"

