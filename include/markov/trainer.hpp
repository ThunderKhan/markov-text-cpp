#pragma once

#include "markov/types.hpp"
#include "markov/model.hpp"
#include "types.hpp"
#include <vector>

namespace markov {
  void train(Model& model, const std::vector<Token>& tokens);
}
