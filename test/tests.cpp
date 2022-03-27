// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
TEST(TEST1, TrueOrFalse) {
    Automata automata;
    automata.on();
    EXPECT_EQ(STATES::WAIT, automata.getState());
}

TEST(TEST2, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.check();
    EXPECT_EQ(STATES::WAIT, automata.getState());
}

TEST(TEST3, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.coin(10);
    automata.coin(10);
    EXPECT_EQ(STATES::ACCEPT, automata.getState());
}

TEST(TEST4, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.coin(10);
    automata.coin(10);
    automata.choiceuser(1);
    EXPECT_EQ(STATES::CHOSEN, automata.getState());
}


TEST(TEST5, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.coin(10);
    automata.coin(10);
    automata.choiceuser(1);
    automata.check();
    EXPECT_EQ(STATES::WAIT, automata.getState());
}

TEST(TEST6, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choiceuser(1);
    automata.check();
    EXPECT_EQ(STATES::MAKING, automata.getState());
}

TEST(TEST7, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choiceuser(1);
    automata.check();
    automata.cook()
    EXPECT_EQ(STATES::READY, automata.getState());
}

TEST(TEST8, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choiceuser(1);
    automata.check();
    automata.cook()
    EXPECT_EQ(40, automata.getCash());
}

TEST(TEST9, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(60);
    automata.choice(1000);
    EXPECT_EQ(STATES::WAIT, automata.getState());
}

TEST(TEST10, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.cook();
    EXPECT_EQ(STATES::WAIT, automata.getState());
}

TEST(TEST11, TrueOrFalse) {
    Automata automata;
    automata.on();
    automata.coin(60);
    automata.choice(1);
    automata.check();
    automata.cook();
    automata.finish();
    automata.off();
    EXPECT_EQ(STATES::OFF, automata.getState());
}
