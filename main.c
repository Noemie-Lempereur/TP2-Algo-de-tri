#include <stdio.h>
#include "tri.h"

int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
    int output[size + 1];
    int count[10];

    for (int i = 0; i < 10; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    // Calculate cummulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--) {
        int d=count[(array[i] / place) % 10];
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
    // Get maximum element
    int max = getMax(array, size);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

int main() {
    int table[23]={1034,48,7,4,21,42,945,3,433,5,648,5,49,4354,49,673,9,675,54,345,8,6,3};
    int table2[23]={3,3,4,5,5,6,7,8,9,21,42,48,49,49,54,345,433,648,673,675,945,1034,4354};

    radixsort(table,23);
    //Tri_Base(table,23);
    for(int i=0;i<23;i++){
        printf("%d _ ",table[i]);
    }
    printf("\n");
    for(int i=0;i<23;i++){
        printf("%d _ ",table2[i]);
    }
    printf("\n");
    printf("ok");
    return 0;
}

