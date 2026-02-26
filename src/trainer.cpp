#include <cstddef>
#include <vector>
#include "markov/trainer.hpp"

namespace markov {
  void train(Model& model, const std::vector<Token> &tokens) {
    const Order order = model.order();

    if (tokens.size() <= order) {
      return;
    }

    for (std::size_t i = 0; i + order < tokens.size(); ++i) {
      State state;
      state.reserve(order);

      for (std::size_t j = 0; j < order; ++j) {
        state.push_back(tokens[i + j]);
      }

      const Token& next = tokens[i + order];
      model.add_transition(state, next);
    }
  }
}
