#include "../distance.h"

class Chebyshev : public Distance {
private:
    template <typename T>
    double calculateDistanceAny(const std::vector<T>& p1, const std::vector<T>& p2);

public:
    double calculateDistance(const std::vector<double>& p1, const std::vector<double>& p2) override;
    double calculateDistance(const std::vector<int>& p1, const std::vector<int>& p2) override;
};