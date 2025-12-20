# # _Check_if_Array_Is_Sorted_and_Rotated

# # logic
# # - find minimum number in the list
# # - check no. before minimum is sorted and after the min is sorted
# # - first element should be greater than last


# # def Check(nums:List[int]) -> bool:
# #     if(isSorted(nums)):
# #         return True
# #     arrMin=min(nums)
# #     print(' arrMin: ',  arrMin)
# #     indexMin=nums.index(arrMin)
# #     beforeMin=nums[0:indexMin]
# #     print('beforeMin: ', beforeMin)
# #     afterMin=nums[indexMin+1:]
# #     print('afterMin: ', afterMin)
# #     if nums[0]>=nums[len(nums)-1]:
# #         if isSorted(beforeMin) and isSorted(afterMin):
# #             return True

# #     return False

# # def isSorted(list:List[int])->bool:
# #     sort=sorted(list)
# #     print(' sort: ',  sort)
# #     print(sort == list)
# #     if sort == list:
# #         return True
# #     return False

# # x=Check([1,2,3])



# # the proble with this solution is  due to the min function and 
# # index function ,the index function  return the first element index

# def check(nums:List[int])->bool:
#     minElem=sys.maxsize
#     minIndex=-1
#     # get minimum value and its index
#     sortedArr=True
#     for i in range(1,len(nums)-1):
#         if nums[i] < nums[i-1]:
#             sortedArr=False
#     print('sortedAr: ', sortedArr)
#     if sortedArr:
#         return True
#     for i in range(len(nums)-1):
#         if nums[i]<= minElem:
#             minElem=nums[i]
#             minIndex=i
            
#     # check right of it is sorted
#     print(' minIndex: ',  minIndex)
#     flag1=1
    
#     for i in range(1,minIndex):
#         if nums[i]<nums[i-1]:
#             flag1=0
#             break
#     # check left of it is sorted
#     print(' flag1: ',  flag1)
#     flag2=1
    
#     for i in range(minIndex+1,len(nums)-1):
#         if nums[i]<nums[i-1]:
#             flag2=0
#             break
#     print('flag2=1: ', flag2)
#     # if all the condition it true return true 
#     if (flag1 and flag2 and nums[0]>=nums[len(nums)-1]):
#         return True
#     return False


# # y=check([6,10,6])
# k=check([1,2,1,1])
# print(k)


# _____ right answer _____*****_____

from typing import List 
import sys
def check( nums: List[int]) -> bool:
    count = 0
    length = len(nums) - 1
    for i in range(length):
        if nums[i] > nums[i + 1]:
            print(nums[i] , nums[i + 1])
            count+=1
            print(' count: ',  count)

    print(count)
    if count > 1 or (count == 1 and nums[0] < nums[length]):
        return False
    
    return True

y=check([4,5,6,1,2,3])
print(y)
# k=check([1,2,1,4,1])
# print(k)

# for  checking the rotation , in rotation only one position where current element is greater from the point of rotation