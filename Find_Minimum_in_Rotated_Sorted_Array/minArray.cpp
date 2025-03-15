int minArray(vector<int>& numbers) {
    int low = 0;
    int high = numbers.size()-1;
    int mid;
    while(low < high){
        mid = low + (high - low) / 2;
        if (numbers[mid] > numbers[high])
            low = mid + 1; //这里 +1 是关键
        else if(numbers[mid] < numbers[high])
            high = mid;
        else
            high--;
    }
    return numbers[low];
}
