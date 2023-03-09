// 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
// 输入：arr = [3,2,1], k = 2
// 输出：[1,2] 或者 [2,1]

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> res;
    sort(arr.begin(), arr.end());
    for(int i=0; i<k; i++) res.push_back(arr[i]);
    return res;
}

class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) {
            return new int[0];
        }
        // 最后一个参数表示我们要找的是下标为k-1的数
        return quickSearch(arr, 0, arr.length - 1, k - 1);
    }

    private int[] quickSearch(int[] nums, int lo, int hi, int k) {
        // 每快排切分1次，找到排序后下标为j的元素，如果j恰好等于k就返回j以及j左边所有的数；
        int j = partition(nums, lo, hi);
        if (j == k) {
            return Arrays.copyOf(nums, j + 1);
        }
        // 否则根据下标j与k的大小关系来决定继续切分左段还是右段。
        return j > k? quickSearch(nums, lo, j - 1, k): quickSearch(nums, j + 1, hi, k);
    }

    // 快排切分，返回下标j，使得比nums[j]小的数都在j的左边，比nums[j]大的数都在j的右边。
    private int partition(int[] nums, int lo, int hi) {
        int v = nums[lo];
        int i = lo, j = hi + 1;
        while (true) {
            while (++i <= hi && nums[i] < v);
            while (--j >= lo && nums[j] > v);
            if (i >= j) {
                break;
            }
            int t = nums[j];
            nums[j] = nums[i];
            nums[i] = t;
        }
        nums[lo] = nums[j];
        nums[j] = v;
        return j;
    }
}

class Solution {
    //使用快速排序
    public int[] getLeastNumbers(int[] arr, int k) {
        if(arr.length == 0){
            return arr;
        }
        int[] ans = new int[k];
        quicklySort(arr,0,arr.length-1);

        for(int i = 0; i<k; i++){
            ans[i] = arr[i];
        }
        return ans;

    }
    // 4、5、1、6、2、7、3、8
    public void quicklySort(int[] arr, int leftIndex, int rightIndex){
        if(leftIndex >= rightIndex){
            return;
        }
        
        int left = leftIndex;
        int right = rightIndex;
        int key = arr[left];

        while(left < right){
            //找到第一个比key小的元素
            while(right > left && arr[right] >= key){
                right--;
            }
            arr[left] = arr[right];

            //找到第一个比key大的元素
            while(left < right && arr[left] <= key){
                left++;
            }
            arr[right] = arr[left];
        }
        //当 left等于right时 key就放到那个位置
        arr[left] = key;

        //分别对key左边和右边的元素递归，实现快速排序
        quicklySort(arr,leftIndex,left-1);
        quicklySort(arr,right+1,rightIndex);
    }
}

作者：NoviceCode
链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/solution/tong-guo-kuai-su-pai-xu-lai-jie-jue-ti-m-ots1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

