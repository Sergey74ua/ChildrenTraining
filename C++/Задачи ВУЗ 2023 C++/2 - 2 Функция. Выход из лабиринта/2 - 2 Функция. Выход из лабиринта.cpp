// Дан код, который определяет, достижим ли выход из лабиринта из заданной точки старта.И если это так, выводит YES, иначе NO :
/*
YES
3 7
7 10
*//*
NO
5 5
7 10
##########
#     #  E
#  ## ## #
# #     ##
#  ##### #
#  #     #
#E########
*/

#include <iostream>
#include <vector>
#include <string>

bool is_can_exit_from_maze(std::vector<std::string> maze, int row, int col) {
    std::vector<std::tuple<int, int>> w; //НУЖЕН МАССИВ (Вектор) с координатами
    w.push_back(<row, col>);
    if (maze[row][col] == 'E')
        return true;
    else
        maze[row][col] == '.';

    for (int y = 0; y < maze.size(); y++) {
        for (int x = 0; x < maze[y].size(); x++) {
            std::cout << maze[y][x];
        }
        std::cout << std::endl;
    }

    return false;
}

int main() {
    int row, col, rows, cols;
    std::cin >> row >> col >> rows >> cols;
    std::cin.ignore(1); // Игнорируем перевод строки, застрявший в потоке ввода

    std::vector<std::string> maze(rows);
    for (auto& line : maze) std::getline(std::cin, line);

    std::cout << (is_can_exit_from_maze(maze, row, col) ? "YES" : "NO") << std::endl;
}