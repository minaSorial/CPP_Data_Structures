#include<iostream>

void swap(int array[], int firstIndex, int secondIndex) {

    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex) {

    int swapIndex = pivotIndex;
    for (int i = pivotIndex + 1; i <= endIndex; i++)
    {
        if (array[i] < array[pivotIndex])
        {
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    swap(array, pivotIndex, swapIndex);
    return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex) {

    int pivotIndex = pivot(array, leftIndex, rightIndex);

    if (leftIndex >= rightIndex)
    {
        return;
    }
    quickSort(array, leftIndex, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, rightIndex);
}


int main() {

    int myArry[] = { 10,512,89,15,1117,10,20 };
    int size = sizeof(myArry) / sizeof(myArry[0]);

    int leftIndex = 0;
    int rightIndex = size - 1;
    //int midIndex = (size / 2) - 1;

    quickSort(myArry, leftIndex, rightIndex);
    for (auto value : myArry)
    {
        std::cout << value << " ";
    }


}