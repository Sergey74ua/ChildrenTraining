#include <iostream>

int main() {
    int n, i = 1, w = 3, s = 1, k = 1;
    std::cin >> n;
    system("cls");
    while (i <= n) {
        for (int j = 0; j < k && i <= n; ++j)
            std::cout << i++ << " ";
        std::cout << std::endl;
        k += s;
        if (k < 1) {
            s = 1;
            k = 2;
            ++w;
        }
        else if (k >= w) {
            s = -1;
            k -= 2;
        }
    }
    return 0;
}