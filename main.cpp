#include <iostream>

size_t size;

size_t **matrixMultiplier(size_t **matrix1, size_t **matrix2);

int main() {

    int N;

    srand((unsigned int) time(NULL));
    std::cout << " give the size of the array" << std::endl;
    std::cin >> size;
    std::cout << "How many times should I multiply? " << std::endl;
    std::cin >> N;

    size_t **matrix1 = new size_t *[size];
    size_t **matrix2 = new size_t *[size];

    for (int n = 0; n < size; n++) {
        matrix1[n] = new size_t[size];
        matrix2[n] = new size_t[size];
        // finalMatrix[n] = new double[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix1[i][j] = (size_t) rand() % 10;
            matrix2[i][j] = matrix1[i][j];
        }
    }

    size_t **result = matrixMultiplier(matrix1, matrix2);

    while (0 < N - 2) {
        result = matrixMultiplier(result, matrix1);

        N--;
    }


    printf("The first array is \n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix1[i][j] << ' ';

        }
        std::cout << std::endl;
    }

    printf("The second array is \n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix2[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    printf("results are : \n");

    for (int h = 0; h < size; h++) {
        for (int w = 0; w < size; w++) {
            printf("%lu,", result[h][w]);
        }
        printf("\n");
    }

    // clean up memory
    printf("\n");
    printf("Cleaning up memory...\n");
    for (int h = 0; h < size; h++) {
        delete[] result[h];
    }
    delete[] result;
    result = 0;
    printf("Ready.\n");


    return 0;
}

size_t **matrixMultiplier(size_t **matrix1, size_t **matrix2) {
    size_t **resultMatrix = new size_t *[size];

    for (int n = 0; n < size; n++) {
        resultMatrix[n] = new size_t[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < size; ++k)
                resultMatrix[i][j] = resultMatrix[i][j] + (matrix1[i][k] * matrix2[k][j]);

        }

    }

    return resultMatrix;

}


