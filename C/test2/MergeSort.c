#include <stdio.h>  
#include <stdlib.h>  
#include <sys/time.h>
void merge(int arr[], int l, int m, int r) {  
    int i, j, k;  
    int n1 = m - l + 1;  
    int n2 = r - m;  
  
    /* 创建临时数组 */  
    int L[n1], R[n2];  
  
    /* 拷贝数据到临时数组 L[] 和 R[] */  
    for (i = 0; i < n1; i++)  
        L[i] = arr[l + i];  
    for (j = 0; j < n2; j++)  
        R[j] = arr[m + 1 + j];  
  
    /* 合并临时数组回 arr[l..r] */  
    i = 0;   
    j = 0;   
    k = l;   
    while (i < n1 && j < n2) {  
        if (L[i] <= R[j]) {  
            arr[k] = L[i];  
            i++;  
        }  
        else {  
            arr[k] = R[j];  
            j++;  
        }  
        k++;  
    }  
  
    /* 拷贝 L[] 的剩余元素到 arr[l..r] */  
    while (i < n1) {  
        arr[k] = L[i];  
        i++;  
        k++;  
    }  
  
    /* 拷贝 R[] 的剩余元素到 arr[l..r] */  
    while (j < n2) {  
        arr[k] = R[j];  
        j++;  
        k++;  
    }  
}  
  
void mergeSort(int arr[], int l, int r) {  
    if (l < r) {  
        // 找到中间点  
        int m = l + (r - l) / 2;  
  
        // 对左半边排序  
        mergeSort(arr, l, m);  
  
        // 对右半边排序  
        mergeSort(arr, m + 1, r);  
  
        // 合并结果  
        merge(arr, l, m, r);  
    }  
}  
  
int main() {  
    int n,*a;
    scanf("%d",&n);
    a = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    struct timeval stop,start;
    gettimeofday(&start,NULL);
    mergeSort(a,0,n-1);
    gettimeofday(&stop,NULL);
    printf("took %lu us\n",(stop.tv_sec-start.tv_sec)*1000000+stop.tv_usec-start.tv_usec);
    return 0;
    return 0;  
}