#ifndef INC_7_STRUCT_H
#define INC_7_STRUCT_H
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <random>
#include <algorithm>
#include <iostream>
#include <chrono>

struct Trust{
    int trustNumber;
    std::string trustCoName;
};

void addTrust(std::vector<Trust>& data, int SIZE){
    for(int i = 0; i < SIZE; i++){
        Trust t = {rand() % SIZE, "Name_Co_№_" + std::to_string(i)};
        data.push_back(t);
    }
}

bool compareByInt(const Trust& a, const Trust& b) {
    return a.trustNumber < b.trustNumber;
}

void sortData(std::vector<Trust>& data){
    sort(data.begin(), data.end(), compareByInt);
}

void printTrust(std::vector<Trust> data){
    for(auto item: data){
        std::cout << item.trustNumber << " " << item.trustCoName << std::endl;
    }
}

#endif //INC_7_STRUCT_H
