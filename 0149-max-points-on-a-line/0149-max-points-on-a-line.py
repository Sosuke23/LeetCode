from collections import defaultdict

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        res = 0
        for i in range(n):
            slope_count = defaultdict(int)
            for j in range(i + 1, n):
                if points[i][0] == points[j][0]:  # avoid division by zero
                    slope = float('inf')
                else:
                    slope = (points[i][1] - points[j][1]) / (points[i][0] - points[j][0])
                
                slope_count[slope] += 1
            
            res = max(res, max(slope_count.values(), default=0))
        
        return res + 1
