// Copyright 2021 Pestreev Daniil

#include <string>
#include <vector>
#include "include/interpolation_search.h"
#include "include/searchApplication.h"

searchApplication::searchApplication() : message_("") {}

void searchApplication::help(const char* appname) {
    message_ = std::string("This is a interpolation_search application.") +
           "Please provide some integers to search.\nExample: \n" +
           " $ " + appname + " 0 1 2 0";
}


bool parseint(const char* arg) {
    std::string str = arg;
    int start = 0;
    if (str.size() == 1) {
        if (str[0] < '0' || str[0] > '9') {
            return false;
        }
    }
    if (str[0] = '-') {
        start++;
    }
    for (int i = start; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

bool searchApplication::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

std::string searchApplication::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    std::vector<int> array;
    int key;
    try {
        for (int i = 1; i < argc - 1; i++) {
            if (parseint(argv[i])) {
                int value_int = std::stoi(argv[i]);
                array.push_back(value_int);
            } else {  //  e = element
                throw -1;
            }
           //  array.push_back(e);
        }
        if (parseint(argv[argc - 1])) {
            key = std::stoi(argv[argc - 1]);
        } else {
            throw -1;
        }
    } catch (int e) {
        return "ERROR! Not integer";
    }
    int res_InterpSearch = InterpSearch::interpolation_search(array, key,
        false);

    std::string result = "";
    result += std::to_string(res_InterpSearch);
    return result;
}
