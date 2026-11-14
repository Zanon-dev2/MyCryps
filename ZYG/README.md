# 🛡️ ZYG

**ZYG** is the most complex and robust experiment in the **MyCryps** repository. It implements a **multi-layer hybrid cipher**, combining a 5-rotor Enigma-style machine, a Vigenère-derived polyalphabetic cipher, and string reversal into a reversible symmetric pipeline.

## 🧠 Architecture & How It Works

To run the algorithm, the user defines **two numeric keys**:
1. **Initial Rotor Positions:** 5 numbers (from `0` to `26`) that set the starting state of the 5 rotors (`ir1` through `ir5`).
2. **Stepping & Shift Keys:** 8 numbers (from `0` to `10`) that control both the rotor stepping speed and the expanded Vigenère key (`ls1` through `ls8`).

### Encryption Pipeline (`[C]`)
The plaintext goes through **4 sequential stages**:
1. **First Rotor Pass (`enyg`):** The input passes through 5 rotors (`rta` to `rte`), bounces off a reflector (`rlf`), and returns through the inverted tables (`ive` to `iva`). The rotors cascade forward using the 8-number key sequence.
2. **Expanded Vigenère Cipher (`vege`):** From the 8 user-provided numbers, the algorithm mathematically generates a **16-position cyclic key** (combining individual values and cross-sums) to apply an additional polyalphabetic shift.
3. **String Reversal (`rm`):** The output from the previous stage is completely reversed (`std::reverse`).
4. **Second Rotor Pass (`enyg`):** The reversed text is fed through the 5-rotor machine a second time from the initial rotor positions, further scrambling the final ciphertext.

### Decryption Pipeline (`[D]`)
Because every stage is symmetric or invertible, decryption reverses each layer in the exact opposite order:
1. **Undo 2nd Rotor Pass (`enyg`)**
2. **Un-reverse String (`rm`)**
3. **Apply Inverse Vigenère (`revege`):** Subtracts the 16 shifts of the expanded key.
4. **Undo 1st Rotor Pass (`enyg`):** Recovers the original plaintext.

> ☕ **Easter Eggs:** Entering an invalid option on the initial prompt returns HTTP code **418** (*"vai tomar cafe"*), while an invalid mode selection returns **404** (*"ERRO"*).

## 💻 Usage Example

```text
Wanna use ZYG?[s/n]
s
Criptografy or decriptografy?[C/D]

c
type 5 nums (0 to 26) to set the discs initial positions 
5 12 0 21 8
type 8 nums (0 to 10) to the keys
2 7 4 9 1 6 3 8
diga sua palavra/frase
Segredo absoluto!
[ENCRYPTED OUTPUT]
```
