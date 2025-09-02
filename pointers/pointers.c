// notes to understand pointers in C    
// pointer is a "variable-like" reference that holds memory address to another variable
#include <stdio.h>

int display(int a){
    int *p = &a;

    return *p;
    // OR 
    // return *&a;
}

void ex1(){
    
    int x = 4;
    // integer x stores 4
    int *pX = &x;
    // pointer pX stores the address of variable x
    int y = *pX;
    // integer y stores the value at address pX (which is 4)
   
    int a = 20;
    printf("address of a: %p\n", &a); 
    // & is the address of operator 
    printf("value of a: %d\n", a); 
    
    int *p = &a;
    // * is the dereference operator
    // pointer p is storing the address of variable a
    printf("value of p: %p\n",p);
    printf("value at address p: %d\n", *p);
    printf("%d\n",display(a));
}

void ex2(){
    int x, *y, z, *q;
    x=3;
    y=&x;
    printf("%d\n",x); // 3
    printf("%d\n",y); // address of x
    printf("%d\n",*y); // 3
    printf("%d\n",*y+1); // 4
    printf("%d\n",*(y+1)); // garbage value
    printf("%d\n",*y+*y); // 6
    z=*(&x);
    q=&*y;
    printf("%d\n",z); // 3
    printf("%d\n",q); // address of x
}

 void ex3(){
    int a=5,b=10,arr[5];
    int *ptr;
    ptr=&a; // ptr points to a
    b=*ptr; // b = 5
    *ptr=20;  // a = 20
    ptr=&arr[0]; // ptr points to arr[0]
    *ptr=1; // arr[0] = 1
    *(ptr+1)=2; // arr[1] = 2
    *(ptr+2) = *ptr + *(ptr+1); // arr[2] = 3
    printf("a = %d\n",a); // 20
    printf("b = %d\n",b); // 5
    printf("arr[0] = %d\n",arr[0]); // 1
    printf("arr[1] = %d\n",arr[1]); // 2
    printf("arr[2] = %d\n",arr[2]); // 3
 }

 void ex4(){
    int arr[4]={12,20,39,43};
    int *ptr;
    ptr = &arr[0];  // ptr points to arr[0]
    for(int i=0;i<4;i++){
        printf("%d\n",*(ptr+i)); // prints all elements of arr
    }
    ptr+=2; // ptr now points to arr[2]
    printf("%d\n",*ptr); // prints 39
    *ptr=38;
    printf("%d\n",*ptr-1); // prints 37
    ptr++; // ptr now points to arr[3]
    printf("&d\n",*ptr); // prints 43
    (*ptr)++; // 44
    printf("%d\n",*ptr); // prints 44
 }

 void ex5(){
    // write a program to increment each element of an array using pointers
    int arr[5]={1,2,3,4,5};
    int *ptr=&arr[0];
    for(int i=0;i<5;i++){
        (*ptr)++;
        ptr++;
    }
    for(int i=0;i<5;i++){
        printf("%d\n",arr[i]);
    }
 }
 
 void ex6(){
    // write a program to swap two numbers using pointers
    int a=5,b=10;
    int *p1=&a,*p2=&b;
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
    printf("a = %d\n",a);
    printf("b = %d\n",b);
 }

 void ex7(){
    char str1[] = "welcome";
    char *str2 = "hello";
    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("str1[0] = %c\n", str1[0]);
    printf("str2[0] = %c\n", str2[0]);
    str1[0] = 'W'; // valid
    // str2[0] = 'H'; 
    printf("%s\n", str1);

    char *str3 = str1;
    str3[0] = 'x';
    *(str3+4) = 'y';
    printf("%s\n", str3);
 }  

 void ex8(){
    // pointer to pointer
    int a = 10;
    int *p = &a;
    int **q = &p;
    printf("value of a: %d\n", a);
    printf("value at address p: %d\n", *p);
    printf("value at address q: %d\n", **q);
    printf("address of a: %p\n", &a);
    printf("value of p (address of a): %p\n", p);
    printf("value of q (address of p): %p\n", q);
    printf("address of p: %p\n", &p);
    printf("address of q: %p\n", &q);
 }

void main(){
    // printf("example 1:\n");
    // ex1();
    // prinf("example 2:\n");
    // ex2();
    // printf("example 3:\n");
    // ex3();
    // printf("example 4:\n");
    // ex4();
    // printf("example 5:\n");
    // ex5();
    // printf("example 6:\n");
    // // ex6();
    // printf("example 7:\n");
    // ex7();
    printf("example 8:\n");
    ex8();
}
