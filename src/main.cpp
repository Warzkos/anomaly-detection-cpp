#include "../lib/algorithm.h"
#include "../lib/algorithms/iqr.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {

    std::unique_ptr<Algorithm> iqr = std::make_unique<IQR>();

    std::vector<std::vector<int>> data = {
        {1, 3, 5},
        {2, 4, 6},
        {3, 5, 7},
        {4, 6, 8},
        {5, 7, 9},
    };

    iqr->fit(data);

    std::vector<int> labels = iqr -> get_labels();
    for(auto const &label : labels) {
        std::cout << label << std::endl;
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> outlying_data = {
        {10, 5, 7}
    };

    labels = iqr -> predict(outlying_data);
    for(auto const &label : labels) {
        std::cout << label << std::endl;
    }

    return 0;
}
