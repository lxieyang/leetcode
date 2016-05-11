# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        dummyHead = ListNode(-1)
        temp = dummyHead

        while l1 or l2:
            a = 0
            b = 0
            if l1:
                a = l1.val
                l1 = l1.next
            if l2:
                b = l2.val
                l2 = l2.next

            sum = a + b + carry
            carry = (sum) / 10
            val = (sum) % 10

            temp.next = ListNode(val)
            temp = temp.next
        if carry:
            temp.next = ListNode(carry)

        return dummyHead.next

def printList(node):
    print "printing node:\n"
    while node:
        print node.val, " ",
        node = node.next
    print "\n"



a = ListNode(2)
b = ListNode(4)
c = ListNode(3)

a.next = b
b.next = c


w = ListNode(9)
x = ListNode(9)
y = ListNode(9)
z = ListNode(9)
w.next = x
x.next = y
y.next = z

sol = Solution()
ret = sol.addTwoNumbers(a, w)
print "Original: \n"
printList(a)
printList(w)
print "Added: \n"
printList(ret)

