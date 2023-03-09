

#include<iostream>
#include<vector>

using namespace std;

int minArray(vector<int>& numbers) {
    int right = numbers.size();
    int left = 0;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(numbers[mid] > numbers[right]){
            left = mid + 1;
        }
        else if(numbers[mid] < numbers[right]) right = mid;
        else right -= 1;
    }
    return numbers[left];
}