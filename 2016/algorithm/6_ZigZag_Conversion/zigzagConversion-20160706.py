class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        
        if numRows <= 1 or len(s) <= 1:
        	return s

        result = ""
        for i in range(numRows):
        	j = 0
        	idx = i
        	while idx < len(s):
        		result += s[idx]
        		if (i == 0) or (i == (numRows - 1)):
        			j += 1
        			idx = 2 * (numRows - 1) * j + i
        			continue
        		if (idx + (numRows - 1 - i) * 2) < len(s):
        			result += s[idx + (numRows - i - 1) * 2]
        		j += 1
        		idx = 2 * (numRows - 1) * j + i

    	return result

concern = "PAYPALISHIRING"
num = 3

sol = Solution()
print sol.convert(concern, num)