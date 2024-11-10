#include<iostream>
using namespace std;
#include <stdlib.h>
  //方案一：利用辅助数组进行标记的方法 
   
  //方案二：采用原地哈希进行标记的方法
  //请在此补充函数，可选择上面方案的其中一种。
 int  findMissMin(int *a, int n){
    int *b=new int[n];
   
    int min=a[0],max=a[0];
    for(int i=1;i<n;i++){
          b[a[i]]++;
          if(a[i]>max) max=a[i];
          if(a[i]<min) min=a[i];
    }  
    // 检查 min 是否为正数
    if(min <= 0) {
        // 如果 min 不是正数，返回 1
        return 1;
    }
    for(int j=min;j<=max;j++){   
      if(b[j]==0&&j>0)         
         return j;
    }
     
 }
 
int main() 
{
    int *a,n,i;
    //cout<<"请输入元素的个数n:";
    cin>>n;
    // bug修复：将 new int(n) 修改为 new int[n]
    a = new int[n];
    //cout<<"请依次输入整数数组的数据值:";
    for(i=0;i<n;i++)
        cin>>a[i];
    //cout<<"该数组未出现过的最小正整数是：";
  
    cout<<findMissMin(a,n);   
    return 0;
}
