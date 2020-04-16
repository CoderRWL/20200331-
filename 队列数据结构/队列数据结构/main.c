//
//  main.c
//  队列数据结构
//
//  Created by  RWLi on 2020/4/13.
//  Copyright © 2020  RWLi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef enum{error,ok} status;
typedef int DataType;
#define MAXSIZE 5

//顺序储存队列
typedef struct {
    DataType data[MAXSIZE];
    int front;//出指针坐标
    int rear;//进指针坐标
}stackNode;

status initLineNode(stackNode* node){
    node->front = 0;
    node->rear = 0;
    return ok;
}
//入队列
status push(stackNode* node,DataType e){
    //让front一直可以++，超出最大值后又回到初始值，取模来得到下标，预留一个位置，用来区分满和空队列
    
    if ((node->rear +1 )%MAXSIZE == node->front) {//满了,差一个位置就超一圈了
        return error;
    }
    
    node->data[node->rear] = e;
    node->rear = (node->rear +1)%MAXSIZE;
    
    return ok;
}
//出队列
status pop(stackNode* node,DataType *e){
    if (node->front == node->rear) {//空队列
        return error;
    }
    
    *e = node->data[node->front];
    node->front = (node->front +1)%MAXSIZE;
    
    return ok;
}

status isEmpty(stackNode node){
    if (node.front == node.rear) {
        return ok;
    }
    return error;
}
status clearNode(stackNode* node){
    if(!node) return error;
    node->rear = node->front = 0;
    return ok;
}
int length(stackNode node){
    return  (node.rear-node.front +MAXSIZE)%MAXSIZE;
}
status travel(stackNode node){
    for (int i = node.front; (i+1)%MAXSIZE!=node.rear; i++) {
        printf("%d\n",node.data[i]);
    }
    
    return ok;
}

//链式储存
typedef struct linkNode{
    DataType data;
    struct linkNode* next;
}linkNode;

typedef struct{
    linkNode *node;
    linkNode *top;//队顶
}linkNodeque;

status initlinkNode(linkNodeque** que){
    //头节点
    (*que) = malloc(sizeof(linkNodeque));
    (*que)->node = malloc(sizeof(linkNode));
    (*que)->node->data = -1;
    (*que)->node->next = NULL;
    (*que)->top = (*que)->node;
    return ok;
}

status pushlinkNode(linkNodeque* que,DataType e){
    if(!que) return error;
    
    linkNode *new = malloc(sizeof(linkNode));
    new->data = e;
    new->next = NULL;
    
    que->top->next = new;
    
    que->top = new;
    
    return ok;
}

status poplinkNode(linkNodeque* que,DataType *e){
     if(!que) return error;
    if (que->top == que->node) {//空队列
        return error;
    }
    
    //首元节点出队列
    linkNode *head = que->node->next;
    que->node->next = head->next;
    *e = head->data;
    free(head);
    
    return ok;
    
}

status travellinkNode(linkNodeque que){
    
    linkNode *temp = que.node->next;
    while (temp) {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    return ok;
}

status isEmptylinkNode(linkNodeque que){
    if (que.top == que.node) {
        return ok;
    }
    return error;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
//    stackNode node;
//    initLineNode(&node);
//    for (int i =1; i<7; i++) {
//        push(&node, i);
//    }
//
//    travel(node);
//
//    DataType e;
//    pop(&node, &e);
//    travel(node);
    
    
    linkNodeque *que;
    initlinkNode(&que);
    for (int i =1; i<7; i++) {
        pushlinkNode(que, i);
    }
    travellinkNode(*que);
    
    return 0;
}
