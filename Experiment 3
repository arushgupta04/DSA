#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main () {
int N;
scanf("%d ",&N);
int arr[N];
for (int i=0;i<N;i++){
    scanf("%d ",&arr[i]);
}
int num;
scanf("%d",&num);
for(int i=0;i<N;i++){
    if(arr[i]==num){
        for(int j=i;j<N-1;j++){
            arr[j]=arr[j+1];
        }
    N--;
    break;
}
}
for(int i=0;i<N;i++){
    printf("%d ",arr[i]);
}
    return 0;
}
