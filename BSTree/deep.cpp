#include<iostream>
using namespace std;
int depth(tree *root){//递归实现
        int ldep,rdep;
        if(!root){
                return 0;
        }else{
                ldep = depth(root->left);
                rdep = depth(root->right);
        }
        return (ldep>rdep?(ldep+1):(rdep+1))
}
int deepth(tree *root){//非递归实现
        stack<pair<tree,bool>> s;//bool变量标记右子树是否被遍历
        tree * p = root;
        max=-1;
        while(p||!s.empty()){
                if(p){
                        s.push(make_pair(p,false));//根节点入栈，遍历作指示
                        p = p->left;
                }else{
                        if(s.top().second)==false){//若右子树未被遍历，则遍历右子树
                                s.top().second = true;
                                p=s.top().second->right;
                        }else{//左右子树均已遍历，处理根节点
                                if(s.size()>max){//最深的栈的深度即为二叉树的深度
                                        max=s.size();
                                }
                                p=s.top();//根节点出栈
                                s.pop();
                        }
                }
        }
}