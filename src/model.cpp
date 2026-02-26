#include "markov/model.hpp"
#include <algorithm>
#include <vector>

namespace markov {
  Model::Model(Order order)
    : m_order(order)
  {
  }

  Order Model::order() const noexcept {
    return m_order;
  }

  void Model::add_transition(const State& state, const Token& next) {
    m_table[state].push_back(next);
  }

  const std::vector<Token>* Model::next_tokens(const State& state) const {
    auto it = m_table.find(state);
    if (it ==  m_table.end()) {
      return nullptr;
    }

    return &it -> second;
  }

  const TransitionTable& Model::transitions() const noexcept {
    return m_table;
  }
}
