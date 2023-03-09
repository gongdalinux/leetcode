// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
//      5
//     / \
//    2   6
//   / \
//  1   3
// postOrder
// 输入: [1,3,2,6,5]
// 输出: true

// inOrder
// 输入: [5,2,1,3,6]
// 输出: true

bool PostorderTraverse(vector<int> postorder, int l, int r){
    if(l>=r) return true;
    int m = l;
    while(postorder[m] < postorder[r]) m++;
    // int m = l;
    while(m<r){
        if(postorder[m] < postorder[r]){
            return false;
        }
        m++;
    }
    return PostorderTraverse(postorder, l, m-1) && PostorderTraverse(postorder, m, r-1);
}

bool verifyPostorder(vector<int>& postorder) {
    return PostorderTraverse(postorder, 0, postorder.size()-1);
}


// 二叉搜索树的前序遍历

bool InorderTraverse(vector<int> inorder, int l, int r){
    if(l>=r) return true;
    int m = l;
    while(inorder[++m] < inorder[l]) {};
    int temp = m;
    while(temp<r){
        if(inorder[temp] < inorder[l]){
            return false;
        }
        temp++;
    }
    return InorderTraverse(inorder, l+1, m-1) && InorderTraverse(inorder, m, r);
}

bool verifyInorder(vector<int>& inorder) {
    return InorderTraverse(inorder, 0, inorder.size()-1);
}