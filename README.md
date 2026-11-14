# 🔐 MyCryps

Just a bunch of homemade cryptography experiments written in **C++**. Made for learning, curiosity, and fun!

> ⚠️ **Security Disclaimer:** The algorithms in this repository are educational and experimental implementations ("homemade cryptography"). **Do not use this code in production environments** or to protect real, sensitive data.

## 📂 Available Algorithms

| Folder | Algorithm | Description |
| :--- | :--- | :--- |
| **[Enyg](./Enyg)** | 4-Rotor Simulator (Enigma-inspired) | Symmetric polyalphabetic cipher inspired by the Enigma machine, featuring 4 rotors, a reflector, and variable stepping via a 6-digit numeric key. |
| **[ZDOR](./ZDOR)** | Neighbor Expansion + Reversal | Expansion substitution cipher that doubles the text length using adjacent ASCII characters and reverses the final string. |
| **[ZYG](./ZYG)** | Multi-Layer Hybrid Cipher | The most complex algorithm in the repository: combines a 5-rotor machine (double pass), an expanded 16-key Vigenère cipher, and string reversal. |

## 🚀 How to Build and Run

You will need a C++ compiler installed (such as `g++` or `clang++`).

1. **Clone the repository:**
   ```bash
   git clone https://github.com
   cd MyCryps
   ```

2. **Navigate to the desired experiment folder and compile:**
   ```bash
   cd ZYG
   g++ -std=c++17 main.cpp -o zyg
   ```

3. **Run the executable:**
   ```bash
   ./zyg
   ```

## 🛠️ Built With

* **C++** (C++17 or higher)
* C++ Standard Library (`<iostream>`, `<string>`, `<cctype>`, `<algorithm>`)

## 📄 License

This project is licensed under the **MIT License**. See the [LICENSE](./LICENSE) file for details.
