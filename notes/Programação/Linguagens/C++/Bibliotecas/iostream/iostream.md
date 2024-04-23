# iostream

&nbsp; A biblioteca `iostream` é responsável por conter as funções/objetos de input e output na linguagem C++.

## Index

1. [cin](#cin)
2. [cout](#cout)
3. [cerr](#cerr)
4. [clog](#clog)
5. [wcin](#wcin)
6. [wcout](#wcout)
7. [wcerr](#wcerr)
8. [wclog](#wclog)

## cin

#### Standard Input Stream
&nbsp; Objeto de classe `istream` que representa o _standard input stream_ orientada para _narrow characters_ (de tipo `char`). Corresponde ao **C stream** `stdin`.

&nbsp; O _standard input stream_ é uma fonte de caracteres determinados pelo ambiente. Assume-se geralmente que seja o _input_ de uma fonte externa, como o teclado ou um arquivo.

&nbsp; Como um objeto de classe `istream`, caracteres podem ser adquiridos tanto como dados formatados com o uso do operador de extração (`>>`) ou como dados não formatados, usando funções como `read()`.

&nbsp; O `cin` por padrão é conectado ao _standard output stream_ `cout`, indicando que o buffer de `cout` sofre um `flush` antes de cada operação i/o feita pelo `cin`.

&nbsp; Para além disso, o `cin` também é sincronizado ao `stdin` por padrão.

&nbsp; Um programa deve evitar misturar operações de input de `cin` com operações de input em [wcin](#wcin). Uma vez que uma operação de input é realizada, a _standard input stream_ adquiri uma orientação (_**narrow**_ ou _**wide**_) que só pode ser alterada com segurança com a função `freopen()` no `stdin`.

#### Exemplo de Uso


## cout

#### Standard Output Stream
&nbsp; Objeto de classe `ostream` que representa o _standard output stream_ orientada para _narrow characters_  (de tipo `char`). Corresponde ao **C stream** `stdout.`

&nbsp; O _standard output stream_ é o destino padrão para os caracteres determinado pelo ambiente. Esse estino pode ser partilhado com mais objetos _standard_.

&nbsp; Como um objeto de classe `ostream`, caracteres podem ser escritos tanto como dados formatados usando o operador de inserção (`<<`) ou como dados não formatados, com funções como `write()`.

&nbsp; O `cout` não é conectado à nenhuma outra stream.

&nbsp; Por padrão, `cout` é sincronizado com `stdout`.

&nbsp; Um programa deve evitar misturar operações de output de `cout` com operações de [wcout](#wcout). Uma vez que uma operações de output é realizada, a _standard output stream_ adquiri uma orientação (_**narrow**_ ou _**wide**_) que só pode ser alterada com segurança com a função `freopen()` no `stdout`.

## cerr

#### Standard Output Stream for Errors
&nbsp; Objeto de classe `ostream` que representa o _standard error stream_ orientado para _narrow characters_ (de tipo `char`). Corresponde ao **C stream** `sterr.`

&nbsp; O _standard error stream_ é o destino padrão determinado pelo sistema para caracteres. Esse destino pode ser partilhado por mais de um objeto _standard_ (como [cout](#cout) ou [clog](#clog)).

&nbsp; Como um objeto de classe `ostream`, caracteres podem ser escritos tanto como dados formatados usando o operador de inserção (`<<`) ou como dados não formatados, com funções como `write()`.

&nbsp; Por padrão, `cerr` é sincronizado com `stderr`.

&nbsp; Um programa deve evitar misturar operações de output de `cerr` com operações de [wcerr](#wcerr) ou [wclog](#wclog). Uma vez que uma operações de output é realizada, a _standard error stream_ adquiri uma orientação (_**narrow**_ ou _**wide**_) que só pode ser alterada com segurança com a função `freopen()` no `sterr`.

## clog

#### Standard Output Stream for Logging
&nbsp; Objeto de classe `ostream` que representa o _standard logging stream_ orientado para _narrow characters_ (de tipo `char`). Corresponde, juntamente do [cerr](#cerr) ao **C stream** `sterr.`

&nbsp; O _standard logging stream_ é o destino padrão determinado pelo sistema para caracteres. Esse destino pode ser partilhado por mais de um objeto _standard_ (como `cout` ou `cerr`).

&nbsp; Como um objeto de classe `ostream`, caracteres podem ser escritos tanto como dados formatados usando o operador de inserção (`<<`) ou como dados não formatados, com funções como `write()`.

&nbsp; Por padrão, `clog` é sincronizado com `stderr`.

&nbsp; Um programa deve evitar misturar operações de output de `clog` com operações de [wclog](#wclog) ou [wcerr](#wcerr). Uma vez que uma operações de output é realizada, a _standard error stream_ adquiri uma orientação (_**narrow**_ ou _**wide**_) que só pode ser alterada com segurança com a função `freopen()` no `stderr`.

## wcin

#### Standard Input Stream (wide)
&nbsp; Objeto de classe `wistream` que representa o _standard input stream_ orientada para _wide characters_ (de tipo `wchar_t`). Corresponde ao **C stream** `stdin`.

&nbsp; O _standard input stream_ é uma fonte de caracteres determinados pelo ambiente. Assume-se geralmente que seja o _input_ de uma fonte externa, como o teclado ou um arquivo.

&nbsp; Como um objeto de classe `basic_istream`, caracteres podem ser adquiridos tanto como dados formatados com o uso do operador de extração (`>>`) ou como dados não formatados, usando funções como `read()`.

&nbsp; O `wcin` por padrão é conectado ao _standard output stream_ `wcout`, indicando que o buffer de `wcout` sofre um `flush` antes de cada operação i/o feita pelo `wcin`.

&nbsp; Para além disso, o `wcin` também é sincronizado ao `stdin` por padrão.

&nbsp; Um programa deve evitar misturar operações de input de `wcin` com operações de input em [cin](#cin). Uma vez que uma operação de input é realizada, a _standard input stream_ adquiri uma orientação (_**narrow**_ ou _**wide**_) que só pode ser alterada com segurança com a função `freopen()` no `stdin`.

## wcout
#### Standard Output Stream (wide)
&nbsp; Objeto de classe `wostream` que representa o _standard output stream_ orientada para _wide characters_  (de tipo `wchar_t`). Corresponde ao **C stream** `stdout.`

&nbsp; O _standard output stream_ é o destino padrão para os caracteres determinado pelo ambiente. Esse estino pode ser partilhado com mais objetos _standard_.

&nbsp; Como um objeto de classe `ostream`, caracteres podem ser escritos tanto como dados formatados usando o operador de inserção (`<<`) ou como dados não formatados, com funções como `write()`.

&nbsp; O `wcout` não é conectado à nenhuma outra stream.

&nbsp; Por padrão, `wcout` é sincronizado com `stdout`.

&nbsp; Um programa deve evitar misturar operações de output de `wcout` com operações de [cout](#cout). Uma vez que uma operações de output é realizada, a _standard output stream_ adquiri uma orientação (_**narrow**_ ou _**wide**_) que só pode ser alterada com segurança com a função `freopen()` no `stdout`.

## wcerr

#### Standard Output Stream for Errors (wide_oriented)
&nbsp; Objeto de classe `wostream` que representa o _standard error stream_ orientado para _narrow characters_ (de tipo `wchar_t`). Corresponde ao **C stream** `sterr.`

&nbsp; O _standard error stream_ é o destino padrão determinado pelo sistema para caracteres. Esse destino pode ser partilhado por mais de um objeto _standard_ (como [wcout](#wcout) ou [wclog](#wclog)).

&nbsp; Como um objeto de classe `basic_ostream`, caracteres podem ser escritos tanto como dados formatados usando o operador de inserção (`<<`) ou como dados não formatados, com funções como `write()`.

&nbsp; Por padrão, `wcerr` é sincronizado com `stderr`.

&nbsp; Um programa deve evitar misturar operações de output de `wcerr` com operações de [cerr](#cerr) ou [clog](#clog). Uma vez que uma operações de output é realizada, a _standard error stream_ adquiri uma orientação (_**narrow**_ ou _**wide**_) que só pode ser alterada com segurança com a função `freopen()` no `stderr`.

## wclog
#### Standard Output Stream for Logging (wide)
&nbsp; Objeto de classe `wostream` que representa o _standard logging stream_ orientado para _wide characters_ (de tipo `wchar_t`). Corresponde, juntamente do [wcerr](#wcerr) ao **C stream** `sterr.`

&nbsp; O _standard logging stream_ é o destino padrão determinado pelo sistema para caracteres. Esse destino pode ser partilhado por mais de um objeto _standard_ (como [wcout](#wcout) ou [wcerr](#wcerr)).

&nbsp; Como um objeto de classe `basic_ostream`, caracteres podem ser escritos tanto como dados formatados usando o operador de inserção (`<<`) ou como dados não formatados, com funções como `write()`.

&nbsp; Por padrão, `wclog` é sincronizado com `stderr`.

&nbsp; Um programa deve evitar misturar operações de output de `wclog` com operações de [clog](#clog) ou [cerr](#cerr). Uma vez que uma operações de output é realizada, a _standard error stream_ adquiri uma orientação (_**narrow**_ ou _**wide**_) que só pode ser alterada com segurança com a função `freopen()` no `stderr`.