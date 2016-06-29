class Solution(object):
    def expandTwoWays(self, s, left, right):
        l = left
        r = right
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1

        return r - l - 1

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        start = 0
        end = 0
        for i in range(len(s)):
            single = self.expandTwoWays(s, i, i)
            double = self.expandTwoWays(s, i, i + 1)
            length = max(single, double)
            # print "length: ", length
            if length > end - start:
                start = i - (length - 1) / 2
                end = i + length / 2
            # print "start: ", start
            # print "end: ", end

        # print "start: ", start
        # print "end: ", end
        return s[start: end + 1]


sol = Solution()
angela = "abbaismysecondfavoritebandnab"

print "longest parlindronic substr: ", sol.longestPalindrome(angela)

