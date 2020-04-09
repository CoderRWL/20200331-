//
//  main.c
//  题目一
//
//  Created by  RWLi on 2020/4/6.
//  Copyright © 2020  RWLi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/* 题⽬1 :
将2个递增的有序链表合并为一个链表的有序链表; 要求结果链表仍然使⽤用两个链表的存储空间,
不另外占⽤用其他的存储空间. 表中不不允许有重复的数据
 */

//单向链表

typedef  enum{error,ok} status;
typedef int DataType;
typedef struct Node{
    DataType data;
    struct Node *next;
}Node;
typedef Node* linkList;
status InitNodeLinkList(linkList *list){
    
    *list = malloc(sizeof(Node));
    linkList p = *list;
    if (!p) {
        return error;
    }
    p->data = 0;
    p->next = NULL;
    
    
    return ok;
}



//默认升序
/* 插入一个数然后进行排序，默认前面的数据已经排好了序*/
status InsertDataAndSorted(linkList *list,DataType data){

    linkList p = *list;
    if(!p) return error;
    
    
    //找到跟data最近的节点,第一次比插入值大的前一个节点
   
    while (p->next) {
        if (p->next->data > data) {
            break;
        }
        p = p->next;
    }
    
    linkList add = malloc(sizeof(Node));
    if(!add) return error;
    add->data = data;
    add->next = NULL;
    
    add->next = p->next;
    p->next = add;
    
    return ok;
}

//node是list2分配好的空间，慎重使用，可能会改变list2的空间布局
status InsertNodeAndSorted(linkList *list,Node *node){

    linkList p = *list;
    if(!p) return error;

    
    //找到跟data最近的节点,第一次比插入值大的前一个节点
   
    while (p->next) {
        if (p->next->data > node->data) {
            break;
        }
        p = p->next;
    }
        
    
//    node->next = p->next;//会改变list2的内存布局,
    
    linkList add = malloc(sizeof(node));//采用新建的方式
    add->data = node->data;
    add->next = p->next;
    
    p->next = add;
    
    return ok;
}



status DuplicateRemoval(linkList *list){
    linkList p = *list;
    p = p->next;
   
   
    
    while ( p && p->next) {//循环到尾节点前一个节点
         linkList q = p;
        
        while (q->next ) {//循环到最后一个节点的前一个节点
            
            //找到相同元素的前一个节点，修改指针域
            
            if (q->next->data == p->data) {
                //删除q->next
                linkList dele = q->next;
                q->next = q->next->next;
                free(dele);
                //不需要移动q,对新修改的指针域进行判断
                
            }else{
                q = q->next;
            }
        }
        
        p = p->next;
    }
    
    return ok;
}


status havelastNode(linkList list, int j){
    linkList q = list->next;
    if (!q->next) {
        return error;
    }
    
    while (j--) {
        q = q->next;
        if (!q) {
            return error;
        }
        
    }
    
    return ok;
    
    
}

status sortedList(linkList *list){
    linkList p = *list;
    p = p->next;
    
    //排序法  方式多样
    //冒泡排序
    
    int j = 1 ;
    while (p && p->next) {
        
        linkList q = (*list)->next;
       
        while (q &&  havelastNode(q, j)) {
            
            if (q->data > q->next->data) {
                //交换相邻2个节点位置，其实交换下连个数据就行
                DataType tempData = q->data;
                q->data = q->next->data;
                q->next->data = tempData;
                
            }
            
            q = q->next;
        }
        
        p = p->next;
        j++;
    }
    
    
    
    return ok;
}




//合并内容返回至list1,会开辟新的内存空间
status combinListAndSorted(linkList *list1,linkList *list2){
    linkList temp = *list2;
    temp = temp->next;
    
    while (temp) {
    
        InsertNodeAndSorted(list1, temp);
        temp = temp->next;
    }
    
    return ok;
    
}

//把数据加到最后再去，拼接两个链表，在实行排序
status combinList(linkList *list1,linkList *list2){
    linkList temp2 = *list2;
    temp2 = temp2->next;
   
    if (temp2 == NULL) {
        return error;
    }
    
    linkList temp1 = *list1;
    temp1  = temp1->next;
    if (temp1 == NULL) {
        return error;
    }
    
    //找到最后一个节点
    while (temp1->next) {
        temp1 = temp1->next;
    }
    
    //把list2 拼接到最后一个节点
    
    temp1->next = temp2;
    
    
 
   
    

    
    return ok;
    
}

void travelList(linkList list){
    linkList p = list->next;
    while (p) {
        printf("%d\n",p->data);
        p = p->next;
    }
}


int mainElement(int *a,int n){
    
    
    int count = 1;
    int key = a[0];
    for (int i =1; i<n; i++) {
        if (key == a[i]) {
            count++;
        }else{
            
            if (count>0) {
                count--;
            }else{
                key = a[i];
                count = 1;
            }
            
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
//    linkList list;
//    InitNodeLinkList(&list);
    
//    InsertDataAndSorted(&list, 5);
//    InsertDataAndSorted(&list, 10);
//    InsertDataAndSorted(&list, 2);
//    InsertDataAndSorted(&list, 30);
//    InsertDataAndSorted(&list, 10);
//    InsertDataAndSorted(&list, 1);
//    InsertDataAndSorted(&list, 1);
    
    
//    DuplicateRemoval(&list);

//    travelList(list);
    
//    linkList list1;
//    InitNodeLinkList(&list1);
//    InsertDataAndSorted(&list1, 6);
//     InsertDataAndSorted(&list1, 3);
//     InsertDataAndSorted(&list1, 8);
//    InsertDataAndSorted(&list1, 10);
//    InsertDataAndSorted(&list1, 10);
//
//
//    linkList list2;
//    InitNodeLinkList(&list2);
//     InsertDataAndSorted(&list2, 6);
//     InsertDataAndSorted(&list2, 7);
//     InsertDataAndSorted(&list2, 5);
//     InsertDataAndSorted(&list2, 10);
//     InsertDataAndSorted(&list2, 10);
  
    // 方法一 开辟新空间
//    combinListAndSorted(&list1, &list2);

    
   
    //方法二 不开辟新空间
//    combinList(&list1, &list2);//拼接
//
//    sortedList(&list1);
//    DuplicateRemoval(&list1);
//
//    travelList(list1);
    
    
    
    int a[] = {0,5,5,3,1,7,5,5,2,5,5};
    
    mainElement(a, 8);
    
    return 0;
    
}
