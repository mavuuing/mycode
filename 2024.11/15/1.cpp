#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20   			  //顺序表的最大长度
typedef  int  KeyType;   		  // 将关键字类型定义为整型
typedef  struct
{
    KeyType   key;             // 关键字项
    char     *otherinfo;       // 其它信息
}ElemType;

typedef  struct
{
    ElemType   r[MAXSIZE+1];   //r[0]空
    int        length;         //当前元素的个数
}SqList;

//初始化顺序表函数
void InitList_Sort(SqList &L)
{
    int i;
    //printf("输入待排序的记录个数(<20): ");
    scanf("%d",&L.length);
    //printf("输入待排序记录的关键字序列: ");
    for(i=1;i<=L.length;i++)
        scanf("%d",&L.r[i].key);
}

//输出顺序表函数
void Print_Sort(SqList &L)
{
    int i;
    for(i=1;i<=L.length;i++)
        printf("%d ",L.r[i].key);
    printf("\n");
}

//此处添加直接插入排序功能函数

void InsertSort(SqList &L) {
    int i, j;
    for (i = 2; i <= L.length; i++) {
        L.r[0] = L.r[i];
        j = i - 1;
        while (j > 0 && L.r[j].key > L.r[0].key) {
            L.r[j + 1] = L.r[j];
            j--;
        }
        L.r[j + 1] = L.r[0];
    }
}
int main( )
{
    int x;
    SqList L,L1;

    //printf("直接插入排序操作---\n");
    InitList_Sort(L);        //创建待排序的数据表
    //printf("直接插入排序之前数据序列为：");
    Print_Sort(L);
    InsertSort(L);           //直接插入排序
    //printf("直接插入排序之后数据序列为：");
    Print_Sort(L);
    return 0;
}
