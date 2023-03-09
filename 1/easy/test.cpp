#include<iostream>

using namespace std;

int get_array_lenth(int arrays[]){
    int len = arrays.length;
    return len;
}

int main(){
    int nums[3] = {1, 2, 3};
    int len = get_array_lenth(nums);
    cout << "len = " << len << endl;
}