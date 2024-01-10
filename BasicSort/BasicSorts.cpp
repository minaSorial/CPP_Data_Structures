#include <iostream>

void bubbleSort(int array[], int size)
{

    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


void selectionSort(int array[], int size) {

    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }




}

void insertionSort(int array[], int size) {

    for (int i = 0; i < size; i++)
    {
        int temp = array[i];
        int j = i - 1;
        while (j > -1 && temp < array[j])
        {
            array[j + 1] = array[j];
            array[j] = temp;
            j--;
        }

    }



}
void printArray(int array[], int size)
{

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }
}

int main()
{
    // int size = 6;
    int num[] = { 4, 2, 6, 5, 1, 3 };
    int size = sizeof(num) / sizeof(num[0]);
    //bubbleSort(num, size);
    //selectionSort(num, size);
    insertionSort(num, size);
    printArray(num, size);
}