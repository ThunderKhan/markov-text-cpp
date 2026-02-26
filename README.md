# Markov Text Generator (C++)

A small, clean C++ project that implements a **Markov chain–based sentence generator**.

This project is intentionally written in a modular and beginner-friendly way, so each part of the pipeline (tokenizing, training, modeling and generation) is easy to understand, test and extend.

The goal is not to build a “smart” language model — but a correct and transparent **stochastic text engine**.

---

## ✨ What this project does

Given a text file, the program:

1. tokenizes the text into words and punctuation,
2. builds a Markov model of fixed order *N*,
3. samples from that model to generate a new sequence of tokens,
4. prints the generated text.

The output is a probabilistic remix of the original text, based only on local word history.

---


### Core components

- **types**  
  Common type aliases and hash helpers used across the project.

- **tokenizer**  
  Converts raw text into a sequence of tokens.

- **model**  
  Stores the Markov transition table:
  `state (last N tokens) → possible next tokens`.

- **trainer**  
  Builds the model from a token stream.

- **generator**  
  Samples tokens from a trained model.

- **main**  
  CLI entry point.

---

## ⚙️ Build

This project uses CMake.

From the project root:

```bash
cmake -S . -B build
cmake --build build
```

This produces the executable:

```bash
build/markov_text_cli
```
## Usage

```bash
./build/markov_text_cli <input_text_file>
```
---
## 🧠 How it works (short explanation)

For a chosen order of *N*, the model learns the transitions of the form:

```bash
[token_{i-N}, ..., token_{i-1}] → token_i
```
During generation:

1. a starting state is chosen,
2. the next token is sampled from the learned transitions,
3. the window is shifted forward,
4. the process repeats for a fixed number of tokens.

The generator does not understand grammar or meaning — it only models local token statistics.

---
## 📜 License

This project is released under the MIT License.
