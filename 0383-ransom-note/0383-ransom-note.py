class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        n=len(ransomNote)        # Len of the Ransom Note String
        m=len(magazine)          # Len of the Magazine String

        need={}                  # Declaration of the Need HashMap (Ransom Note)
        have={}                  # Declaration of the Have HashMap (Magazine)

        for i in range(n):
            need[ransomNote[i]]=need.get(ransomNote[i], 0) + 1

        for i in range(m):
            have[magazine[i]]=have.get(magazine[i], 0) + 1

        return self.fun(have,need)

    def fun(self,have,need):
        for c, fneed in need.items():
            # c -> Key One
            # fneed -> Value One
            fhave = have.get(c, 0)    # The freq of that letter in have

            if fhave<fneed:
                return False

        return True