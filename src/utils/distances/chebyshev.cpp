#include "../../../lib/utils/distances/chebyshev.h"

template <typename T>
double Chebyshev::calculateDistanceAny(const std::vector<T>& p1, const std::vector<T>& p2) {
    if(p1.size() != p2.size()) {
        throw std::invalid_argument("Vectors must be of equal length");
    }
    
    double distance = 0;
    for (int i = 0; i < p1.size(); i++) {
        distance = std::max(distance, std::abs(static_cast<double>(p1[i]) - static_cast<double>(p2[i])));
    }
    return distance;
}

double Chebyshev::calculateDistance(const std::vector<double>& p1, const std::vector<double>& p2) {
    return calculateDistanceAny(p1, p2);
}

double Chebyshev::calculateDistance(const std::vector<int>& p1, const std::vector<int>& p2) {
    return calculateDistanceAny(p1, p2);
}