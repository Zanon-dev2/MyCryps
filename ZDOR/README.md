# 🔀 ZDOR

**ZDOR** is an experimental cipher based on **character expansion (ASCII neighbors)** and **string reversal**. Every character in the original message is expanded into a pair of characters before the entire string is reversed.

## 🧠 How It Works

### Encryption (`[c]`)
1. **Expansion Substitution (1-to-2):** The algorithm iterates over each character `a` in the input text:
   * **Letters from `b` to `y` (uppercase or lowercase):** Replaced by two characters: its predecessor (`a - 1`) and its successor (`a + 1`) in the ASCII table. *(Example: `c` becomes `bd`)*.
   * **Exceptions (`a`, `z`, spaces, numbers, and symbols):** To avoid shifting out of the alphabet or altering symbols, these characters are simply duplicated. *(Example: `a` becomes `aa`, a space becomes `  `)*.
2. **String Reversal:** Once substitution is complete, the entire resulting string is reversed (`std::reverse`).

### Decryption (`[d]`)
1. **Un-reversing:** The ciphertext is reversed again to restore the original pair order.
2. **Validation:** The program checks if the text length is even. If it is odd, it outputs `"Texto criptografado invalido!"`.
3. **Reconstruction:** Reads the text in pairs of 2 characters:
   * If both characters in the pair are identical, it keeps that single character.
   * If they differ, it subtracts `1` from the second character (`second - 1`) to recover the original letter.

> 🫖 **Easter Egg:** Entering any option other than `c` or `d` in the initial prompt returns HTTP error code **418** (*"sorry, I cant make coffe because im a teapot"*).

## 💻 Usage Example


```text
Wanna criptografy or decriptografy?[c/d]
c
text:
casa
aatrbzbd
One more time? [1 se sim, 0 se nao]
1
Wanna criptografy or decriptografy?[c/d]
d
text:
aatrbzbd
casa
```
