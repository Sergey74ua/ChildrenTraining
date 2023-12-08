/*
Даны два чистых абстрактных класса (интерфейсы) IRunnable и IClock.
Методы интерфейса IClock:
    add - "запоминает" событие (объект реализующий интерфейс IRunnable) и временную метку;
    next - выполняет запуск следующего по времени события и удаляет его из списка. Перед запуском события выводится временная метка в формате часы:минуты:секунды. Если событий нет, то возвращает false.
Методы интерфейса IRunnable:
    run - если вызвать этот метод, то выполнится код который в нём написан.
Классы OSUpdater, Alarm, ActivityChecker, реализуют интерфейс IRunnable и в качестве действия выводят на экран имя класса.
Класс Clock реализует оба интерфейса и в качестве действия вызывает у себя next, пока не закончатся все события которые были установлены ранее.
*/

#include <iostream>

struct Time {
    short hours;
    short minutes;
    short seconds;

    void addSeconds(short count) {
        seconds += count;
        if (seconds >= 60) {
            count = seconds / 60;
            seconds %= 60;
        }
        else return;

        minutes += count;
        if (minutes >= 60) {
            count = minutes / 60;
            minutes %= 60;
        }
        else return;

        hours += count;
        if (hours >= 60)
            hours = minutes = seconds = 0;
    }
};

bool operator==(const Time& lhs, const Time& rhs) {
    return lhs.hours == rhs.hours &&
        lhs.minutes == rhs.minutes &&
        lhs.seconds == rhs.seconds;
}

bool operator!=(const Time& lhs, const Time& rhs) {
    return not (lhs == rhs);
}

bool operator<(const Time& lhs, const Time& rhs) {
    return lhs.hours * 3600 + lhs.hours * 60 + lhs.seconds < rhs.hours * 3600 + rhs.hours * 60 + rhs.seconds;
}

class IRunnable {
public:
    virtual void run() = 0;
};

class IClock {
public:
    virtual void add(IRunnable* client, Time time) = 0;
    virtual bool next() = 0;
};

// Ваш код здесь
class OSUpdater : public IRunnable {
    //в качестве действия выводят на экран имя класса
    void run() override {
        std::cout << "OSUpdater" << std::endl;
    };
};

class Alarm : public IRunnable {
public:
    //в качестве действия выводят на экран имя класса
    void run() override {
        std::cout << "Alarm" << std::endl;
    };
};

class ActivityChecker : public IRunnable {
public:
    //в качестве действия выводят на экран имя класса
    void run() override {
        std::cout << "ActivityChecker" << std::endl;
    };
};

#include <vector> //возможно лишнее
#include <iomanip> //возможно лишнее

class Clock : public IRunnable, public IClock {
public:
    //Список событий
    std::vector<std::pair<IRunnable*, Time>> events;

    //в качестве действия вызывает у себя next, пока не закончатся все события которые были установлены ранее.
    void run() override {
        while (next());
    };

    //"запоминает" событие (объект реализующий интерфейс IRunnable) и временную метку;
    void add(IRunnable* client, Time time) override {
        events.push_back(std::make_pair(client, time));
    };

    //выполняет запуск следующего по времени события и удаляет его из списка. Перед запуском события
    //выводится временная метка в формате часы:минуты:секунды. Если событий нет, то возвращает false.
    bool next() override {
        if (events.empty())
            return false;

        auto it = events.begin();
        auto nextEvent = it;
        for (; it != events.end(); ++it) {
            if (it->second < nextEvent->second)
                nextEvent = it;
        }

        std::cout
            << std::setfill('0') << std::setw(2) << nextEvent->second.hours << ":"
            << std::setfill('0') << std::setw(2) << nextEvent->second.minutes << ":"
            << std::setfill('0') << std::setw(2) << nextEvent->second.seconds << " ";

        nextEvent->first->run();
        events.erase(nextEvent);

        return true;
    };
};

int main() {
    int monentum;
    std::cin >> monentum;
    srand(monentum);  // Фиксируем случайность

    IClock* clock = new Clock;
    IRunnable* timer = (Clock*)clock;

    Time t = { 0, 0, 0 }, midnight = { 0, 0, 0 };

    do {
        int type = rand() % 3;
        if (type == 0) clock->add(new OSUpdater, t);
        else if (type == 1) clock->add(new Alarm, t);
        else if (type == 2) clock->add(new ActivityChecker, t);
        t.addSeconds(3600 + rand() % 3600);
    } while (t != midnight);

    timer->run();
}


/*
class Clock : public IClock, public IRunnable
private:
    std::vector<std::pair<IRunnable*, Time>> events;

public:
    void add(IRunnable* client, Time time) override
        events.push_back(std::make_pair(client, time));


    bool next() override
        if (events.empty()) return false;

        auto it = events.begin();
        auto nextEvent = it;
        for (; it != events.end(); ++it)
            if (it->second < nextEvent->second)
                nextEvent = it;



        std::cout << std::setfill('0') << std::setw(2) << nextEvent->second.hours << ":"
                  << std::setfill('0') << std::setw(2) << nextEvent->second.minutes << ":"
                  << std::setfill('0') << std::setw(2) << nextEvent->second.seconds << " ";
        nextEvent->first->run();

        events.erase(nextEvent);
        return true;


    void run() override
        while (next());

;
*/


/*
class OSUpdater : public IRunnable 
public:
    void run() override 
        std::cout << "OSUpdater" << std::endl;
    
;

class Alarm : public IRunnable 
public:
    void run() override 
        std::cout << "Alarm" << std::endl;
    
;

class ActivityChecker : public IRunnable 
public:
    void run() override 
        std::cout << "ActivityChecker" << std::endl;
    
;
*/