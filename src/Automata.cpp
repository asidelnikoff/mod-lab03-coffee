// Copyright 2024 Alexander Sidelnikov

#include "Automata.h"

Automata::Automata() {
    balance = 0;
    current_state = Automata::OFF;
    menu.insert({"Espresso", 60});
    menu.insert({"Americano", 70});
    menu.insert({"Capuchinno", 90});
    menu.insert({"Latte", 100});
}

Automata::Automata(std::map<std::string, int> menu) {
    balance = 0;
    current_state = Automata::OFF;
    for (auto &menu_item : menu) {
        this->menu.insert_or_assign(menu_item.first, menu_item.second);
    }
}

void Automata::on() {
    if (current_state == Automata::OFF) {
        current_state = Automata::WAIT;
    }
}

void Automata::off() {
    if (current_state == Automata::WAIT) {
        current_state = Automata::OFF;
    }
}

void Automata::coin(int amount) {
    if (current_state == Automata::WAIT) {
        current_state = Automata::ACCEPT;
    }

    if (current_state == Automata::ACCEPT) {
        balance += amount;
    }
}

void Automata::choice(std::string drink_name) {
    if (menu.find(drink_name) == menu.end()) {
        return;
    }

    int price = menu[drink_name];
    if (balance >= price && current_state == Automata::ACCEPT) {
        chosen_drink = drink_name;
        current_state = Automata::CHECK;
        cook();
    }
}

void Automata::cook() {
    if (current_state == Automata::CHECK) {
        balance -= menu[chosen_drink];
        current_state = Automata::COOK;
        finish();
    }
}

void Automata::finish() {
    if (current_state == Automata::COOK) {
        chosen_drink = "";
        current_state = Automata::WAIT;
    }
}

void Automata::cancel() {
    if (current_state == Automata::ACCEPT) {
        current_state = Automata::WAIT;
        balance = 0;
    }
}

std::map<std::string, int> Automata::get_menu() {
    return menu;
}

int Automata::get_balance() {
    return balance;
}

Automata::STATES Automata::get_state() {
    return current_state;
}
