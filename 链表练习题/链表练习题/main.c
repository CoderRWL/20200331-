//
//  main.c
//  链表练习题
//
//  Created by  RWLi on 2020/4/9.
//  Copyright © 2020  RWLi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef enum{error,ok} status;
typedef int eleType;
typedef struct Node{
    eleType data;
    struct Node* next;
}Node;
typedef Node* Link;


status initLink(Link *link){
    *link = malloc(sizeof(Node));
    if(*link == NULL) return error;
    (*link)->data = -1;
    (*link)->next = NULL;
    return ok;
}

//后插法
status insertEleType(Link* link ,eleType data){
    Link tab = *link;
    if(!tab) return error;
    
    while (tab->next) {
        tab = tab->next;
    }
    
    Link add = malloc(sizeof(Node));
    if(!add) return  error;
    add->data = data;
    add->next = NULL;
    tab->next = add;
    
    return ok;
}


//前提条件，link1,link2都是递增的链表，结果仍仍使用2链表的存储空间，不额外占用空间，不允许重复,结果存link1
void CombinLink(Link* link1,Link* link2){
    //指向首元节点
    Node *p = (*link1)->next;
    Node *q = (*link2)->next;
    Node* r = *link1;
    Node *temp;//用来删除重复节点
    
 
    
    //因为是递增的，首元节点是最小的
    //循环条件是当某一链表到达尾节点结束循环
    while (p && q) {
        if (p->data < q->data) {
            //把小的链到返回链表中
            r->next = p;
            p = p->next;
        }else if(p->data > q->data){
            r->next = q;
            q = q->next;
            
            
        }else{
            temp = q;
            r->next = p;
            p = p->next;
            q = q->next;
            free(temp);
            
        }
        r = r->next;
    }

    //链尾巴
    r->next = p?:q;
    
    //只需要用一个头节点，link2头节点可以删除了
     free(*link2);
    
}

//条件，均是递增链表，求交集存储在link1中
void InterLink(Link* link1,Link* link2){
//指向首元节点
Node *p = (*link1)->next;
Node *q = (*link2)->next;
Node* r = *link1;
    
Node *temp;//用来删除重复节点

    while (p && q) {
        
        if(p->data < q->data){
            //记住是递增关系，所以要找相等，小的应该往后移，查找下一个
            //删除前要先保存
            temp = p;
            p = p->next;
            free(temp);
            
            
        }else if(p->data > q->data){
            //记住是递增关系，所以要找相等，小的应该往后移，查找下一个
            //删除前要临时保存下
            temp = q;
            q = q->next;
            free(temp);
            
        }else{
            //把dd相等值的节点链到返回节点
            r->next = p;
            r = r->next;
            
            p = p ->next;
            
            
            temp = q;
            q= q->next;
            free(temp);
        }
    }

    //删掉尾巴，尾巴肯定是不重复的
    
    //这个是指删掉了一个节点，而应该是删除剩下的所有节点
//    if (p) {
//        free(p);
//    }
//    if (q) {
//        free(q);
//    }
    
    while (p) {
        //先保存一个，等下删完后好赋值
        temp = p->next;
        free(p);
        p = temp;
        
    }
    while (q) {
        //先保存一个，等下删完后好赋值
        temp = q->next;
        free(q);
        q = temp;
        
    }
    
    free(*link2);
    r->next = NULL;
    
}

//条件：原地旋转,要求空间复杂度为O(1)
//考虑前插法
void Inverse(Link *link){
    if (*link == NULL) {
        return;
    }
    
    Link temp = (*link)->next;//指向首元节点
    //把原来的断开
    Link r = *link;
    r->next = NULL;
    Link first = r->next;//保存新链表的首元节点
    Link next;
    //依次取出前插
    while (temp) {

        r->next = temp;
        next = temp->next;
        
        //使前插的节点的next指向新链表的首元节点
        temp->next = first;
        
        first = temp;//刷新现在的头节点
        temp = next;//再赋值下一个节点
        
    }
    
    
}

//截取链表，（left right）区间的节点
//条件，递增链表,就是比较变得简单
//思路，找到，left和right的位置,让首元节点指向left，right节点next=NULL,删除righty剩下的节点
void InterceptList(Link *link,eleType left,eleType right){
    if (*link == NULL) {
        return;
    }
    
    
    Link temp = (*link)->next;
    (*link)->next = NULL;
    
    Link rightPre = NULL;
    
    while (temp) {
        if (temp->data<= left) {
            temp = temp->next;
        }else {
            
            if (temp->data < right) {
                //第一次找到，给头节点链上首元节点
                if ((*link)->next == NULL) {
                    (*link)->next = temp;
                }
               
                rightPre = temp;
                temp = temp->next;
                
            }else{
                //找到>=right，可以退出循环了，
                
                
                Link dele = rightPre->next;
                
                
                while (dele) {
                    Link deleNext = dele->next;
                    free(dele);
                    dele = deleNext;
                }
                
                rightPre->next = NULL;
                
                break;
                
            }
  
        }
        
        
    }
    
}


//一位数组，左移P个位置
/* [0,1,2,3,4,5,6,7,8,9] 左移3 -> [3,4,5,6,7,8,9,0,1,2]*/
/*解决思路：
 1. 数据原地逆转 [9,8,7,6,5,4,3,2,1,0]
 2.从右边开始p个位置截成2段 [9,8,7,6,5,4,3] [2,1,0]
 3.再分别原地逆转 [3,4,5,6,7,8,9] [0,1,2]
 */

void Reverse(int *a ,int left,int right){
    
    while (left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }
}

void leftShift(int *a ,int count,int p){
    
    //原地逆转
    Reverse(a, 0, count-1);
    
    //截成2段， 再分别逆转回去
    
    Reverse(a, 0, count-p-1);
    Reverse(a, count-p, count-1);
    
}


//寻找主元素, 在数组中主元素的数量> n/2，
/* 主元素有个规律，主元素与非主元素配对，一定会多出来,可根据中位数来理解*/

int foundMainElement(int *a,int count){
    
    int num = 1;//以第一个元素为候选主元素
    int main = a[0];
    
    for (int i =1; i<count; i++) {
        if (main == a[i]) {
            num ++;
        }else{
            
            if (num > 0) {
                num--;
            }else{
                
                //更换候选
                main = a[i];
                num = 1;
            }
        }
    }
    
    //如果num >1 说明此元素数量最多
    if (num <= 0) {
        return -1;
    }
    
   //遍历又多少数量
    int mainNum = 0;
    num = 0;
    
    while (num < count) {
        if (a[num] == main) {
            mainNum++;
        }
        num++;
    }
    
    if (mainNum > count/2) {
        return main;
    }
    
    return -1;
    
   
}

//链表的绝对值<=n, 删除绝对值相同的节点，只保留第一次出现的节点
//思路：空间换时间，用一个数组来保存值的状态
void deleEqualNode(Link *link,int n){
    
    int *p = alloca(sizeof(int)*n);
    int i = 0;
    while (i<n) {
        p[i] = 0;
        i++;
        
    }
    
    Link r =*link;//保存节点，在跳过当前节点时需要使用
    
    
    Link temp = (*link)->next;
    while (temp) {
        if(p[abs(temp->data)] == 1){
            //已经出现，删除节点
            r->next = temp->next;//新链表跳过当前节点,指向下一节点
            free(temp);
            temp = r->next;
           
         
            
            
        }else{
            //第一次出现，状态+1
            p[abs(temp->data)] = 1;
            r =temp;//不需改动新链表指向下一个
            temp = temp->next;
            
           
        }
        
        
        
    }
    
    
    
    
}

void travel(Link link){
    
    if (link) {
        Link temp = link->next;
        while (temp) {
            printf("%d\n",temp->data);
            temp = temp->next;
           }
    }
    
   
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    Link a,b;
    initLink(&a);
    initLink(&b);
   
    
    insertEleType(&a, 3);
    insertEleType(&a, 5);
    insertEleType(&a, -7);
     insertEleType(&a, 8);
     insertEleType(&a, 7);
     insertEleType(&a, -7);
    
    insertEleType(&b, 2);
    insertEleType(&b, 5);
    insertEleType(&b, 8);
    
//    CombinLink(&a, &b);
//     InterLink(&a, &b);
//    Inverse(&a);
//    InterceptList(&a, 5, 10);
//    travel(a);
    
    int num[] = {9,1,9,9,4,9,6,9,8,9};
    leftShift(num, sizeof(num)/sizeof(num[0]), 5);
    int main = foundMainElement(num, sizeof(num)/sizeof(num[0]));
    
    deleEqualNode(&a, 8+1);
    
    
    
    return 0;
}
