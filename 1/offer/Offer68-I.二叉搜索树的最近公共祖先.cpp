

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
}

public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // 不可以这样写：Stack<TreeNode> stack = new LinkedList<TreeNode>();
        // 可以这样写：Stack<TreeNode> stack = new Stack<>();
        // 可以这样写：Deque<TreeNode> stack = new LinkedList<>();
        Deque<TreeNode> stack = new LinkedList<>();
        if (root != null) {
            stack.push(root);
        }
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            if (isParent(node, q) && isParent(node, p)) {
                boolean isRight = false;
                if (node.right != null) {
                    stack.push(node.right);
                    isRight = isParent(node.right, q) && isParent(node.right, p);
                }
                boolean isLeft = false;
                if (node.left != null) {
                    stack.push(node.left);
                    isLeft = isParent(node.left, q) && isParent(node.left, p);
                }
                if (!isRight && !isLeft) {
                    return node;
                }
            }
        }
        return null;
    }
    
    /**
     * curr 是否是node的祖先。
     */
    public Boolean isParent(TreeNode curr, TreeNode node) {
        if (curr != null) {
            if (curr.equals(node)) {
                return true;
            }
            return isParent(curr.left, node) || isParent(curr.right, node);
        }
        return false;
    }

作者：lelelongwang
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/jian-zhi-offer-68-i-er-cha-sou-suo-shu-d-f9du/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        //传递参数
        //传入root,节点p,q,返回公共节点

        //退出条件
        //p和q分别在root的左右两边则退出
        if(root.val > p.val && root.val < q.val || root.val > q.val && root.val < p.val){
            return  root;
        }

        //p或者q分别为根节点时候则退出,root和p或q重合
        if(root.val == p.val || root.val == q.val){
            return root;
        }

        //单层逻辑
        //p,q都在root左侧则检查root左孩子
        if(p.val < root.val && q.val < root.val){
            return lowestCommonAncestor(root.left,p,q);
        }


        //p,q都在root右侧则检查root右孩子
        if(p.val > root.val && q.val > root.val){
            return lowestCommonAncestor(root.right,p,q);
        }

        return null;
    }
}


作者：yu-shu-lin-feng-7
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/di-gui-jie-dai-ma-jian-dan-zhu-shi-xiang-ja6k/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。