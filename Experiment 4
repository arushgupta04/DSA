#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
void delete(int*arr,int*size){
    int value,i,j;
    scanf("%d",&value);
    for(i=0;i<(*size);){
        if(arr[i]==value){
            for (j=i;j<(*size)-1;j++){
                arr[j]=arr[j+1];
            }
            (*size)--;
        }
        else 
        i++;
        
    }
    
}
void printlist(int*arr,int n){
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++)
        scanf("%d",&arr[i]);
    delete(arr,&n);
    printlist(arr,n);

    return 0;
}
