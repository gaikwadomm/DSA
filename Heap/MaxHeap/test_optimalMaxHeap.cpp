#include <iostream>
#include <cassert>
#include<bits/stdc++.h>
using namespace std;

// Declaration of BuildMaxHeap from the implementation file
void BuildMaxHeap(int arr[], int n);

// Helper function to check if array is a max heap
bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] < arr[left]) return false;
        if (right < n && arr[i] < arr[right]) return false;
    }
    return true;
}

void test_basic() {
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_sorted_input() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_reverse_sorted_input() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_all_equal() {
    int arr[] = {5, 5, 5, 5, 5, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_single_element() {
    int arr[] = {42};
    int n = 1;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_empty() {
    int arr[] = {};
    int n = 0;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_two_elements_increasing() {
    int arr[] = {1, 2};
    int n = 2;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_two_elements_decreasing() {
    int arr[] = {2, 1};
    int n = 2;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_three_elements_all_equal() {
    int arr[] = {7, 7, 7};
    int n = 3;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_three_elements_distinct() {
    int arr[] = {3, 1, 2};
    int n = 3;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_large_values() {
    int arr[] = {INT_MAX, INT_MIN, 0, INT_MAX - 1, INT_MIN + 1};
    int n = 5;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_alternating_high_low() {
    int arr[] = {1, 100, 2, 99, 3, 98, 4, 97};
    int n = 8;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_negative_numbers() {
    int arr[] = {-1, -3, -2, -7, -6, -5, -4};
    int n = 7;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_mixed_positive_negative() {
    int arr[] = {0, -1, 1, -2, 2, -3, 3};
    int n = 7;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_large_heap() {
    const int n = 1000;
    int arr[n];
    for (int i = 0; i < n; ++i) arr[i] = n - i;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_heap_with_duplicates() {
    int arr[] = {5, 1, 5, 3, 5, 2, 5};
    int n = 7;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_heap_with_min_int() {
    int arr[] = {INT_MIN, INT_MIN, INT_MIN};
    int n = 3;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_heap_with_max_int() {
    int arr[] = {INT_MAX, INT_MAX, INT_MAX};
    int n = 3;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_heap_with_one_large_rest_small() {
    int arr[] = {1, 1, 1, 1, 1000};
    int n = 5;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_heap_with_one_small_rest_large() {
    int arr[] = {1000, 1000, 1000, 1000, 1};
    int n = 5;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_heap_with_alternating_signs() {
    int arr[] = {1, -1, 2, -2, 3, -3, 4, -4};
    int n = 8;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_heap_with_odd_size() {
    int arr[] = {7, 3, 5, 1, 9};
    int n = 5;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_heap_with_even_size() {
    int arr[] = {8, 4, 6, 2, 10, 12};
    int n = 6;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

void test_heap_with_large_gap() {
    int arr[] = {1000000, 1, 2, 3, 4, 5};
    int n = 6;
    BuildMaxHeap(arr, n);
    assert(isMaxHeap(arr, n));
}

int main() {
    test_basic();
    test_sorted_input();
    test_reverse_sorted_input();
    test_all_equal();
    test_single_element();
    test_empty();
    test_two_elements_increasing();
    test_two_elements_decreasing();
    test_three_elements_all_equal();
    test_three_elements_distinct();
    test_large_values();
    test_alternating_high_low();
    test_negative_numbers();
    test_mixed_positive_negative();
    test_large_heap();
    test_heap_with_duplicates();
    test_heap_with_min_int();
    test_heap_with_max_int();
    test_heap_with_one_large_rest_small();
    test_heap_with_one_small_rest_large();
    test_heap_with_alternating_signs();
    test_heap_with_odd_size();
    test_heap_with_even_size();
    test_heap_with_large_gap();
    cout << "All tests passed!" << endl;
    return 0;
}