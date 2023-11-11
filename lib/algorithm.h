#pragma once

#include <vector>

class Algorithm {
  protected:
    std::vector<double> _decision_scores = {};
    std::vector<double> _threshold = {};
    std::vector<int> _labels = {};

  public:
    virtual void fit(std::vector<std::vector<double>> data,
                     std::vector<std::vector<int>> labels = {}) = 0;
    virtual void fit(std::vector<std::vector<int>> data,
                     std::vector<std::vector<int>> labels = {}) = 0;

    virtual std::vector<int> predict(std::vector<std::vector<double>> data) = 0;

    virtual std::vector<int> predict(std::vector<std::vector<int>> data) = 0;

    std::vector<double> get_decision_scores() { return _decision_scores; }

    std::vector<double> get_threshold() { return _threshold; }

    std::vector<int> get_labels() { return _labels; }
};