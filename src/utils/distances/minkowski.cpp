#include "../../../lib/utils/distances/minkowski.h"

Minkowski::Minkowski(double order) : _order(order) {
    if(order < 1) {
        throw std::invalid_argument("Order must be greater than or equal to 1");
    }
};

template <typename T>
double Minkowski::calculateDistanceAny(const std::vector<T>& p1, const std::vector<T>& p2) {
    if(p1.size() != p2.size()) {
        throw std::invalid_argument("Vectors must be of equal length");
    }
    
    double distance = 0;
    for (int i = 0; i < p1.size(); i++) {
        distance += std::pow(std::abs(static_cast<double>(p1[i]) - static_cast<double>(p2[i])), _order);
    }
    return std::pow(distance, 1.0 / _order);
}

double Minkowski::calculateDistance(const std::vector<double>& p1, const std::vector<double>& p2) {
    return calculateDistanceAny(p1, p2);
}

double Minkowski::calculateDistance(const std::vector<int>& p1, const std::vector<int>& p2) {
    return calculateDistanceAny(p1, p2);
}