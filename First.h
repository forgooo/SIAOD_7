#ifndef INC_7_FIRST_H
#define INC_7_FIRST_H
#include "Struct.h"

void linearSearch(int SIZE){
    std::vector<Trust> data;
    addTrust(data, SIZE);

    int randomTrustNumber = data[rand() % SIZE].trustNumber;
    long Cf = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (auto item: data) {
        Cf++;
        if (item.trustNumber == randomTrustNumber) {
            std::cout << Cf << " ";
            break;        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << duration.count() << " ns\n";

    data.clear();
}

void barrierSearch(int SIZE){
    std::vector<Trust> data;
    addTrust(data, SIZE);

    int randomTrustNumber = data[rand() % SIZE].trustNumber;
    long Cf = 0;
    int i = 0;

    auto start = std::chrono::high_resolution_clock::now();
    while (i < SIZE && data[i].trustNumber != randomTrustNumber) {
        Cf++;
        i++;
    }
    if (i < SIZE) {
        std::cout << Cf << " ";
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << duration.count() << " ns\n";

    data.clear();
}

#endif //INC_7_FIRST_H