class Solution(object):
    def arrayRankTransform(self, arr):
        sorted_unique = sorted(list(set(arr)))
        rank_map = {num: rank + 1 for rank, num in enumerate(sorted_unique)}
        return [rank_map[num] for num in arr]
        