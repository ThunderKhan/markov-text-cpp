#include <cstddef>
#include <markov/tokenizer.hpp>
#include <markov/generator.hpp>
#include <markov/trainer.hpp>
#include <markov/model.hpp>

#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char** argv) {
  std::string filename = "data/sample.txt";

  if (argc > 1) {
    filename = argv[1];
  }

  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Failed to open file: " << filename << "\n";
    return 1;
  }

  std::ostringstream buffer;
  buffer << file.rdbuf();
  std::string text = buffer.str();

  auto tokens = markov::tokenize(text);

  if (tokens.empty()) {
    std::cerr << "No tokens found.\n";
    return 1;
  }

  markov::Order order = 2;
  markov::Model model(order);

  markov::train(model, tokens);


  std::size_t max_tokens = 50;

  auto generated = markov::generate(model, max_tokens);


  for (std::size_t i = 0; i < generated.size(); ++i) {
    if (i > 0) {
      std::cout << " ";
    }
    std::cout << generated[i];
  }

  std::cout << "\n";

  return 0;
}
