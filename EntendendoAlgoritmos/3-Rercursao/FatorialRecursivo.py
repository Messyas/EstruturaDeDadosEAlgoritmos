def fat(x):
    if x == 1:
        return 1
    else:
         result = x * fat(x-1)
         print(result)
         return result
    
fat(3)
