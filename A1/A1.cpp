#include <iostream>
#include <fstream>
#include <cmath>

int main(int argc, const char *argv[])
{
    std::cout << argv[1] << " opened. " << std::endl;
    int size = 1, numbers = 0, subscript = 0, total = 0, avarage = 0;
    int *fileData = new int[size];
    int *tempData = new int[size];

    std::ifstream inputStream;
    inputStream.open(argv[1]);

    while ((inputStream >> numbers) && !(std::cin.fail())) //If the instream reads a non integer value, the loop will exit.
    {
        if (subscript == size)
        {
            size++;
            for (int i = 0; i < subscript; i++)
            {
                tempData[i] = fileData[i];
            }

            delete[] fileData;
            fileData = nullptr;
            fileData = new int[size];

            for (int i = 0; i < subscript; i++)
            {
                fileData[i] = tempData[i];
            }

            delete[] tempData;
            tempData = nullptr;
            tempData = new int[size];
        }
        fileData[subscript] = numbers;
        subscript++;
    }
    inputStream.close();
    for (int i = 0; i < subscript; i++)
    {
        total += fileData[i];
    }
    avarage = total / subscript;
    for (int i = 0; i < subscript; i++)
    {
        if (fileData[i] > avarage)
        {
            std::cout << std::round(fileData[i]) << " ";
        }
    }
    std::cin.get();
    tempData = fileData = NULL;
    delete[] fileData, tempData;
}
