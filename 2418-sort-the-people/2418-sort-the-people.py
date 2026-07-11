class Solution(object):
    def sortPeople(self, names, heights):
        height_to_name = {heights[i]: names[i] for i in range(len(names))}

        heights.sort(reverse=True)

        return [height_to_name[h] for h in heights]
        