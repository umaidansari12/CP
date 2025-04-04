n = int(input())

a = list(map(int, input().split()))
# visited = [False] * n

l,r = 0, n-1

while(l<r):
  if(a[l] > a[r]):
    visited[r] = True
    visited[r-1] = True
    r-=2
  elif(a[r] >= a[l]):
    visited[l] = True
    visited[l+1] = True
    l+=2
print(a[l])
  

# _max = max(a)
# visited = [False] * n
# for i in range(0, n-1):
#   if (not visited[i] and not visited[i+1] and a[i] != _max and a[i+1]!=_max):
#     visited[i] = True
#     visited[i+1] = True

# for i in range(0,n):
  # if(not visited[i]):
    # print(a[i])

# tc - O(n) + O(n) -> 2 loops

# sc - O(n) -> visited array
# 4 7 4 9 2

# 4 7 4       4 9 2

# 4            2
#              4 



# 4 9 7 2 4

# 4 9 7      7 2 4

# 7           7

# 4 7 2 9 4

# 4 7 4 9 2

# 4 9 7 2 4

# l = 2,
# r = 4, 

# print(a[l])

'''
5
4 7 4 2 9
9

5 
4 7 4 2 9
9

5
4 2 9 4 7
9

5
4 9 4 2 7
4
9
7
O -> 7
first approach failed in above test case, answer will be 7

5 
4 9 7 2 4
7

5
4 7 4 9 2
4

1
1
1

'''