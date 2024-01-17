#include <iostream>

class Keeper {
    int trash;
    int secret;

public:
    Keeper() {
        std::cin >> secret;
    }
};

// Ваш код здесь //////////////////////
class Hack {
public:
    int hack_trash, hack_secret;
};

int& hack_it(Keeper &keeper) {
    return ((Hack*)(&keeper))->hack_secret;
};
///////////////////////////////////////

int main() {
    Keeper keeper;
    int secret = hack_it(keeper);
    std::cout << secret;
}