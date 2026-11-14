# ⚙️ Enyg

**Enyg** is an experimental polyalphabetic cipher inspired by the electromechanical operation of the historical **Enigma Machine**. It uses multiple stages of dynamic substitution combined with a symmetric reflector.

## 🧠 How It Works

1. **Initialization Key:** The user provides a sequence of **6 numbers** (from `1` to `9`). These numbers determine the stepping pace of the rotors for each processed letter.
2. **4-Rotor & Gear System:**
   * For every alphabetic character, the first rotor (`g1`) advances according to the current number in the 6-digit sequence.
   * When a rotor completes a full rotation (`>= 26`), it carries the step over to the next rotor (`g2`, `g3`, and `g4`), acting like a dynamic odometer.
3. **Round-Trip Path (Symmetry):**
   * The letter passes through all 4 rotors (`rt1` → `rt2` → `rt3` → `rt4`).
   * It hits the **Reflector** (`rlf`), which swaps the letter in pairs.
   * It travels back through the inverted rotor tables (`iv4` → `iv3` → `iv2` → `iv1`).
4. **Character Preservation:** Spaces, numbers, and punctuation remain unchanged and do not advance the rotors. All output letters are converted to uppercase.

## 🔄 Encrypting & Decrypting

Because it uses a symmetric reflector (just like the original Enigma), **the decryption process is identical to encryption**: simply run the program again, enter the exact **same 6 numbers** as the key, and input the ciphertext to recover the original message.

## 💻 Usage Example

*(Note: Console prompts are in Portuguese)*

```text
quer usar o enyg?[y/n]
y
diga 6 numeros de 1 a 9 em sequencia
3 1 4 1 5 9
agora digite uma frase
Ola Mundo!
QXP ZWRKV!
```
