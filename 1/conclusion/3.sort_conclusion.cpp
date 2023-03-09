// 排序算法总结

#include<iostream>
#include<vector>
using namespace std;

// 1.冒泡排序法 :比较相邻的元素。如果第一个比第二个大，就交换他们两个。

void bubbleSort(int a[], int n)
{
  for(int i =0 ; i< n-1; ++i)
  {
    // for(int j = 0; j < n-i-1; ++j)
    for(int j = i; j < n-1; ++j)
    {
      if(a[j] > a[j+1])
      {
        int tmp = a[j] ;  //交换
        a[j] = a[j+1] ;
        a[j+1] = tmp;
      }
    }
  }
}

// 2 选择排序 :在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
void selectionSort(int arr[], int len) {
    int minIndex, temp;
    for (int i = 0; i < len - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIndex]) {     // 寻找最小的数
                minIndex = j;                 // 将最小数的索引保存
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// 3 插入排序 
void print(int a[], int n ,int i){
  cout<<i <<":";
  for(int j= 0; j<n; j++){
    cout<<a[j] <<" ";
  }
  cout<<endl;
}

void InsertSort(int a[], int n){
    for(int i= 0; i<n; i++){
        for(int j= i; j>0; j--){
            if(a[j] < a[j-1]) swap(a[j], a[j-1]);
            else break;
        }
        print(a, n, i);
    }
}

// 4. 快排
/*void QuickSort(vector<int>& v, int low, int high) {
	if (low >= high)		// 结束标志
		return;
	int first = low;		// 低位下标
	int last = high;		// 高位下标
	int key = v[first];		// 设第一个为基准

	while (first < last)
	{
		// 将比第一个小的移到前面
		while (first < last && v[last] >= key)
			last--;
		if (first < last)
			v[first++] = v[last];

		// 将比第一个大的移到后面
		while (first < last && v[first] <= key)
			first++;
		if (first < last)
			v[last--] = v[first];
	}
	//
	v[first] = key;
	// 前半递归
	QuickSort(v, low, first - 1);
	// 后半递归
	QuickSort(v, first + 1, high);
}*/

void quicklySort(int arr[], int leftIndex, int rightIndex){
    if(leftIndex >= rightIndex){
        return;
    }
    
    int left = leftIndex;
    int right = rightIndex;
    int key = arr[left];

    while(left < right){
        //找到第一个比key小的元素
        while(left < right && arr[right] >= key){
            right--;
        }

        //找到第一个比key大的元素
        while(left < right && arr[left] <= key){
            left++;
        }
        if(left<right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    //当 left等于right时 key就放到那个位置
    int temp = arr[left];
    arr[left] = arr[leftIndex];
    arr[leftIndex] = temp;

    //分别对key左边和右边的元素递归，实现快速排序
    quicklySort(arr,leftIndex,left-1);
    quicklySort(arr,right+1,rightIndex);
}

// 希尔排序
void shell_sort(int array[], int length) {
    int h = 1;
    while (h < length / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < length; i++) {
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
                std::swap(array[j], array[j - h]);
            }
        }
        h = h / 3;
    }
}

int main(){
    int nums[6] = {8,4,6,3,5,7};
    // bubbleSort(nums, 6);
    // selectionSort(nums, 6);
    // InsertSort(nums, 6);
    // quicklySort(nums, 0, 6);
    shell_sort(nums, 6);
    for(int i=0; i<sizeof(nums)/sizeof(nums[0]); i++){
        printf("i, nums[i]= [%d, %d]\n", i, nums[i]);
    }
}