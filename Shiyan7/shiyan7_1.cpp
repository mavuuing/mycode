#include<iostream>
using namespace std;
#define OVERFLOW -1
#define OK 1
#define ERROR 0
typedef int KeyType; 
typedef struct BSTNode
{
KeyType data;	             //数据域
BSTNode *lchild,*rchild;    //左右孩子指针
}BSTNode,*BSTree; 

//此处请补充二叉排序树元素插入函数
void InsertBST(BSTree &T,int key){
if(T){   
     BSTree  S=new BSTNode;
     S->data=key;
     S->lchild=S->rchild=NULL;
     T=S;
    }
    else 
       if(T->data>key) InsertBST(T->lchild,key);
       if(T->data<key) InsertBST(T->rchild,key);
}



//创建一棵二叉排序树函数
void CreateBST(BSTree &T,int n) 
{   
KeyType e;
//cout<<"请输入结点的关键值(格式：5 8 7...)：";
while (n--)
{   
cin>>e;
InsertBST(T, e);    //调用插入函数
}
//cout<<"创建二叉排序树成功！\n";
}

//中序遍历输出二叉排序树结点信息
void InOrderTraverse(BSTree &T)    
{
if(T)
{
InOrderTraverse(T->lchild);
cout<<T->data<<' '; 
InOrderTraverse(T->rchild);
}
}

int main( )
{  
BSTree T=NULL;
BSTree S;
int x,n,key;
//cout<<"请输入二叉排序树中元素的个数：";
cin>>n;
CreateBST(T,n);
//cout<<"当前有序二叉树中序遍历结果为:";
InOrderTraverse(T);

return 0;
}

