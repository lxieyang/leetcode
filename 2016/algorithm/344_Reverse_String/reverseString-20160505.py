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


# version 3
class Solution3(object):
    def reverseString(self, s):
        return s[::-1]



concern = 'jesus'

sol = Solution()
print sol.reverseString(concern)


sol2 = Solution2()
print sol2.reverseString(concern)


sol3 = Solution3()
print sol3.reverseString(concern)
