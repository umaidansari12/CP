# Skip to:

# Header Navigation
# Side Navigation
# Main content
# HackerRank
# G
# M
# Wayfair Onsite Loop Coding Question: Cargo Management
# Mohammad Umaid Ansari
# Gaurav Pundir
# Wayfair Onsite Loop Coding Question: Cargo Management
# Description
# A shipping company needs a cargo management application to support following needs.

# Calculate the space required to transport a cargo consisting of one or more packages.
# Calculate the total transportation cost along with total service charge for the cargo.
# Packages can be of type Standard, Fragile & Hazardous with space requirements as follows.

# Standard: package volume * 1.2
# Fragile: package volume * 1.5
# Hazardous: package volume * 1.25
# Shipping company has set following transportation cost and service charges

# Package Type	Transportation Cost	Service Charge
# Standard	package volume * 0.05	Distance * 0.5 + Weight * 0.5
# Fragile	package volume * 0.07	Distance * 0.75 + Weight * 0.75
# Hazardous	package volume * 0.06	Distance * 0.625 + Weight * 0.625
 

 

 

 

 
 

 
# Write an application that can accept cargo request with one or more packages and output total space (volume) required to transport the cargo, total transportation cost and total service charge

 

# Example

# Cargo needs to be transported 25 miles containing 4 packages, with Id, Type, Weight, Length, Width, and Height.

# 25

# Package-1 Standard 3 16 10 5

# Package-2 Hazardous 2 14 18 7

# Package-3 Hazardous 2 25 15 10

# Package-4 Fragile 3 20 30 11

 

# Calculate the total space and shipping cost. For package Id = Package-1, Volume = 16*10*5 = 800, its of type Standard so the transportation cost is 800 * 0.05 = 40 and service charge is 25 * 0.5 + 3 * 0.5 = 14, adding up to total shipping cost of 54 for the package. Space required for Package-1 = 800 * 1.2 = 960

 

# Output

# Total Space: 17752.5

# Transportation Cost: 832.84

# Service Charges: 68.75

# Total Cost: 901.59

 

# Note: I/O and method calls are handled by the provided code stub.

 

# Input Format For Custom Testing
# Sample Case 1
# Sample Input For Custom Testing

# 25

# Package-1 Standard 3 16 10 5

# Package-2 Hazardous 2 14 18 7

# Package-3 Hazardous 2 25 15 10

# Package-4 Fragile 3 20 30 11

 

# Sample Output

# Total Space: 17752.5

# Transportation Cost: 832.84

# Service Charges: 68.75

# Total Cost: 901.59

 

# Sample Case 2
# Python 3
# 5556545152535758596061626364656667686970717273747576777879808182838485
# import os
# import sys
# # Enter your code here. Use STDOUT to print output for debugging

# class Package:
#     def __init__(self, _id, _type, weight, length, width, height):
#         self._id = _id
#         self._type = _type
#         self.weight = weight
#         self.length = length
# …        f"Total Space: {result['total_space']}\n",
#         f"Transportation Cost: {result['transportation_cost']}\n",
#         f"Service Charges: {result['service_charges']}\n",
#         f"Total Cost: {result['total_cost']}\n"])
#     fptr.close()
# Line: 101 Col: 17

# Input / Output

# Test Cases

# Console
# Congratulations! All testcases have been passed.
# Test case passed:

# 1/1

# Select a test case
# Test case 0
# Input (stdin)
# 25
# Package-1 Standard 3 16 10 5
# Package-2 Hazardous 2 14 18 7
# Package-3 Hazardous 2 25 15 10
# Package-4 Fragile 3 20 30 11
# Your Output (stdout)
# Total Space: 17752.5
# Transportation Cost: 832.84
# Service Charges: 68.75
# Total Cost: 901.59
# Expected Output
# Total Space: 17752.5
# Transportation Cost: 832.84
# Service Charges: 68.75
# Total Cost: 901.59
# _type, ``` ``` , ``` ``` , hint

import os
import sys
# Enter your code here. Use STDOUT to print output for debugging

class Package:
    def __init__(self, _id, _type, weight, length, width, height):
        self._id = _id
        self._type = _type
        self.weight = weight
        self.length = length
        self.width = width
        self.height = height
        
    def set_volume(self):
        self.volume = self.length *  self.width * self.height
    
    def set_space_multiplier(self):
        if self._type == 'Standard':
            self.space_multiplier = 1.2
        elif self._type == 'Fragile':
            self.space_multiplier = 1.5
        elif self._type == 'Hazardous':
            self.space_multiplier = 1.25
        
    def set_transportation_cost_multiplier(self):
        if self._type == 'Standard':
            self.transportation_cost_multiplier = 0.05
        elif self._type == 'Fragile':
            self.transportation_cost_multiplier = 0.07
        elif self._type == 'Hazardous':
            self.transportation_cost_multiplier = 0.06

            
    def set_service_charge_multiplier(self):
        if self._type == 'Standard':
            self.service_charge_multiplier = 0.5
        elif self._type == 'Fragile':
            self.service_charge_multiplier = 0.75
        elif self._type == 'Hazardous':
            self.service_charge_multiplier = 0.625
        
    def calculate_space(self):
        return self.volume * self.space_multiplier
    
    def calculate_transportation_cost(self):
        return self.volume * self.transportation_cost_multiplier
    
    def calculate_service_charge(self, distance):
        return distance * self.service_charge_multiplier + self.weight * self.service_charge_multiplier
        
    
    
    
    

def cargoSpaceAndCost(distance, packages):
    # Placeholder return statement
    space = 0
    transportation_cost = 0
    service_charges = 0
    total_cost = 0
    for package in packages:
        # fetching package info
        package_obj = Package(package[0], package[1], int(package[2]),int(package[3]),int(package[4]), int(package[5]))
        
        # set volume of the package
        package_obj.set_volume()
        package_obj.set_space_multiplier()
        package_obj.set_transportation_cost_multiplier()
        package_obj.set_service_charge_multiplier()
        
        space += package_obj.calculate_space()
        transportation_cost += package_obj.calculate_transportation_cost()
        service_charges += package_obj.calculate_service_charge(distance)
        
         
    return {"total_space": space, "transportation_cost": transportation_cost, "service_charges": service_charges, "total_cost": transportation_cost+service_charges}

if __name__ == "__main__":
    fptr = open(os.environ["OUTPUT_PATH"], "w")
    n = input().strip().split(" ")
    
    distance = int(n[0])
    packages = []
    try:
        while True:
            line=input()
            packages.append(line.strip().split(" "))
    except EOFError:
        # end of input
        pass

    # call candidate's method
    result=cargoSpaceAndCost(distance, packages)

    fptr.writelines([
        f"Total Space: {result['total_space']}\n",
        f"Transportation Cost: {result['transportation_cost']}\n",
        f"Service Charges: {result['service_charges']}\n",
        f"Total Cost: {result['total_cost']}\n"])
    fptr.close()