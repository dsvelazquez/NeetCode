"""
You are given an array points, an integer angle, and your location, where location = [posx, posy] and points[i] = [xi, yi] 
both denote integral coordinates on the X-Y plane.

Initially, you are facing directly east from your position. You cannot move from your position, but you can rotate. 
In other words, posx and posy cannot be changed. Your field of view in degrees is represented by angle, 
determining how wide you can see from any given view direction. Let d be the amount in degrees that you 
rotate counterclockwise. Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].
"""
def visiblePoints(self, points: list[list[int]], angle: int, locatino: list[int]) -> int:
    def getAngle(p):
        angle = math.atan2(p[0] - location[0], p[1] - location[1] / (2*math.pi) *360
        

    angles = []