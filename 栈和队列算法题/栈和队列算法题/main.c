//
//  main.c
//  栈和队列算法题
//
//  Created by  RWLi on 2020/4/16.
//  Copyright © 2020  RWLi. All rights reserved.
//

/*
 
 实现下⾯算法题:
 括号匹配检验: (字节出现过的算法⾯试题/LeetCode) 假设表达式中允许包含两种括号:圆括号与⽅括号,其嵌套顺序随意,即([]()) 或者[([][])]都是正 确的.⽽这[(]或者(()])或者([()) 都是不正确的格式. 检验括号是否匹配的⽅法可⽤”期待的急迫 程度"这个概念来描述.例如,考虑以下括号的判断: [ ( [ ] [ ] ) ]
 
 每⽇⽓温: (LeetCode-中等) 题⽬: 根据每⽇⽓温列表，请重新⽣成⼀个列表，对应位置的输⼊是你需要再等待多久温度才 会升⾼超过该⽇的天数。如果之后都不会升⾼，请在该位置0来代替。例如，给定⼀个列 表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。提示：⽓温 列表⻓度的范围是 [1, 30000]。每个⽓温的值的均为华⽒度，都是 在 [30, 100] 范围内的整数 1
 
爬楼梯问题:(LeetCode-中等) 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不 同的⽅法可以爬到楼顶呢？注意：给定 n 是⼀个正整数å
 
 去除重复字⺟(LeetCode-困难) 给你⼀个仅包含⼩写字⺟的字符串，请你去除字符串中重复的字⺟，使得每个字⺟只出现⼀ 次。需保证返回结果的字典序最⼩（要求不能打乱其他字符的相对位置）
 
 字符串编码(LeetCode-中等) 给定⼀个经过编码的字符串，返回它解码后的字符串。 编码规则为: k[encoded_string]，表示其中⽅括号内部的 encoded_string 正好重复 k 次。 注意 k 保证为正整数。你可以认为输⼊字符串总是有效的；输⼊字符串中没有额外的空格， 且输⼊的⽅括号总是符合格式要求的。此外，你可以认为原始数据不包含数字，所有的数字只 表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输⼊。 例如: s = "12[a]2[bc]", 返回 "aaabcbc". s = "3[a2[c]]", 返回 "accaccacc". s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef
 
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum{error,ok} status;
typedef char DataType;
//typedef int DataType;
#define MAXSIZE 50
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
//status popNode(stackNode *node,DataType *data){
//    if(!node)return error;
//    if(node->top== -1) return error;//空栈
//    *data = node->data[node->top];
//    node->top--;
//    return ok;
//}
status popNode(stackNode *node){
    if(!node)return error;
    if(node->top== -1) return error;//空栈
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
 

#pragma mark -  括号匹配检验
//[ ( [ ] [ ] ) ]
//思路： 左括号入栈，判断下一个是否是栈顶的右边，是就出栈，否就再入栈，再用下一个元素是否是栈顶的右边继续判断下去，直到最后栈为空，表示匹配，不为空不匹配
//void checkBrackets(char* source ,int length){
//    
//    stackNode stack;
//    initStackNode(&stack);
//    
//    for (int i =0; i<length; i++) {
//        
//        if (source[i] == '\0') {
//            break;
//        }
//        
//        if (isEmpty(stack)== ok) {
//            pushNode(&stack, source[i]);
//        }else{
//            
//           
//            char top = stack.data[stack.top];
//            if (top == '[') {
//                if (source[i] == ']') {
//                    popNode(&stack);
//                }else{
//                    pushNode(&stack, source[i]);
//                }
//            }else if (top == '('){
//                if (source[i] == ')') {
//                    popNode(&stack);
//                }else{
//                    pushNode(&stack, source[i]);
//                }
//            }else if (top == '{'){
//                if (source[i] == '}') {
//                    popNode(&stack);
//                }else{
//                    pushNode(&stack, source[i]);
//                }
//            }else{
//                
//            }
//            
//        }
//    }
//    
//    if (isEmpty(stack)) {
//        printf("括号是匹配的\n");
//    }else{
//        printf("括号是不匹配的\n");
//    }
//    
//}


#pragma mark - 每⽇⽓温:
//temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]
//思路：从后面开始压栈进行比较,比较时，从栈顶开始比较
//但是感觉这种方法跟2个for循环没有啥区别，

//void outputTemperatures(int *temperatures,int length,int* output ){
//    stackNode stack;
//    initStackNode(&stack);
//    for (int i = length-1; i>=0; i--) {
//
//        if (i == length-1) {
//            output[length-1] = 0;
//            pushNode(&stack, temperatures[i]);
//        }else{
//            int top = stack.top;
//            int count = 0;
//
//            while (top !=-1) {
//                count++;
//                if (temperatures[i]<stack.data[top]) {
//                    break;
//                }
//                top--;
//            }
//            if (top == -1) {
//                //没有找到
//                count = 0;
//            }
//
//            output[i] = count;
//            pushNode(&stack, temperatures[i]);
//        }
//
//    }
//}


#pragma mark - 爬楼梯

//int caculateMethodCount(int maxStep ,int height){
//
//    if (maxStep <= 0 || height <=0) return 0;
//
//    //　出口
//    if (height==1) {
//        return 1;
//    }else{
//
//
//
//    }
//
//
//
//
//
//
//
//}

#pragma mark - 字符串编码
//s = "3[a2[cd]]", 返回 "acdcdacdcdacdcd"
//0:48
 void decodeBM(char *code,char *out){
    
    
    stackNode countNode;//记录重复次数的
    initStackNode(&countNode);
    
    stackNode indexNode;//记录重复字符开始位置
    initStackNode(&indexNode);
    
    stackNode node;//输出
    initStackNode(&node);
    
    
    
    
    char* count = malloc(sizeof(char)*10);
    char *number = count;
    
    
    
    while (*code) {
        if (*code >=48 && *code <= 57 ) {
            //数字
            *number = *code;
            number++;
           
            
        }else if (*code == '['){
            //入栈要开始了,压栈数字
            *number = '\0';
            number = count;
            int s = 0;
            int w = 1;
           
            while (*number) {
                int n = *number-48;
                s = s*w+n;
                //不考虑首位为0的情况
                w*=10;
                number++;
            }
            
            number = count;
            pushNode(&countNode, s);//数量
            pushNode(&indexNode, node.top+1);//记录字符[之后入栈的位置
            
             
            
            
            
        }else if (*code == ']'){
            //处理1之后剩余次数
            int start = indexNode.data[indexNode.top];
            int end = node.top;
            popNode(&indexNode);
            
            int count = countNode.data[countNode.top];
            popNode(&countNode);
            
            
            
            for (int i =1; i<count; i++) {
                for (int j = start; j<=end; j++) {
                    pushNode(&node, node.data[j]);
                }
                
            }
            
            
        }else{
            
            pushNode(&node, *code);
            
            
            
        }
        
        code++;
    }
    
    
    if (isEmpty(node) == error) {
        for (int i =0 ; i<= node.top; i++) {
            out[i] = node.data[i];
        }
    }
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    // 题一
//    char brackets[] = "{}{[[()()]]}";
//    checkBrackets(brackets, sizeof(brackets));
    
    // 题二
//    int temperatures[] = {73,74,75,71,69,72,76,73};
//    int output[8];
//    outputTemperatures(temperatures, sizeof(temperatures)/sizeof(temperatures[0]),output);
    
    //字符编码
    char *zifu = "3[a2[c2[d]]]";
    char out[100];
    decodeBM(zifu,out);
    printf("%s\n",out);
    
    return 0;
}
