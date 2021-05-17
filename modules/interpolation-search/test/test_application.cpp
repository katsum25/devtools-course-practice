// Copyright 2021 Pestreev Daniil
#include <gtest/gtest.h>

#include <vector>
#include <string>

#include "include/searchApplication.h"

TEST(InterpolationSearchApplication, constructor) {
    ASSERT_NO_THROW(searchApplication());
}

TEST(InterpolationSearchApplication, arrayСontainsDouble) {
    int argc = 5;
    std::vector<const char *> argv = {"app", "2.5", "-3", "3", "0"};

    searchApplication app;
    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ("ERROR! Not integer", actual);
}

TEST(InterpolationSearch, empty_array) {
    int argc = 2;
    std::vector<const char *> argv = {"app", "123"};

    searchApplication app;
    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ(-1 , std::stoi(actual));
}

TEST(InterpolationSearchApplication, find_in_an_array_of_size1) {
    int argc = 3;
    std::vector<const char *> argv = {"app", "1", "1"};

    searchApplication app;
    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ(0, std::stoi(actual));
}

TEST(InterpolationSearchApplication, not_find_in_an_array_of_size1) {
    int argc = 3;
    std::vector<const char *> argv = {"app", "1", "2"};

    searchApplication app;
    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ(-1, std::stoi(actual));
}

TEST(InterpolationSearchApplication, find_in_some_array) {
    int argc = 10;
    std::vector<const char *> argv = {"app", "-10", "-2", "0", "10", "15",
        "17", "21", "100", "0"};

    searchApplication app;
    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ(2, std::stoi(actual));
}

TEST(InterpolationSearchApplication, find_in_array_with_same_numbers) {
    int argc = 10;
    std::vector<const char *> argv = {"app", "100", "100", "100", "100", "100",
        "100", "100", "100", "100"};

    searchApplication app;
    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ(0, std::stoi(actual));
}

TEST(InterpolationSearchApplication, not_find_in_array_with_same_numbers) {
    int argc = 10;
    std::vector<const char *> argv = {"app", "100", "100", "100", "100", "100",
        "100", "100", "100", "200"};

    searchApplication app;
    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ(-1, std::stoi(actual));
}

TEST(InterpolationSearchApplication, exist_far_left) {
    int argc = 10;
    std::vector<const char *> argv = {"app", "-100", "-70", "-68", "-55", "-36",
        "36", "100", "420", "-100"};

    searchApplication app;
    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ(0, std::stoi(actual));
}

TEST(InterpolationSearchApplication, exist_far_right) {
    int argc = 10;
    std::vector<const char *> argv = {"app", "-100", "-70", "-68", "-55", "-36",
        "36", "100", "420", "420"};

    searchApplication app;
    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ(7, std::stoi(actual));
}

TEST(InterpolationSearchApplication, arrayContainsString) {
    int argc = 10;
    std::vector<const char *> argv = {"app", "-10", "-2", "0", "aaaa", "15",
        "17", "21", "100", "0"};

    searchApplication app;
    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ("ERROR! Not integer", actual);
}

TEST(InterpolationSearchApplication, arrayContainsOnlyMinus) {
    int argc = 10;
    std::vector<const char *> argv = {"app", "-10", "-2", "0", "-", "15", "17",
        "21", "100", "0"};

    searchApplication app;
    std::string actual = app(argc, &argv[0]);

    ASSERT_EQ("ERROR! Not integer", actual);
}
