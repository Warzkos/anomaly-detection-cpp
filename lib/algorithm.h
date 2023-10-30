#pragma once

#include <vector>

class Algorithm {
  protected:
    std::vector<float> _decision_scores;
    std::vector<float> _threshold;
    std::vector<int> _labels;

  public:
    virtual void fit(std::vector<std::vector<float>> data,
                     std::vector<std::vector<int>> labels) = 0;
    virtual void fit(std::vector<std::vector<int>> data,
                     std::vector<std::vector<int>> labels) = 0;

    virtual void predict(std::vector<std::vector<float>> data) = 0;
    virtual void predict(std::vector<std::vector<int>> data) = 0;

    std::vector<float> get_decision_scores() { return _decision_scores; }

    std::vector<float> get_threshold() { return _threshold; }

    std::vector<int> get_labels() { return _labels; }
};