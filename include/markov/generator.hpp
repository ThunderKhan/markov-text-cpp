#pragma once

#include <vector>
#include <cstddef>

#include <markov/types.hpp>
#include <markov/model.hpp>

namespace markov {
  std::vector<Token> generate(const Model& model, std::size_t max_tokens);
}
