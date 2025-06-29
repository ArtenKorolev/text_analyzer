# Multithreaded File Analyzer

 📌Project Overview

Multithreaded File Analyzer is a high-performance C++ tool designed for efficient and scalable file content analysis.
It leverages multithreading to process large datasets quickly, making it suitable for log analysis, data mining, or batch content processing on modern multi-core systems.

⸻

🚀 Features
	•	✅ Parallel File Processing: Automatically distributes workload across multiple threads.
	•	✅ Thread-Safe Reporting: Aggregates results safely from multiple threads.
	•	✅ Performance Optimized: Minimal synchronization overhead, making full use of CPU cores.
	•	✅ Cross-Platform: Builds and runs on Linux, macOS, and Windows (tested with GCC, Clang, MSVC).

⸻

⚙️ Build Instructions

Prerequisites
	•	C++17 or higher
	•	CMake 3.10+
	•	Make / Ninja / Visual Studio (any CMake-supported build system)

Build (Linux/macOS/WSL):

git clone https://github.com/ArtenKorolev/text_analyzer.git
cd text_analyzer
mkdir build && cd build
cmake ..
make
./file_analyzer [input_directory]

Build (Windows with Visual Studio):

git clone https://github.com/ArtenKorolev/text_analyzer.git
cd text_analyzer
mkdir build
cd build
cmake .. -G "Visual Studio 17 2022"

Then open the generated .sln file and build the project.

⸻

🛠️ Usage

./text_analyzer ./logs

Command-line Options:

Option	Description
input_directory	Directory with files to analyze

⸻

✅ TODO / Future Improvements
	•	Support for recursive directory traversal
	•	File type filtering (e.g., .txt, .log)
	•	Advanced reporting (JSON/CSV output)
	•	Dynamic thread pool resizing
	•	Unit tests with GoogleTest

⸻

🤝 Contributing

Contributions, bug reports, and suggestions are welcome!
Feel free to open a pull request or submit an issue.

⸻

⭐️ Motivation

This project was created as a learning exercise in multithreading, synchronization, and efficient file I/O handling in C++.
It’s a great stepping stone towards more advanced system programming projects.

⸻
