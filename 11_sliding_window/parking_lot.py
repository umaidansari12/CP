# Parking lot
# Consider the car parking lot as 0 indexed array. Given a list of positions occupied by cars and k, return the min length of roof required to cover k cars.
#For the first one, sort the positions, shift the window and calculate the distance between the first and the kth elements. Store the minimum
#Sliding window on k cars, shrink the window if there is > k cars and increase window is there are less than k cars, keep track of window size

# There are many cars parked in the parking lot. The parking is a straight very long line and a parking slot for every single meter. There are cars parked currently and you want to cover them from the rain by building a roof. The requirement is that at least k cars are covered by the roof.What's the minium length of the roof that would cover k cars?
# The function has the following parameters:
# cars: integer array of length denoting the parking slots where cars are parked
#k: integer denoting the number of cars that have to be covered by the roof

# Example:
# Input:
# cars: [2, 10, 8, 17]
# k: 3
# output: 9
# Explanation: you can build a roof of length 9 covering all parking slots from the 2nd one to the 10th one, so covering 3 cars at slots 2, 10, 8, there are no shorter roof  that can cover 3 cars, so the answer is 9
# 1 <= n <= 10^5
# 1 <= k <= n
# 1 <= cars[i] <= 10^14
# All slots token by cars are unique

a=[3,5,7,8,9,53,67,124]
k=6

a.sort()
x=0
minLength=float('inf')
for idx,num in enumerate(a):
    if idx-x+1==k:
        minLength=min(minLength,num-a[x]+1)
        x+=1

print(minLength)

class Solution:
    """
    @param cars:  integer array of length denoting the parking slots where cars are parked
    @param k: integer denoting the number of cars that have to be covered by the roof
    @return: return the minium length of the roof that would cover k cars
    """
    def ParkingDilemma(self, cars, k):
        # write your code here
        cars.sort()
        n = len(cars)
        res = float('inf')
        for i in range(n-k+1):
            res = min(res, cars[i+k-1] - cars[i])
        return res+1
