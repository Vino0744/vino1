/*************************************************************************
	> File Name: 2.共用体.c
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Jul 2023 07:43:59 PM CST
 ************************************************************************/

//共用体以union开头 

//union register { //4字节  
//  struct {//匿名结构体    
//      unsigned char byte1;
//      unsigned char byte2;
//      unsigned char byte3;
//      unsigned char byte4;
//  } bytes;         
//  unsigned int number;    
//}                  
//                   
//union node { //8字节 
//  double a;        
//  char b;          
//  int c;           
//}      

#include <stdio.h>  

union IP {           
    struct {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } bytes;         
    unsigned int number;
};  

int main() {         
    union IP p;      
    char str[20] = {0};
    scanf("%s", str);
    int arr[4] = {0};
    sscanf(str, "%d.%d.%d.%d", &arr[0], &arr[1], &arr[2], &arr[3]);
    //小端机倒着存
    p.bytes.byte1 = arr[3];
    p.bytes.byte2 = arr[2];
    p.bytes.byte3 = arr[1];
    p.bytes.byte4 = arr[0];
    printf("%u\n", p.number);
    return 0;
}                        
