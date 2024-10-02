#include <iostream>
#include <vector>>
using namespace std;

int maxFrequency(vector<int> &nums, int k){
    long long int currentSum = 0;
    int maxFrequency = 0; 
    int left = 0;
    int size = nums.size();
    sort(nums.begin() , nums.end());
    for(int right = 0; right<size ; right++){
        
        currentSum += nums[right];

        while (currentSum <= (long) nums[right]*(right - left + 1) + k)
        {
            currentSum -= nums[left];
            left++;
        }
        maxFrequency = max((right - left +1) , maxFrequency);
        
    }



}

int main(){

    return 0;
}