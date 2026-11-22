# Greedy (Single Traversal)

class Solution:
    def checkString(self, s: str) -> bool:
        n=len(s)

        flag=False

        for i in range(n):
            if s[i]=='b':
                flag=True
            elif s[i]=='a' and flag==True:
                return False
        return True