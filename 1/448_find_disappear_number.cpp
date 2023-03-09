// 找到所有数组中消失的数字
// 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
// 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
// 输入:
// [4,3,2,7,8,2,3,1]  sort:[1,2,2,3,3,4,7,8]
// 输出:
// [5,6]

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    for (auto& num : nums) {
        int x = (num - 1) % n; //还原x，得到x的下标
        nums[x] += n;   //此时x的位置上的值大于n，表明x出现过至少一次
    }
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
        if (nums[i] <= n) {
            ret.push_back(i + 1); //i位置上的值i+1未曾出现过
        } else {
            nums[i] %= n;//还原该位置上的值
        }
    }
    return ret;
}


// List<Integer> findDisappearedNumbers(int[] nums) {
//     int n = nums.length;
//     List<Integer> res = new LinkedList<>();
//     int x;
//     for (int i = 0; i < n; i++) {
//         x = (nums[i] - 1) % n;//还原x，得到x的下标
//         nums[x] += n;//此时x的位置上的值大于n，表明x出现过至少一次
//     }
//     for (int i = 0; i < n; i++) {
//         if (nums[i] <= n) {//
//             res.add(i + 1);//i位置上的值i+1未曾出现过
//         } else {
//             nums[i] %= n;//还原该位置上的值
//         }
//     }
//     return res;
// }

int main(){
    vector<int> nums={1,2,2};
    vector<int> ret = findDisappearedNumbers(nums);
    for(int i=0; i<ret.size(); i++){
        printf("%d\n", ret[i]);
    }
}


