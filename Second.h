#ifndef INC_7_SECOND_H
#define INC_7_SECOND_H
#include "Struct.h"

int Cf = 0;

int interpolationSearch(std::vector<Trust> data, int lo, int hi, int x)
{
    int pos;
    Cf++;
    if (lo <= hi && x >= data[lo].trustNumber && x <= data[hi].trustNumber) {
        pos = lo
              + (((double)(hi - lo) / (data[hi].trustNumber - data[lo].trustNumber))
                 * (x - data[lo].trustNumber));
        Cf++;
        if (data[pos].trustNumber == x) {
            return pos;
        }

        Cf++;
        if (data[pos].trustNumber < x) {
            return interpolationSearch(data, pos + 1, hi, x);
        }

        Cf++;
        if (data[pos].trustNumber > x) {
            return interpolationSearch(data, lo, pos - 1, x);
        }
    }
    return -1;
}

void interpolationSearchStart(int SIZE){
    std::vector<Trust> data;
    addTrust(data, SIZE);
    sortData(data);
    srand(time(NULL));
    int randomTrustNumber = data[rand() % SIZE].trustNumber;
    auto start = std::chrono::high_resolution_clock::now();

    interpolationSearch(data, 0, SIZE - 1, randomTrustNumber);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << Cf << " " << duration.count() << " ns\n";

    data.clear();
}

#endif //INC_7_SECOND_H