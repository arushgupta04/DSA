#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10000
int main() {
    char stack[MAX];
    char  s[MAX];
    int top =-1;
    scanf("%s",s);
    for (int i=0;s[i]!='\0';i++){
        if(top>=0 && stack[top]==s[i]){
        top--;
    }
    else {
        stack[++top]=s[i];
    }
    }
for (int i =0;i<=top;i++){
    printf("%c",stack[i]);
    
}
return 0;
}
