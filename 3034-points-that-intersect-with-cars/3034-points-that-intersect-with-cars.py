class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        p = [0] * 101
        for (x, y) in nums:
            for i in range(x, y + 1):
                p[i] = 1

        return p.count(1)