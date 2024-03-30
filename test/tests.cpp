// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(automata, turn_on) {
    Automata automata;
    
    automata.on();
    
    Automata::STATES actual_state = automata.get_state();
    EXPECT_EQ(Automata::STATES::WAIT, actual_state);
}

TEST(automata, turn_off) {
    Automata automata;
    automata.on();
    
    automata.off();
    
    Automata::STATES actual_state = automata.get_state();
    EXPECT_EQ(Automata::STATES::OFF, actual_state);
}

TEST(automata, accept_coins) {
    Automata automata;
    automata.on();
    
    automata.coin(1);
    
    Automata::STATES actual_state = automata.get_state();
    int actual_balance = automata.get_balance();
    EXPECT_EQ(Automata::STATES::ACCEPT, actual_state);
    EXPECT_EQ(1, actual_balance);
}

TEST(automata, choice_with_enough_coins) {
    Automata automata;
    automata.on();
    automata.coin(100);
    
    automata.choice("Espresso"); //cost: 60

    Automata::STATES actual_state = automata.get_state();
    int actual_balance = automata.get_balance();
    EXPECT_EQ(Automata::STATES::WAIT, actual_state);
    EXPECT_EQ(40, actual_balance);
}

TEST(automata, choice_with_notenough_coins) {
    Automata automata;
    automata.on();
    automata.coin(50);
    
    automata.choice("Espresso"); //cost: 60

    Automata::STATES actual_state = automata.get_state();
    int actual_balance = automata.get_balance();
    EXPECT_EQ(Automata::STATES::ACCEPT, actual_state);
    EXPECT_EQ(60, actual_balance);
}

TEST(automata, cancel) {
    Automata automata;
    automata.on();
    automata.coin(10);

    automata.cancel();

    Automata::STATES actual_state = automata.get_state();
    int actual_balance = automata.get_balance();
    EXPECT_EQ(Automata::STATES::WAIT, actual_state);
    EXPECT_EQ(0, actual_balance);
}