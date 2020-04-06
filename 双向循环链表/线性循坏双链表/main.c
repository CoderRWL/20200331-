//
//  main.c
//  线性双向循坏链表
//
//  Created by  RWLi on 2020/4/5.
//  Copyright © 2020  RWLi. All rights reserved.
//

#include <stdio.h>

#include <stdlib.h>


typedef enum {error,ok}status;
typedef int EleType;


typedef struct Node{
    struct Node *pre;
    EleType data;
    struct Node *next;
} Node;

typedef Node* NodeList;



status InitNodeList(NodeList *list){
    
    
    (*list) = malloc(sizeof(Node));
    if ((*list) == NULL) {
         return error;
    }
   
    (*list)->pre = *list;
    (*list)->next = *list;
    (*list)->data = -1;
   
    return ok;
}





/* 增 找前一个*/
status insertElementToList(NodeList *list,EleType e,int place){
    Node *p = *list;
    if (!p) {
        return error;
    }
    

    int g = 0;
    /*p->next == *list表示已经遍历到了最后一个节点
     place为最大的位置*/
    while(g<place && p->next != *list)
    {
        p = p->next;
        g++;
    }
 
    
    if (g!= place ) {
        /* place不合法 <0 或者>最大长度*/
        return error;
    }
    
   
    Node *add = malloc(sizeof(Node));
    if (!add) {
        return error;
    }
    add->next = NULL;
    add->pre = NULL;
    add->data = e;

   //改变之前后继的节点关系
    add->next= p->next;
    add->pre = p;
   
    
    //改变之前前驱的节点关系
    p->next->pre = add;
    p->next = add;

    return ok;
    
    
    
}

//删 找当前
status deleteElementFromList(NodeList *list,int place){
    Node *p = (*list)->next;
    if (!p) {
        return error;
    }
    

    int g = 0;
    
    while(g< place && p != *list)
    {
        p = p->next;
        g++;
    }
     
    if (g != place ) {
        //没有找到删除节点
        return error;
    }
    
    p->pre->next = p->next;
    p->next->pre = p->pre;
    
    free(p);

   
    return ok;
    
    
    
}
void travelLit(Node *list){
    if (!list) {
        return;
    }
    Node *temp = list->next;
    
    while (temp != list) {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    NodeList list;
    InitNodeList(&list);
    for (int i = 0; i<10; i++) {
        insertElementToList(&list, i,0);
    }
    
    insertElementToList(&list, 100, 10);
    insertElementToList(&list, 100, 5);
      insertElementToList(&list, 100, -1);
    deleteElementFromList(&list, 11);
    deleteElementFromList(&list, 0);
    deleteElementFromList(&list, 4);
     deleteElementFromList(&list, -1);
    travelLit(list);
    
    return 0;
}
