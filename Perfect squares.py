class Solution:
    def numSquare(self, n; int) -> int:
        ih = [n] * n+1
        ih[0] = 0
        for tar in range(1,n+1)
            for s in range(1,tar+1)
                sqr = s*s
                if tar - sqr < 0:
                    break
                ih[tar] = min(ih[tar], 1+ih[tar-sqr])
        return ih[n]
