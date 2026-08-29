class Solution(object):
    def minBishopMoves(self, source, target):
        """
        :type source: List[int]
        :type target: List[int]
        :rtype: int
        """
        # x, y -> x+1,y+1  , x+1,y-1, x-1,y-1, x-1,y+1
        sx , sy = source[0], source[1]
        tx , ty = target[0], target[1]

        if ((sx+sy)%2 != (tx+ty)%2):
            return -1

        if (abs(sx-tx)==abs(sy-ty)):
            return 1
        return 2