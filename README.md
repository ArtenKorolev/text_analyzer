# Multithreaded File Analyzer

A multithreaded C++ tool for analyzing text files.
It counts words, lines, and characters.

---

# Performance

This tool is designed to be high-performance and fully multithreaded. It processes
each file in a separate thread, which increases performance. Also, it uses modern C++ features such as
move semantics, RAII, the std::filesystem library, trailing types, auto, etc.

## Benchmarks

If you build this project in debug configuration, this tool will
display the results of benchmarking both one thread and multithread versions
instead of the actual analysis results, for example:

```text
Analyzing directory: /bin
Multithread version: 71.979 ms
One thread version: 176.419 ms
```

---

# C++ Tooling

This project uses *CMake* as meta build system, *clang-format* as code formatter and
*clang-tidy* as static analyzer.
---

# Build

1) Clone git repo: `git clone https://github.com/ArtenKorolev/text_analyzer`
2) Create bin folder: `mkdir bin; cd bin`
3) Run CMake with your generator : `cmake .. -G<your generator>`
4) Run your build system, for example: `make`

---

# Usage

Using this tool is as simple as:

``` text
./text_analyzer <input_directory>
```

<input_directory> is the directory you want to analyze. This tool
will traverse all the files in this directory and count words, lines and
characters there, and then display them to you (in release configuration)

---

# Motivation

This project was created for learning purposes. First, I wanted to
practice multithreaded programming in C++, synchronization primitives, and
related concepts. Also, I wanted to practice skills in using modern C++ and
improve my system programming skills.