#pragma once
#include <vector>

// Default: sort by ascending order if no function is passed.
template <typename T, typename Compare = std::less<T>>
void merge_sort(std::vector<T>& arr, int left, int right, Compare comp = Compare());

template <typename T, typename Compare>
void merge(std::vector<T>& arr, int left, int mid, int right, Compare comp) {
    int l = mid - left + 1;
    int r = right - mid;
    
    std::vector<T> L(l), R(r);

    for(size_t i = 0;i < l; i++) {
        L[i] = arr[left + i];
    }

    for(size_t j = 0; j<r; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while(i < l && j < r) {
        if(comp(L[i], R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < l) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < r) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T, typename Compare>
void merge_sort(std::vector<T>& arr, int start, int end, Compare comp) {
    if(start >= end) {
        return;
    }   
    int mid = (start + end) / 2;
    merge_sort(arr,start,mid, comp);
    merge_sort(arr, mid+1, end, comp);
    merge(arr, start, mid, end, comp);
}