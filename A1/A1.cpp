#include <iostream>
#include <fstream>
#include <cmath>

int main(int argc, const char *argv[])
{
    std::cout << argv[1] << " opened.  " << std::endl;
    int size = 1, subscript = 0;
    double total = 0, avarage = 0, numbers = 0;
    double *fileData = new double[size];
    double *tempData = new double[size];

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
            fileData = new double[size];

            for (int i = 0; i < subscript; i++)
            {
                fileData[i] = tempData[i];
            }

            delete[] tempData;
            tempData = nullptr;
            tempData = new double[size];
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
    std::cout << "\nThe avarage is: " << round(avarage) << "\nValues above avarage are: ";
    for (int i = 0; i < subscript; i++)
    {
        if (fileData[i] > avarage)
        {
            std::cout << round(fileData[i]) << " ";
        }
    }
    std::cin.get();
    tempData = fileData = NULL;
    delete[] fileData, tempData;
}
