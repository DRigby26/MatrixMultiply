#include <iostream>

int size;

int main() {


    srand((unsigned int)time(NULL));
    std::cout << " give the size of the array"<<std::endl;
    std::cin>>size;

    double **matrix1 = new double*[size];
    double **matrix2 = new double*[size];
    for(int n = 0; n < size; n++)
    {
        matrix1[n] = new double[size];
        matrix2[n] = new double[size];
    }

    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = matrix1[i][j];        }
    }



    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << matrix2[i][j] << ' ';

        }
        std::cout << std::endl;
    }


    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << matrix1[i][j] << ' ';
        }
        std::cout << std::endl;
    }


    return 0;
}

