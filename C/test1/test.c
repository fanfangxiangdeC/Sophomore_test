#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
void Bubble(int n, int a[]);
int check(int n,int a[]); 

int main(int argc, char *argv[]) {
    int n,*a;
    scanf("%d",&n);
    a = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    struct timeval stop,start;
    gettimeofday(&start,NULL);
    Bubble(n,a);
    gettimeofday(&stop,NULL);
    printf("took %lu us\n",(stop.tv_sec-start.tv_sec)*1000000+stop.tv_usec-start.tv_usec);
    return 0;
}
void Bubble(int n, int a[]){
    int x;
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
            }
        }
    if(check(n,a))
        printf("Bubble Sort Succeed\n");
    else
        printf("Bubble Sort Failed!\n");

}
int check(int n,int a[]){
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1])
            return 0;
    }
    return 1;
}