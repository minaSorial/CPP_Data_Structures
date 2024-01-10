#include<iostream>

void merge(int arrry[], int leftIndex, int midIndex, int rightIndex) {

    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
    {
        leftArray[i] = arrry[leftIndex + i];
    }

    for (int j = 0; j < rightArraySize; j++)
    {
        rightArray[j] = arrry[midIndex + 1 + j];
    }


    int index = leftIndex;
    int i = 0;
    int j = 0;

    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arrry[index] = leftArray[i];
            index++;
            i++;
        }
        else {
            arrry[index] = rightArray[j];
            index++;
            j++;
        }
    }

    while (i < leftArraySize)
    {
        arrry[index] = leftArray[i];
        index++;
        i++;
    }

    while (j < leftArraySize)
    {
        arrry[index] = rightArray[j];
        index++;
        j++;
    }
}

void mergeSort(int array[], int leftIndex, int rightIndex) {

    if (leftIndex >= rightIndex) return;
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex + 1, rightIndex);
    merge(array, leftIndex, midIndex, rightIndex);
}



int main() {

    int myArry[] = { 10,512,89,15,1117,10,20 };
    int size = sizeof(myArry) / sizeof(myArry[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;
    int midIndex = (size / 2) - 1;

    mergeSort(myArry, leftIndex, rightIndex);
    for (auto value : myArry)
    {
        std::cout << value << " ";
    }


}