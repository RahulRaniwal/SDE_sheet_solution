#include <bits/stdc++.h> 
// merge two array
long long merge(long long *arr , int left , int mid , int right){
    long long inversion = 0;
    int size1 = mid-left+1;
    int size2 = right-mid;
    int arr1[size1];
    int arr2[size2];
    for(int i = 0; i < size1; i++){
        arr1[i] = arr[left+i];
    }
    for(int i = 0; i < size2; i++){
        arr2[i] = arr[mid+1+i];
    }
    
    int i = 0 , j = 0 , k = left;
    while(i < size1 and j < size2){
        if(arr1[i] <= arr2[j]){
            arr[k++] = arr1[i++];
        }else{
            arr[k++] = arr2[j++];
            
            inversion += size1-i;
        }
    }
    
    while(i < size1){
        arr[k++] = arr1[i++];
    }
    while(j < size2){
        arr[k++] = arr2[j++];
    }
    return inversion;
}
// merge sort function
long long mergeSort(long long *arr , int left , int right){
    long long inversion = 0;
    if(left < right){
        int mid = (left+right)/2;
        inversion += mergeSort(arr , left , mid);
        inversion += mergeSort(arr , mid+1 , right);
        inversion += merge(arr , left , mid , right);
    }
    return inversion;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr , 0 , n-1);
}
