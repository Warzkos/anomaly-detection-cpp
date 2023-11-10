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
    };

    Algorithm* iqr = new IQR();
    iqr->fit(data);

    std::vector<int> labels = iqr->get_labels();
    labels = iqr->predict(std::vector<std::vector<int>>{{10, 3, 5}, {1, 3, 5}, {1,6,5}});
    delete iqr;

    for(const auto& label : labels){
        std::cout << label << std::endl;
    }


}
