# reverse_integer

# from traceback import print_tb


# def reverse( x: int) -> int:
#     strNum=str(x)
#     length=len(strNum)-1
#     result=""
#     checkZero=True
#     if(x>0):
#         for i in range(len(strNum)):
#             if(int(strNum[length-i])==0 and checkZero):
#                 continue
#             result+=strNum[length-i]
#             checkZero=False
#         result=str(result)
#     else:
#         strNum=strNum[1:]
#         # print(strNum)
#         for i in range(len(strNum)):
#             if(int(strNum[len(strNum)-1-i])==0 and checkZero):
#                 continue
#             result+=strNum[len(strNum)-1-i]
#             checkZero=False
#         result="-"+str(result)
#     return int(result)

# print(reverse(-102300000))

#  above solution is runtime error 

# right solution

def reverse(x:int)->int:
    sys=0
    if(x>0):
        sys=1
    else:
        sys=-1
    newX=abs(x)
    digitList=[]
    while newX:
        digitList.append(newX%10)
        newX=newX//10
    reversedNum=0
    digitLen=len(digitList)
    for i in range(digitLen):
        reversedNum+=digitList[digitLen-1-i]* pow(10,i)
    res=sys*reversedNum
    if res > (pow(2, 31) - 1) or res < -(pow(2,31)):
        return 0
    return res


reverse(-102300000)
