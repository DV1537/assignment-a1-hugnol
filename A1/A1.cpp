#include <iostream>
#include <fstream>

int main()
{
    int size = 1, numbers = 0, subscript = 0, total = 0, avarage = 0;
    int *fileData = new int[size];
    int *tempData = new int[size];

    std::ifstream inputStream;
    inputStream.open("number.txt");

    while ((inputStream >> numbers) && !(std::cin.fail())) //If the instream reads a non integer value, the loop will exit.
    {
        if (subscript > size)
        {
            for (int i = 0; i < subscript; i++)
            {
                tempData[i] = fileData[i];
            }

            fileData = NULL;
            delete[] fileData;
            fileData = new int[subscript];

            for (int i = 0; i < subscript; i++)
            {
                fileData[i] = tempData[i];
            }

            tempData = NULL;
            delete[] tempData;
            tempData = new int[subscript];

            size = subscript;
        }
        fileData[subscript] = numbers;
        subscript++;
    }
    for (int i = 0; i < subscript; i++)
    {
        total += fileData[i];
    }
    avarage = total / subscript;
    for (int i = 0; i < subscript; i++)
    {
        if (fileData[i] > avarage)
        {
            std::cout << fileData[i] << " ";
        }
    }

    std::system("pause");

    inputStream.close();
    tempData = fileData = NULL;
    delete[] fileData, tempData;
}
