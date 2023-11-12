#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <vector>

class Distance {
    virtual double calculateDistance(const std::vector<double>& p1, const std::vector<double>& p2) = 0;
    virtual double calculateDistance(const std::vector<int>& p1, const std::vector<int>& p2) = 0;
};