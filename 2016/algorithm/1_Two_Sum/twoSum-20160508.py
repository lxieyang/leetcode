class Solution(object):
    def twoSum(self, nums, target):

        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        intDict = dict()
        ret = list()
        for i in range(len(nums)):
            if nums[i] not in intDict:
                intDict[target - nums[i]] = i
            else:
                ret.append(intDict.get(nums[i]))
                ret.append(i)
                break
        return ret


sol = Solution()
antonia = [0, 3, 4, 0]
target = 0
ret = sol.twoSum(antonia, target)
print ret

