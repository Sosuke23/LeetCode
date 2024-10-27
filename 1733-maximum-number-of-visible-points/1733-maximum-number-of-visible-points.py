class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        extra = 0
        angles = []
        
        for p in points:
            # Ignore points identical to location
            if p == location:
                extra += 1
                continue

            # Take the arctg in radians
            angles.append(atan2(p[1] - location[1], p[0] - location[0]))
        
        if len(angles) == 0:
            return extra

        # Sort angles
        angles.sort()
        
        # Duplicate the array and add 2*PI to the angles
        angles += [a + 2 * pi for a in angles]

        ans = 0
        angle_radians = pi * angle / 180
        
        l = 0
        # Sliding window
        for r in range(len(angles)):
            # Pop all the points out of the field of view
            while angles[r] - angles[l] > angle_radians:
                l += 1
            ans = max(ans, r - l + 1)
        
        return ans + extra