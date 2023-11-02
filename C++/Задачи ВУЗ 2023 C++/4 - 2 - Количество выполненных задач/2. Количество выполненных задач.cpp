#include <iostream>
#include <fstream>
#include "json.hpp"

int main() {
    std::ifstream i("data.json");
    nlohmann::json j;
    i >> j;

    int user_id;
    std::cin >> user_id;

    int completed_tasks = 0;
    for (const auto& project : j) {
        for (const auto& task : project["tasks"]) {
            if (task["user_id"] == user_id && task["completed"] == true) {
                completed_tasks++;
            }
        }
    }

    std::cout << completed_tasks << std::endl;

    return 0;
}