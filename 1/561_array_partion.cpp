#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// int arrayPairSum(vector<int>& nums) {
//     int sum_max = 0;
//     for (int i=0; i<nums.size()-1; i++)
//     {
//         for (int j=i+1; j<nums.size(); j++)
//         {
//             if(nums[i] > nums[j])
//             {
//                 int temp = nums[i];
//                 nums[i] = nums[j];
//                 nums[j] = temp; 
//             }
//         }
//     }

//     for (int k=0; k<nums.size(); k+=2)
//     {
//         printf("%d\n", nums[k]);
//         sum_max += nums[k];
//     }
//     return sum_max;
// }

int main()
{
    int sum_max = 0;
    vector<int> vec{3,6,2,4};
    // int max = arrayPairSum(vec);
    sort(vec.begin(), vec.end());
    for (int k=0; k<vec.size(); k+=2)
    {
        printf("%d\n", vec[k]);
        sum_max += vec[k];
    }
    printf("max = %d\n", sum_max);
}
