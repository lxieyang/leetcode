# version 1, time limit exceeded
class Solution(object):
    def reverseString(self, s):
        ret = ""
        for i in range(len(s)):
            idx = len(s) - i - 1
            ret += s[idx]
        return ret


# version 2
class Solution2(object):
    def reverseString(self, s):
        return ''.join(reversed(s))



concern = 'angela'

sol = Solution()
print sol.reverseString(concern)


sol2 = Solution2()
print sol2.reverseString(concern)
