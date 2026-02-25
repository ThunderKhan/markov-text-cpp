#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <cstddef>

namespace markov {
  using Token = std::string;
  using State = std::vector<Token>;

  struct  StateHash {
    std::size_t operator () ( const State& state ) const noexcept {
      std::size_t seed = 0;

      for ( const auto& token : state ) {
        std::hash<std::string> hasher;
        std::size_t h = hasher(token);

        seed ^= h + 0x9e3779b97f4a7c15ULL + (seed << 6) + (seed >> 2);
      }

      return seed;
    }
  };

  using TransitionTable = std::unordered_map< State, std::vector<Token>, StateHash >;
  using Order = std::size_t;
}
