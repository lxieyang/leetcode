class Solution(object):
    def find_kth(self, A, m, B, n, k):
        if m > n:
            return self.find_kth(B, n, A, m, k)
        if m is 0:
            return B[k - 1]
        if k is 1:
            return min(A[0], B[0])

        ia = min(k / 2, m)
        ib = k - ia
        if A[ia - 1] < B[ib - 1]:
            return self.find_kth(A[ia:], m - ia, B, n, k - ia)
        elif A[ia - 1] > B[ib - 1]:
            return self.find_kth(A, m, B[ib:], n - ib, k - ib)
        else :
            return A[ia - 1]

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)
        total = m + n
        if total & 0x1 :
            return self.find_kth(nums1, m, nums2, n, total/2 + 1)
        else :
            return (self.find_kth(nums1, m, nums2, n, total/2) +
                    self.find_kth(nums1, m, nums2, n, total/2 + 1)) / 2.0


sol = Solution()
michael = [1, 2, 3, 4, 5]
angela = [6, 7, 8, 9, 10]
print "median: ", sol.findMedianSortedArrays(michael, angela)


