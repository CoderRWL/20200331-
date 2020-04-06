//
//  main.c
//  双向链表
//
//  Created by  RWLi on 2020/4/6.
//  Copyright © 2020  RWLi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef enum {error,ok}status;
typedef int DataType;
typedef struct Node{
    struct Node *pre;
    DataType data;
    struct Node *next;
    
}Node;
typedef Node* linkList;
status InitNode(linkList *link){
 
    *link = malloc(sizeof(Node));
    if(!(*link)) return error;
    
    (*link)->data = -1;
    (*link)->pre = NULL;
    (*link)->next = NULL;
    
    return ok;
}

/*增  找到增的位置的前驱 */
status InsertDataToList(linkList *link ,DataType data,int place){
    
    if (place<0) {
        return error;
    }
    linkList p = *link;
    if(!p) return error;
    
    for (int i = 0; i<place && p!= NULL; i++) {
        p = p->next;
    }
    
    if (!p) {
        /* place不合法 < 0 || > 最大长度*/
        return  error;
    }
    
    linkList temp = malloc(sizeof(Node));
    if(!temp) return error;
    
    temp->data = data;
    temp->pre = p;
    temp->next = p->next;
    
    if (p->next) {
        p->next->pre = temp;
        p->next = temp;
    }else{
        //最后一个节点
        p->next = temp;
        temp->pre = p;
        temp->next = NULL;
    }
   

    
    return ok;
}

/*删  找到删的当前位置*/
status DeleteDataToList(linkList *link ,int place){
    

    linkList p = (*link)->next;
    if(!p) return error;
    
    int i = 0;
    for (;i<place && p!= NULL; i++) {
        p = p->next;
    }
    
    if (i != place || !p ) {
        /* place不合法 < 0 || > 最大长度*/
        return  error;
    }
    
   
    
    if (p->next) {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }else{
         p->pre->next = NULL;
    }
    free(p);
   
    return ok;
}

void travelList(linkList link){
    
    if(!link) return ;
    
    linkList temp = link->next;
    while (temp) {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    linkList link;
    InitNode(&link);
    for (int i =0; i<10; i++) {
        InsertDataToList(&link, i, 0);
    }
    InsertDataToList(&link, 100, 10);
    InsertDataToList(&link, 200, 5);
    DeleteDataToList(&link, 12);
     DeleteDataToList(&link, 5);
     DeleteDataToList(&link, 10);
    travelList(link);
    
    
    
    return 0;
}
