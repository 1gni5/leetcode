class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        height_dict = dict(zip(heights,names))
        names.clear()
        for key in sorted(height_dict.keys(),reverse=True):
            names.append(height_dict[key])
        return names