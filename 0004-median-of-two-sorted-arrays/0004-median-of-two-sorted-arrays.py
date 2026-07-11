class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n=len(nums1)
        m=len(nums2)

        if n>m:
            return self.findMedianSortedArrays(nums2,nums1)

        low=0
        high=n

        while low<=high:
            cut1=(low+high)//2
            cut2=(n+m+1)//2-cut1

            left1=float('-inf') if cut1==0 else nums1[cut1-1]
            left2=float('-inf') if cut2==0 else nums2[cut2-1]

            right1=float('inf') if cut1==n else nums1[cut1]
            right2=float('inf') if cut2==m else nums2[cut2]

            if left1<=right2 and left2<=right1:
                if (n+m)%2==0:
                    return (max(left1,left2)+min(right1,right2))/2.0
                else:
                    return max(left1,left2)

            if left1>right2:
                high=cut1-1
            else:
                low=cut1+1

        return 0.0