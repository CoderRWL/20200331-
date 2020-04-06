//
//  main.c
//  线性循环链表
//
//  Created by  RWLi on 2020/4/1.
//  Copyright © 2020  RWLi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef enum{faild,success}status;
typedef int ElemType ;
typedef struct List{
    ElemType data;
    struct List* next;
}List;

status initList(List **list,ElemType e){
    *list = malloc(sizeof(List));
    if (!(*list)) {
        return faild;
    }
    (*list)->data = e;
    (*list)->next = *list;
    return success;
}
//增
status listInsert(List**L, ElemType e ,int place){//因为需要改变头节点指针，所以需要传**
    
    if (!(*L)) {
        return faild;
    }
    
    List *l_add = malloc(sizeof(List));
    l_add->data = e;
    if (!l_add) {
        return faild;
    }
    //首节点比较特殊,因为要使 L指向添加的节点
    if (place == 0) {
        
        
        /*
         查找最后的节点
         */
        List *tempL = *L;
        while (tempL->next!= (*L) ){
            tempL = tempL->next;
        }
        
        tempL->next = l_add;//为节点指向新节点
        l_add->next = *L;//新节点指向头节点
        *L =l_add;//头节点指向新节点
    }else{
        
        /*
         查找最后的节点
         */
        List *tempL = *L;
        int g= 0;
        while (tempL->next!= (*L) && g<place-1 ){
            g++;
            tempL = tempL->next;
        }
        
        
        if (tempL->next == *L) {
            //找完也没有找到,可能place 超出最大长度
            return faild;
        }
        
        
        //找到前面一个节点
        l_add->next = tempL->next;
        tempL->next = l_add;
        
    }
    
    
    return success;
}

//删
status deletList(List**L,int place){
    
    if (!(*L)) {
        return faild;
    }
    
    //处理特殊情况，删除头节点，需要改变尾节点指向
    if (place == 0) {
        
        //只有一个的时候
        if ((*L)->next == *L){
            free(*L);
            return success;
        }
        
        //找到尾节点
        List *tempL = *L;
        List *firstL = *L;
        while (tempL->next!= (*L) ){
            tempL = tempL->next;
        }
        tempL->next = (*L)->next;
        *L = (*L)->next;
        free(firstL);
        
        return success;
        
        
    }else{
        //找到删除节点前驱
        List *tempL = *L;
        int g= 0;
        while (tempL->next!= (*L) && g<place-1 ){
            g++;
            tempL = tempL->next;
        }
        if (tempL->next == *L) {
            //找完也没有找到,可能place 超出最大长度
            return faild;
        }
        
        List *deleL = tempL->next;
        tempL->next = deleL->next;
        free(deleL);
        
    }
    
    
    return success;
}

//改
status modifyList(List *L, ElemType e,int place){
    
    if (!L) {
        return faild;
    }
    
    List *modifyL = L;
    int g = 0;
    while (modifyL->next != L && g < place ) {
        modifyL = modifyL->next;
        g++;
    }
    
    if (modifyL->next == L) {
        return faild;
    }
    
    modifyL->data = e;
    
    return success;
}

//查

status searchList(List *L ,int place,ElemType  *e){
    if (!L) {
        return faild;
    }
    List *searchL = L;
      int g = 0;
      while (searchL->next != L && g < place ) {
          searchL = searchL->next;
          g++;
      }
      
      if (searchL->next == L) {
          return faild;
      }
    *e = searchL->data;
    
    
    return success;
}

void travelList(List *list){
    if (!list) {
        return;
    }
    
    List *temp = list;
    
    do {
        printf("%d\n",temp->data);
        temp = temp->next;
    } while (temp != list);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    List *circelList;
    
    for (int i = 0; i<10; i++) {
        if (!circelList) {
            initList(&circelList, i);
        }else{
            listInsert(&circelList, i, 0);
            
        }
    }
    
    listInsert(&circelList, 100, 5);
    listInsert(&circelList, 99, 12);
    
    deletList(&circelList, 5);
    deletList(&circelList, 9);
    deletList(&circelList, 0);
    
    modifyList(circelList, 20, 2);
    
    ElemType e;
    searchList(circelList,2,&e);
    
    travelList(circelList);
    
    return 0;
}
