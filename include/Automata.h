// Copyright 2024 Alexander Sidelnikov

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#endif

#include <map>
#include <vector>
#include <string>

class Automata {
 public:
    enum STATES {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };
    void on();
    void off();
    void coin(int amount);
    int get_balance();
    std::map<std::string, int> get_menu();
    void choice(std::string drink_name);
    void cancel();
    STATES get_state();
    Automata();
    explicit Automata(std::map<std::string, int> menu);

 private:
    std::map<std::string, int> menu;
    STATES current_state;
    int balance;
    std::string chosen_drink;
    void cook();
    void finish();
};
