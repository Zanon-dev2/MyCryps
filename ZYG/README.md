# 🛡️ ZYG

O **ZYG** é o experimento mais complexo e robusto do repositório **MyCryps**. Ele implementa uma **criptografia híbrida em múltiplas camadas**, combinando um sistema de rotores estilo Enigma de 5 discos, uma cifra polialfabética derivada de Vigenère e inversão de string em um fluxo simétrico reversível.

## 🧠 Arquitetura e Funcionamento

Para operar o algoritmo, o usuário define **duas chaves numéricas**:
1. **Posição Inicial dos Discos:** 5 números (de `0` a `26`) que definem o estado inicial dos 5 rotores (`ir1` a `ir5`).
2. **Chaves de Passo e Deslocamento:** 8 números (de `0` a `10`) que controlam tanto a velocidade de rotação dos discos quanto a chave expandida de Vigenère (`ls1` a `ls8`).

### Fluxo de Criptografia (`[C]`)
O texto passa por **4 estágios sequenciais**:
1. **Primeira Passagem nos Rotores (`enyg`):** O texto original atravessa 5 rotores (`rta` a `rte`), bate em um refletor (`rlf`) e retorna pelas tabelas invertidas (`ive` a `iva`). Os discos avançam em cascata usando a sequência de 8 chaves.
2. **Cifra de Vigenère Expandida (`vege`):** A partir dos 8 números informados pelo usuário, o algoritmo gera matematicamente uma **chave cíclica de 16 posições** (combinando valores individuais e somas cruzadas) para aplicar um deslocamento polialfabético adicional.
3. **Inversão de String (`rm`):** O resultado da etapa anterior é totalmente invertido de trás para frente (`std::reverse`).
4. **Segunda Passagem nos Rotores (`enyg`):** O texto invertido passa novamente pela máquina de 5 rotores desde a posição inicial, embaralhando o padrão final.

### Fluxo de Descriptografia (`[D]`)
Por utilizar operações simétricas e inversas, o algoritmo desfaz cada camada na ordem exata oposta:
1. **Desfaz a 2ª Passagem nos Rotores (`enyg`)**
2. **Desinverte a String (`rm`)**
3. **Aplica a Vigenère Inversa (`revege`):** Subtrai os 16 deslocamentos da chave expandida.
4. **Desfaz a 1ª Passagem nos Rotores (`enyg`):** Recupera o texto original.

> ☕ **Easter Eggs:** Digitar uma opção inválida na pergunta inicial retorna o código HTTP **418** (*"vai tomar cafe"*), enquanto uma opção inválida no modo de operação retorna **404** (*"ERRO"*).

## 💻 Exemplo de Uso

```text
quer usar o zyg?[s/n]
s
Quer criptografar ou descriptografar?[C/D]

c
diga cinco numeros (0 a 26) para definir a posicao inicial dos discos 
5 12 0 21 8
diga oito numeros (0 a 10) para as chaves 
2 7 4 9 1 6 3 8
diga sua palavra/frase
Segredo absoluto!
[SAÍDA CRIPTOGRAFADA]
```
