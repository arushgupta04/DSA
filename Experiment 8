#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX],top = -1;
void push(int value){
    if (top==MAX-1){
        return ;
    }
    else{
        stack[++top]=value;
    }
}
void pop()
{
    if (top== -1)
        return ;
    else{
        top--;
    }
    
}
void show(){
    if(top == -1)
    return;
    else{
        int i;
        for(i=top;i>=0;i--)
            printf("%d ",stack[i]);
        
    }
}
int main() {
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        int value;
        scanf("%d",&value);
        push(value);
    }
    pop();pop();
    for(int i = 0;i < 4;i++){
        int value;
        scanf("%d",&value);
        push(value);
    }
    pop();
    for(int i = 0;i < 2;i++)
    {
        int value;
        scanf("%d",&value);
        push(value);
    }
    for (int i = 0;i < 3;i++)
    {
        pop();
    }
    show();

        
    return 0;
}
