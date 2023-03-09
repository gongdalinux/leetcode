// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

Node* pre, head = nullptr;

Node* treeToDoublyList(Node* root) {
    if(root == nullptr) return nullptr;
    dfs(root);
    head->left = pre;
    pre->right = head;
    return head;
}

void dfs(Node* root){
    if(root == nullptr) return;
    dfs(root->left);
    if(head == nullptr) head = root;
    else pre->right = root;
    root->left = pre;
    pre = root;
    dfs(root->right);    
    
}