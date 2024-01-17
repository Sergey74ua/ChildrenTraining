#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> matrix[i][j];

    //Меняем значения краев матрицы
    for (int i = 1; i < n-1; i++) {
        int temp = matrix[0][i];
        matrix[0][i] = matrix[i][0];
        matrix[i][0] = matrix[n-1][n-i-1];
        matrix[n-1][n-i-1] = matrix[n-i-1][n-1];
        matrix[n-i-1][n-1] = temp;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}