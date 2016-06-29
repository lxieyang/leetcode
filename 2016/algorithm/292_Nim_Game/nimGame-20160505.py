class Solution(object):
    def canWinNim(self, n):
        return not(n % 4 is 0)


sol = Solution()
concern = "Hit \'q\' to quit!\n"
while(True):
    concern = raw_input("")
    if(concern is not 'q'):
        real = int(concern)
        if(sol.canWinNim(real)):
            print 'Can Win!\n'
        else:
            print 'Oops! Will definitely lose!\n'
    else:
        break;
