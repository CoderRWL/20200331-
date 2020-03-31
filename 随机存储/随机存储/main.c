//
//  main.c
//  随机存储
//
//  Created by  RWLi on 2020/3/31.
//  Copyright © 2020  RWLi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 15
typedef enum {faild,success}status;
typedef int ElemType;

//线性链式存储

//data存储数据，next存储与其他数据项的关系

typedef struct  Person{
    ElemType data;
    struct Person *next;
}Person;

//定义一个节点数组,注意要跟结构体指针区分开，
//typedef struct Person* personList;

//数组的地址,初始化一个数组，则把数组的地址传过来，要改变形参，需要传地址，可以这么理解
status InitPerson(Person **list){
    //创建头节点. list是数组首地址
    //先分配一个首元节点空间，后续动态添加，哨兵，一直在最第一个位置
    *list =(Person *)malloc(sizeof(Person));
    if (!*list) {
        return faild;
    }
    (*list)->data = 0;//可以赋值一些有意义的值，比如长度
    (*list)->next = NULL;
    return success;
}

//增
status Insert(Person *p,ElemType e,int index){
    
    if (!p) {
        return faild;
    }
    int k = 0;//计数
    Person *pre_p = p;
    while (pre_p && k < index) {
         //查找index-1的节点
        k++;
        pre_p = pre_p->next;
    }
    
    //如果没有哨兵，上面就要 < index-1,pre_p->next时正好来到index-1
    
    if (!pre_p) {
        return faild;//没有找到
    }
    
    /*要添加节点的关系指向下一个节点
     让前驱节点的关系指向当前节点*/
    Person *add_p = malloc(sizeof(Person));
    if (!add_p) {
        return faild;
    }
    add_p->data = e;
    add_p->next = pre_p->next;
    pre_p->next = add_p;
    return success;
}

//删
status delete(Person *p ,int index){
    //找到前后节点，删掉前后驱关系
    
    //前面判断跟增加节点是一致的
    if (!p) {
        return faild;
    }
    int k = 0;//计数
    Person *pre_p = p;
    while (pre_p && k < index) {
        //查找index-1的节点
        k++;
        pre_p = pre_p->next;
    }
    
    if (!pre_p) {
        return faild;//没有找到
    }
    
    /*让前节点的关系指向删除节点的后驱节点
     释放删除节点空间
     */
    Person *deleteP = pre_p->next;
    pre_p->next = deleteP->next;
    free(deleteP);
    
    
    return success;
    
}

//改
status modify(Person *p,ElemType e,int index){
    /*只需改动值，不需要改动关系*/
    if (!p) {
        return faild;
    }
    int k = 0;//计数
    Person *p_index = p;
    while (p_index && k <= index) {
        //查找index-1的节点
        k++;
        p_index = p_index->next;
    }
    
    if (!p_index) {
        return faild;//没有找到
    }
    
    p_index->data = e;
    
    return success;
}

//查

status search(Person *p,int index,ElemType *e){
    if (!p) {
           return faild;
       }
       int k = 0;//计数
       Person *p_index = p;
       while (p_index && k <= index) {
           //查找index-1的节点
           k++;
           p_index = p_index->next;
       }
       
       if (!p_index) {
           return faild;//没有找到
       }
    
    *e = p_index->data;
    
    return success;
    
    
}

//单链表前插和后插法

status creatHead(Person *p ,int count){
    if (!p) {
        return faild;
    }
    
    Person * p_first = p->next;
    /*
     新加入的节点指向第一个节点
     头节点指向新加入的节点
     */
    while (count-- >0) {
         Person *p_add = malloc(sizeof(Person));
        if (!p_add) {
            return faild;
        }
        
        p_add->data = count;//arc4random_uniform(100);
        p_add->next = p_first;
        p->next = p_add;
        
        p_first = p_add;
    }
    
    return success;
}

status creatAfter(Person *p ,int count){
    if (!p) {
        return faild;
    }
     Person * p_after = p;
    while (p_after->next) {
        p_after = p_after->next;
    }
    /*
     直接加到最后 ,为节点关系指向新添加节点
     */
    while (count-- >0) {
         Person *p_add = malloc(sizeof(Person));
        if (!p_add) {
            return faild;
        }
        
        p_add->data = count;//arc4random_uniform(100);
        p_after->next =p_add;
        p_after = p_add;
        if (count == 0) {
            p_after->next = NULL;
        }
    }
    
    return success;
}



void travel(Person p){
//     printf("%d\n",p.data);//哨兵可以不打印
    Person *nextp = p.next;
    while (nextp) {
        printf("%d\n",nextp->data);
        nextp = nextp->next;
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    Person *p;
    InitPerson(&p);//传地址过去，内部初始化
    for (int i = 0; i<10; i++) {
        Insert(p, i, 0);
    }
//    Insert(p, 100, 5);
//    Insert(p, 100, 11);
    
//    delete(p, 0);
//    delete(p, 8);
//
//    modify(p, 60, 2);
//
//    ElemType e;
//    search(p, 2, &e);
//
//    if (p) {
//        travel(*p);
//    }
   
 
//    creatHead(p, 10);
    creatAfter(p, 5);
    travel(*p);
    
    
    return 0;
}
