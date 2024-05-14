# Entrada e Saída de Dados em C++ com iostream

A entrada e saída de dados em C é feita através das funções `scanf()` e `printf()`, disponíveis na sua biblioteca padrão. Apesar destas funções ainda estarem disponíveis em C++, vamos preferir utilizar o novo sistema de entrada e saída de dados por fluxo.

Uma vez incluído o arquivo `<iostream>`, um programa C++ dispõe de três fluxos predefinidos que são abertos automaticamente pelo sistema:

- **cin**, que corresponde à entrada padrão
- **cout**, que corresponde à saída padrão
- **cerr**, que corresponde à saída padrão de erros

O operador `<<` permite inserir valores em um fluxo de saída, enquanto o operador `>>` permite extrair valores de um fluxo de entrada.

## Exemplo 1.2

```cpp
#include <iostream>

void main(void)
{
    std::cout << "Olá mundo!\n";
}
```
O operador `<<` pode ser usado, de forma encadeada, para inserir diversos valores em um mesmo fluxo de saída.

### Exemplo 1.3:

```cpp
#include <iostream>

void main(void)
{
    char nome[80];
    cout << "Qual o seu nome? ";
    cin >> nome;
    cout << "Olá " << nome << ", tudo bem? \n";
}
```
### Exemplo 1.4:
```cpp
#include <iostream>

void main(void)
{
    float comprimento, largura;
    cout << "Informe o comprimento e a largura do retângulo: ";
    cin >> comprimento >> largura;
    cout << "Área do retângulo: " << comprimento * largura << " m2\n";
}
```

# Manipuladores

Os manipuladores são elementos que determinam o formato em que os dados serão escritos ou lidos de um fluxo.

## Principais Manipuladores

- **oct**: leitura e escrita de um inteiro octal
- **dec**: leitura e escrita de um inteiro decimal
- **hex**: leitura e escrita de um inteiro hexadecimal
- **endl**: insere um caractere de mudança de linha
- **setw(int n)**: define campo com largura de n caracteres
- **setprecision(int n)**: define total de dígitos na impressão de números reais
- **setfill(char c)**: define o caractere usado no preenchimento de campos
- **flush**: descarrega o buffer após a escrita

## Exemplo 1.5

```cpp
#include <iostream.h>
#include <iomanip.h>

void main(void)
{
    int i = 1234;
    float p = 12.3456F;

    cout << "|"
         << setw(8) << setfill('*')
         << hex << i
         << "|\n"
         << "|"
         << setw(6) << setprecision(4)
         << p
         << "|" << endl;
}
//Resultado da execução
|*****4d2|
|*12.35|
```
# Conversões Explícitas

Em C++, a conversão explícita de tipos pode ser feita tanto através da notação de cast quanto da notação funcional.

### Exemplo 1.6:

```cpp
int i, j;
double d = 9.87;
i = (int)d; // notação “cast”
j = int(d); // notação funcional
```
Entretanto, a notação funcional só pode ser usada com tipos simples ou definidos pelo usuário. Para utilizá-la com ponteiros e vetores, precisamos antes criar novos tipos.

```cpp
typedef int * ptr;
int *i;
double d;
i = ptr(&d); // notação funcional com ponteiro
```
# Definição de Variáveis

Em C++, uma variável pode ser declarada em qualquer parte do código, sendo que seu escopo inicia-se no ponto em que foi declarada e vai até o final do bloco que a contém.

### Exemplo 1.8:

```cpp
#include <iostream.h>

void main(void)
{
    cout << "Digite os valores (negativo finaliza): ";
    float soma = 0;
    while (true) {
        float valor;
        cin >> valor;
        if (valor < 0) break;
        soma += valor;
    }
    cout << "\nSoma: " << soma << endl;
}
```
Podemos até declarar um contador diretamente dentro de uma instrução `for`:
```cpp
#include <iostream.h>

void main(void)
{
    cout << "Contagem regressiva: " << endl;
    for (int i = 9; i >= 0; i--)
        cout << i << endl;
}
```
O operador de resolução de escopo ( :: ) nos permite acessar uma variável global, mesmo
que exista uma variável local com o mesmo nome.

### Exemplo 1.10:

```cpp
#include <iostream.h>

int n = 10;

void main(void)
{
    int n = 20;
    {
        int n = 30;
        ::n++; // altera variável global
        cout << ::n << " " << n << endl;
    }
    cout << ::n << " " << n << endl;
}

A saída produzida por esse programa é a seguinte:

11 30
11 20
```
# Constantes

Programadores em C estão habituados a empregar a diretiva `#define` do pré-processador para definir constantes. Entretanto, a experiência tem mostrado que o uso dessa diretiva é uma fonte de erros difíceis de se detectar.

Em C++, a utilização do pré-processador deve ser limitada apenas aos seguintes casos:
- Inclusão de arquivos;
- Compilação condicional.

Para definir constantes, em C++, usamos a palavra reservada `const`. Um objeto assim especificado não poderá ser modificado durante toda a sua existência e, portanto, é imprescindível inicializar uma constante no momento da sua declaração.

### Exemplo 1.11:

```cpp
const float pi = 3.14;
const int meses = 12;
const char *msg = "pressione enter...";
