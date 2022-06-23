```
Given a n*n matrix, where each of the rows and columns is sorted in ascending order, 
return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13


1 5 49
10 11 52
12 13 60

1 5 49 10 11 52 12 13 60 

1 5 10 11 12 13 49 52 60

two sorted arrays find kth smallest in

1, 5, 9
8, 11, 13 k = 4


4 5 6 
7 8 9
1 2 3

k = 3

ans = 3

int kthSmallestElement(vector<vector<int>> &matrix,int k){
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> min_heap;
    
    int n = matrix.size();
    
    for(int row_index=0;row_index<n;row_index++){
        min_heap.insert({row_index,0});
    }
    
    int kth_smallest_element = -1;
    
    for(int iterate=0;iterated<k;iterate++){
        
        pair<int,int> smallestElement = min_heap.top();
        min_heap.pop();
        
        
        int row_number = smallestElement.first;
        int col_number = smallestElement.second;
        
        kth_smallest_element = matrix[row_number][col_number];
        
        if(col_number + 1 < n)
        min_heap.insert({row_number,col_number});
    
    }
    
    return kth_smallest_element;
    
}


```
