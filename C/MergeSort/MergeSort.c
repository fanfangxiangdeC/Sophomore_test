#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int check(int n,int a[]);
void MergeSort(int a[],int n);
void MergePass(int a[],int b[],int s,int n);
void Merge(int a[],int b[],int l,int m,int r); 

int main(int argc, char *argv[]) {
    int n,*a;
    scanf("%d",&n);
    a = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    struct timeval stop,start;
    gettimeofday(&start,NULL);
    MergeSort(a,n);
    gettimeofday(&stop,NULL);
    printf("took %lu us\n",(stop.tv_sec-start.tv_sec)*1000000+stop.tv_usec-start.tv_usec);
    return 0;
}
void MergeSort(int a[],int n){
    int *b =malloc(sizeof(int)*n);
    int s=1;
    while(s<n){
        MergePass(a,b,s,n);
        s+=s;
        MergePass(b,a,s,n);
        s+=s;
    }
    printf("MergeSort Succeed!\n");
}
void MergePass(int a[],int b[],int s,int n){
    int i=0;
    while(i<=n-2*s){
        Merge(a,b,i,i+s-1,i+2*s-1);
        i=i+2*s;
    }
    if(i+s<n)
        Merge(a,b,i,i+s-1,n-1);
    else
        for(int j=i;j<=n-1;j++)
            b[j]=a[j];
}

void Merge(int a[],int b[],int l,int m,int r){
    int i=l,j=m+1,k=l;
    while((i<=m)&&(j<=r)){
        if(a[i]<=a[j])
            b[k++]-a[i++];
        else
            b[k++]=a[j++];
        if(i>m){
            for(int q=j;q<=r;q++)
                b[k++]=a[q];
        }
        else{
            for(int q=i;q<=m;q++)
                b[k++]=a[q];
        }
    }

}



int check(int n,int a[]){
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1])
            return 0;
    }
    return 1;
}