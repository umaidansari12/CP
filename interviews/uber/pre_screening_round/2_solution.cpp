string solution(vector<int> numbers) {
    int even_sum = 0, odd_sum = 0, _size = numbers.size();
    for(int idx = 0; idx < _size; idx++){
        if(idx%2==0)
            even_sum += numbers[idx];
        else
            odd_sum += numbers[idx];
    }
    
    if(even_sum > odd_sum)
        return "even";
    else if(odd_sum > even_sum)
        return "odd";
    return "equal";

}

