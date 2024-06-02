#include <iostream>
#include <string>
class Text {
protected:
    std::string task;

public:
    Text(const std::string& _task) : task(_task) {}

    virtual void display() const {
        std::cout << task << std::endl;
    }
};
class GreatTask : public Text {
public:
    GreatTask(const std::string& _task) : Text(_task) {}

    void display() const override {
        std::cout << "!!! " << task << std::endl;
    }
};
class DeadLineTask : public Text {
private:
    int month;
    int day;

public:
    DeadLineTask(const std::string& _task, int _month, int _day)
        : Text(_task), month(_month), day(_day) {}

    void display() const override {
        std::cout << "Date: " << month << "/" << day << " " << task << std::endl;
    }
};
class DailyTask : public Text {
private:
    int hour;
    int minute;

public:
    DailyTask(const std::string& _task, int _hour, int _minute = 0)
        : Text(_task), hour(_hour), minute(_minute) {}

    void display() const override {
        std::cout << "Time: " << hour << ":" << (minute < 10 ? "0" : "") << minute << " " << task << std::endl;
    }
};

int main() {
    Text* all[5];
    all[0] = new Text("Simple task");
    all[1] = new GreatTask("Important task");
    all[2] = new DeadLineTask("Urgent task", 8, 12); 
    all[3] = new DailyTask("Daily task", 10, 30);
    all[4] = new DailyTask("Daily task 1", 12);
    std::cout << "TO DO LIST:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        all[i]->display();
    }
    for (int i = 0; i < 5; ++i) {
        delete all[i];
    }

    return 0;
}
