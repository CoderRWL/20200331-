//
//  main.c
//  栈结构
//
//  Created by  RWLi on 2020/4/13.
//  Copyright © 2020  RWLi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef enum{error,ok} status;
typedef int DataType;
#define MAXSIZE 5

//线性储存栈
typedef struct {
    DataType data[MAXSIZE];
    int top;//栈顶
}stackNode;
//初始化栈
status initStackNode(stackNode *node){
    if(!node)return error;
    node->top = -1;//从-1开始，以熟悉的0，1，2，数组坐标
    return ok;
}
//入栈
status pushNode(stackNode *node,DataType data){
    if(!node)return error;
    if(node->top== MAXSIZE-1) return error;//已满
    
    node->data[ ++node->top] = data;
    return ok;
}
//出栈
status popNode(stackNode *node,DataType *data){
    if(!node)return error;
    if(node->top== -1) return error;//空栈
    *data = node->data[node->top];
    node->top--;
    return ok;
}
//清空栈
status clearNode(stackNode *node){
    if(!node)return error;
    node->top = -1;
    return ok;
}
//判断是否时空栈
status isEmpty(stackNode node){
    if(node.top ==-1) return ok;
    return error;
}
//栈长度
int getNodeLength(stackNode node){
    return node.top+1;
}
//获取元素
status getDataAtIndex(stackNode node,int place,DataType *data){
    if (place > node.top) {
        return error;
    }
    *data = node.data[place];
    return ok;
}
//遍历
status travelNode(stackNode node){
    int i = 0;
    while (i <= node.top) {
        printf("%d\n",node.data[i++]);
    }
    
    return ok;
}
 

//链式储存的栈

typedef struct stackLinkNode{
    DataType data;
    struct stackLinkNode *next;
}stackLinkNode;
//初始化栈
typedef stackLinkNode* LinkNodePtr;
status initLinkNode(LinkNodePtr *node){
    //使用头节点
    *node = malloc(sizeof(stackLinkNode));
    (*node)->data = -1;
    (*node)->next = NULL;
    return ok;
}
//入栈
status pushLinkNode(LinkNodePtr node,DataType e){
    //采用前插法，使栈顶一直在第一个元素，查找时可以减少对所有元素的遍历
    if(!node) return error;
    
    stackLinkNode *top = node->next;
    
    stackLinkNode *new = malloc(sizeof(stackLinkNode));
    new->data = e;
    new->next = top;
    node->next = new;
    
    return ok;
}

//出栈
status popLinkNode(LinkNodePtr node,DataType *e){
     if(!node) return error;
    
    //删除首元节点
     stackLinkNode *top = node->next;
    if(!top)return error;//空栈
    
    node->next = top->next;
    free(top);
    
    return ok;
}

//清空栈
status clearlinkNode(LinkNodePtr node){
    if(!node)return error;
    //删除除头节点的所有节点
     stackLinkNode *temp = node->next;
    while (temp) {
        stackLinkNode *next = temp->next;
        free(temp);
        temp = next;
    }
    
    return ok;
}

//判断空栈
status isEmptyLinkNode(stackLinkNode node){
    
    if (node.next == NULL) {
        return ok;
    }

    return error;
}
//长度
int LinkNodeLength(stackLinkNode node){
    int length = 0;
    while (node.next) {
        length++;
    }
    return length;
}
//遍历
status traveLinkNode(stackLinkNode node){
    stackLinkNode *temp = node.next;
    while (temp) {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    return ok;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
//    stackNode lineNode;
//    initStackNode(&lineNode);
//    for (int i =0; i<7; i++) {
//        pushNode(&lineNode, i);
//    }
//    travelNode(lineNode);
//
//    DataType e1;
//    DataType e2;
//    popNode(&lineNode, &e1);
//    popNode(&lineNode, &e2);
//    travelNode(lineNode);
//    clearNode(&lineNode);

    
    stackLinkNode *linkNode;
    initLinkNode(&linkNode);
    for (int i = 5; i <10; i++) {
        pushLinkNode(linkNode, i);
    }
    traveLinkNode(*linkNode);
    DataType e;
    popLinkNode(linkNode, &e);
    

    return 0;
}
