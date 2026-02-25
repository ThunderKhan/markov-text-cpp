#pragma once

#include "types.hpp"
#include <vector>

namespace markov {
  class Model {
  public:
    explicit Model(Order order);
    Order order() const noexcept;

    void add_transition(const State& state, const Token& next);

    // Returns pointer to list of possible next tokens.
    // nullptr if the state is unknown.
    const std::vector<Token>* next_tokens(const State& state) const;

    const TransitionTable& transitions() const noexcept;

  private:
    Order m_order;
    TransitionTable m_table;
  };
}
