#include <iostream>
#include <tuple>

int** new_matrix(int rows, int cols, int value = 0);
std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows = 3, int ccols = 3);
std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols);
std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value = 1);
std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value = 1);
void delete_matrix(int*** matrix, int rows);
void print(int** matrix, int rows, int cols);

int main() {
    int rows_first, cols_first, first_init_val,
        rows_core, cols_core;

    std::cin >> rows_first >> cols_first >> first_init_val;
    int** first = new_matrix(rows_first, cols_first, first_init_val);
    for (int i = 0; i < rows_first; i++)
        for (int j = 0; j < cols_first; j++)
            std::cin >> first[i][j];

    std::cin >> rows_core >> cols_core;
    int** core = new_matrix(rows_core, cols_core);
    for (int i = 0; i < rows_core; i++)
        for (int j = 0; j < cols_core; j++)
            std::cin >> core[i][j];

    auto [conv, rows_conv, cols_conv] = convolution(first, rows_first, cols_first, core);

    std::tie(rows_conv, cols_conv) = add_row(&conv, rows_conv, cols_conv);
    std::tie(rows_conv, cols_conv) = add_col(&conv, rows_conv, cols_conv);
    std::tie(rows_conv, cols_conv) = add_col(&conv, rows_conv, cols_conv);

    auto [mult, rows_mult, cols_mult] = multiplication(conv, rows_conv, cols_conv, first, rows_first, cols_first);

    print(mult, rows_mult, cols_mult);

    delete_matrix(&first, rows_first);
    delete_matrix(&conv, rows_conv);
    delete_matrix(&mult, rows_mult);
}

// Ваш код будет вставлен сюда

int** new_matrix(int rows, int cols, int value) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value;
        };
    };

    return matrix;
}

std::tuple<int**, int, int> convolution(int** matrix, int mrows, int mcols, int** core, int crows, int ccols) {
    int rows_conv = mrows - crows + 1;
    int cols_conv = mcols - ccols + 1;
    int** conv = new_matrix(rows_conv, cols_conv);

    for (int i = 0; i < rows_conv; i++) {
        for (int j = 0; j < cols_conv; j++) {
            int sum = 0;
            for (int k = 0; k < crows; k++) {
                for (int l = 0; l < ccols; l++) {
                    sum += matrix[i + k][j + l] * core[k][l];
                };
            };
            conv[i][j] = sum;
        };
    };

    return std::make_tuple(conv, rows_conv, cols_conv);
}

std::tuple<int**, int, int> multiplication(int** a, int arows, int acols, int** b, int brows, int bcols) {
    if (acols != brows) {
        std::cerr << "Error: Matrices dimensions are not compatible for multiplication." << std::endl;
        return std::make_tuple(nullptr, 0, 0);
    };

    int** mult = new_matrix(arows, bcols);

    for (int i = 0; i < arows; i++) {
        for (int j = 0; j < bcols; j++) {
            int sum = 0;
            for (int k = 0; k < acols; k++) {
                sum += a[i][k] * b[k][j];
            };
            mult[i][j] = sum;
        };
    };

    return std::make_tuple(mult, arows, bcols);
};

std::tuple<int, int> add_row(int*** matrix, int rows, int cols, int value) {
    int** temp = new int* [rows + 1];
    for (int i = 0; i < rows; i++) {
        temp[i] = (*matrix)[i];
    };
    temp[rows] = new int[cols];
    for (int j = 0; j < cols; j++) {
        temp[rows][j] = value;
    };
    delete[] * matrix;
    *matrix = temp;

    return std::make_tuple(rows + 1, cols);
}

std::tuple<int, int> add_col(int*** matrix, int rows, int cols, int value) {
    int** temp = new int* [rows];
    for (int i = 0; i < rows; i++) {
        temp[i] = new int[cols + 1];
        for (int j = 0; j < cols; j++) {
            temp[i][j] = (*matrix)[i][j];
        };
        temp[i][cols] = value;
    };
    for (int i = 0; i < rows; i++) {
        delete[](*matrix)[i];
    };
    delete[] * matrix;
    *matrix = temp;

    return std::make_tuple(rows, cols + 1);
};

void delete_matrix(int*** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[](*matrix)[i];
    };
    delete[] * matrix;
    *matrix = nullptr;
};

void print(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        };
        std::cout << std::endl;
    };
};
//