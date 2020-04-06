//
//  main.cpp
//  DataAndAlgorithms0331
//
//  Created by qlmac1 on 2020/3/31.
//  Copyright © 2020 qlmac1. All rights reserved.
//

#include <iostream>


using namespace std;
//线性数据逻辑结构 顺序存储

//自定义属于自己的宏和类型名称
#define OK 1
#define ERROR 0
#define MAXSIZE 15
typedef int ElemType;
typedef enum {faild,success}status;

//定义一个数据元素
/* 数据->数据对象->数据元素->数据项  ，其中数据元素是数据的基本单位*/
 class Person{
    ElemType *data;//使用数组来存储多个数据项
    int size;//记录当前存储数量/长度
     
   public:
     Person(){
         //申请堆空间
         data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);//返回void *需要转换一下
         size = 0;
     }
     ~Person(){
         if (data) {
             free(data);
             size = 0;
         }
     }
     
     

     //增删改，实际中应该加锁
     
     //增
     status insertElem(ElemType e,int index){
         //保持健壮性,边界值判断，容错判断
         if (size == MAXSIZE)  return faild;//容量已达最大
         if(index > size)      return faild;//下标不对，超过最大长度
         
        //判断是否需要移动数据项
         if (index < size) {
             for (int i = size; i>index; i--) {
                 data[i] = data[i-1];
             }
         }
         
         data[index] = e;
         size++;
         
         return success;
     }
     
     //删
     status deleteElem(ElemType e){
        
         if (size == 0)  return faild;
        
         for (int i = 0; i<size; i++) {
             if (data[i] == e) {
                 //移动数据
                 for (int j = i; j<size-1; j++) {
                     data[j] = data[j+1];
                 }
                 size--;
                 break;
             }
         }
         
         return success;
     }
     
     status deleteElemAtIndex(int index){
            
         if (size == 0)  return faild;
         
         for (int j = index; j<size-1; j++) {
             data[j] = data[j+1];
         }
         size--;

         return success;
     }
     
     //改
     status modify(ElemType old_e,ElemType new_e){
         
         if (size == 0)  return faild;
         
         for (int i =0; i< size ; i++) {
             if (data[i] == old_e) {
                 data[i] = new_e;
                 //break;//只改动第一次出现的地方
             }
         }
         return success;
     }
     status modifyAtIndex(ElemType e,int index){
         
         if (size == 0)        return faild;
         if (index > size-1)   return faild;
       
         data[index] = e;
         
         return success;
     }
     
     
     //查
     status search(int index,ElemType &e){
         if (size == 0)        return faild;
         if (index > size-1)   return faild;
         
         e = data[index];
         return success;
     }
     
     //遍历打印
     status travel(){
         if (data == NULL) return faild;
             
         for (int i = 0; i<size; i++) {
             cout << data[i] << endl;
         }
         
         return success;
     }
    
};





int main(int argc, const char * argv[]) {
    // insert code here...
   cout << "Hello, World!\n";
    
    Person p;
    for (int i =0; i<10; i++) {
        p.insertElem(i, 0);
    }
    
    p.modify(5, 50);
    p.modifyAtIndex(90, 0);
    
    ElemType e ;
    p.search(4, e);//当形参是&类型时，传递时可以直接传变量名
    
    p.travel();
    
    
    return 0;
}
