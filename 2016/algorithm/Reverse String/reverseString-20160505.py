class Solution(object):
    def reverseString(self, s):
        ret = ""
        for i in range(len(s)):
            idx = len(s) - i - 1
            ret += s[idx]
        return ret

sol = Solution()
concern = 'angela'
print sol.reverseString(concern)
