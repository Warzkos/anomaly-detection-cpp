#include <iostream>
#include <vector>
#include "../lib/algorithm.h"
#include "../lib/algorithms/iqr.hpp"

int main() {
    std::vector<std::vector<int>> data = {
        {1, 3, 5},
        {1, 3, 5},
        {1, 3, 5},
        {1, 3, 5},
        {1, 3, 5},
        {1, 3, 5},
        {1, 3, 5},
        {1, 3, 5},
        {50,9,9}
    };

    Algorithm* iqr = new IQR();
    iqr->fit(data);

    std::vector<int> labels = iqr->get_labels();
    delete iqr;

    for(const auto& label : labels){
        std::cout << label << std::endl;
    }


}
