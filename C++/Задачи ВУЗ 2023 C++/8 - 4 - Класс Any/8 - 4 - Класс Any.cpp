#include <iostream>
#include <string>
#include <vector>

class Any {
    enum class Type {
        INT,
        DOUBLE,
        STRING,
        VECTOR_ANY_PTR
    };

    void* data;
    Type type;

public:
    Any(int* data);
    Any(double* data);
    Any(std::string* data);
    Any(std::vector<Any*>* data);
    ~Any();

    operator int();
    operator double();
    operator std::string();
    operator std::vector<Any*>*();

    friend std::ostream& operator<<(std::ostream& out, const Any& val);
};

std::ostream& operator<<(std::ostream& out, const Any& o);

int main() {
    Any data(new std::vector<Any*>());

    std::vector<Any*>* array = (std::vector<Any*>*)data;

    int ints_count;
    std::cin >> ints_count;
    for (int i = 0; i < ints_count; i++) {
        int value;
        std::cin >> value;
        Any* temp = new Any(new int(value));
        array->push_back(temp);
    }

    int doubles_count;
    std::cin >> doubles_count;
    for (int i = 0; i < doubles_count; i++) {
        double value;
        std::cin >> value;
        Any* temp = new Any(new double(value));
        array->push_back(temp);
    }

    int strings_count;
    std::cin >> strings_count;
    for (int i = 0; i < strings_count; i++) {
        std::string value;
        std::cin >> value;
        Any* temp = new Any(new std::string(value));
        array->push_back(temp);
    }

    int i = 0; double d = 0; std::string s = "";
    for (auto value : *array) {
        try { i += (int)(*value); }
        catch (...) {}

        try { d += (double)(*value); }
        catch (...) {}

        try { s += (std::string)(*value); }
        catch (...) {}
    }

    Any ai(new int(i));
    Any ad(new double(d));
    Any as(new std::string(s));

    std::cout << data << "\n" << ai << ' ' << ad << ' ' << as;
}

// Ваш код здесь //////////////////////////////////////////////////////////////

// Реализация конструкторов
Any::Any(int* data) : data(data), type(Type::INT) {};
Any::Any(double* data) : data(data), type(Type::DOUBLE) {};
Any::Any(std::string* data) : data(data), type(Type::STRING) {};
Any::Any(std::vector<Any*>* data) : data(data), type(Type::VECTOR_ANY_PTR) {};

// Реализация деструктора
Any::~Any() {
    if (type == Type::VECTOR_ANY_PTR) {
        std::vector<Any*>* v = static_cast<std::vector<Any*>*>(data);
        for (auto e : *v)
            delete e;
        delete v;
    } else
        delete data;
};

// Реализация операторов:

Any::operator int() {
    if (type != Type::INT)
        throw "";
    return *(int*)data;
};

Any::operator double() {
    if (type != Type::DOUBLE)
        throw "";
    return *(double*)data;
};

Any::operator std::string() {
    if (type != Type::STRING)
        throw "";
    return *(std::string*)data;
};

Any::operator std::vector<Any*>* () {
    if (type != Type::VECTOR_ANY_PTR)
        throw "";
    return static_cast<std::vector<Any*>*>(data);
};

std::ostream& operator<<(std::ostream& out, const Any& val) {
    switch (val.type) {
        case Any::Type::INT:
            out << *static_cast<int*>(val.data);
            break;
        case Any::Type::DOUBLE:
            out << *static_cast<double*>(val.data);
            break;
        case Any::Type::STRING:
            out << *static_cast<std::string*>(val.data);
            break;
        case Any::Type::VECTOR_ANY_PTR:
            for (const Any* item : *static_cast<std::vector<Any*>*>(val.data)) {
                if (item != static_cast<std::vector<Any*>*>(val.data)->front())
                    out << " ";
                out << *item;
            }
            break;
    };

    return out;
};