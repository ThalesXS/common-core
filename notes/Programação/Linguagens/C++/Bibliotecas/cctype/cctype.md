# cctype
&nbsp; Esta biblioteca declara um conjunto de funções que classificam e transformam caracteres individuais.

## Funções
&nbsp; Essas funções recebem o `int` equivalente à um caracter usado como parâmetro e retorna um inteiro, que pode ser outro caracter ou um valor representando um `bool`.

#### Funções de Classificação de `char`
* `isalnum()`: Verifica se o caractér é alfanumérico.
* `isalpha()`: Verifica se o caractér é alfabético.
* `isblank()`: Verifica se o caractér é vazio.
* `iscntrl()`: Verifica se o caractér é um `char` de controle.
* `isdigit()`: Verifica se o caractér é um digito decimal.
* `isgraph()`: Verifica se o caractér tem representação gráfica.
* `islower()`: Verifica se o caractér é uma letra minúscula.
* `isprint()`: Verifica se o caractér é printável.
* `ispunct()`: Verifica se o caractér é uma pontuação.
* `isspace()`: Verifica se o caractér é um espaço em branco.
* `isupper()`: Verifica se o caractér é uma letra maiúscula.
* `isxdigit()`: Verifica se o caractér é um digito hexadecimal.

#### Funções de Conversão de `char`
* `tolower()`: Converte a letra maiúscula para minúscula.
* `toupper()`: Converte a letra minúscula para maiúscula.