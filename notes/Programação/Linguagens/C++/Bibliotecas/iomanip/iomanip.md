# iomanip 
&nbsp; iomanip é uma biblioteca usada para manipular o [output](iostream.md#cout) em programas de C++. Para tal, fazemos uso de um conjunto de métodos fornecidos pela mesma.

## Index
* [setbase](#setbase)
* [setfill](#setfill)
* [setprecision](#setprecision)
* [setw](#setw)
* [setbase](#setbase)
## setbase
```cpp
/*unspecified*/ setbase(int base);
```
&nbsp;Define a base que será usada para a tradução dos valores de acordo com o argumento `base`.

* Caso `base` seja 10, será usada a base decimal.
* Caso `base` seja 16, será usada a base hexadecimal.
* Caso `base` seja 8, será usada a base octal.
* Caso `base` seja 0, nenhuma base será usada.
 #### Exemplo
```cpp
#include <iostream>
#include <iomanip>

int main (void)
{
  std::cout << std::setbase(16);
  std::cout << 110 << std::endl;
  return (0);
}
```
&rdsh; No exemplo acima, o  número 110 irá ser impresso no formato hexadecimal.
## setfill
```cpp
/*unspecified*/ setfill(char_type c);
```
&nbsp; Define o parâmetro `c` a ser usado para preencher o espaço mínimo para output quando [setw](#setw) for definido.
#### Exemplo
```cpp
#include <iostream>
#include <iomanip>

int main (void)
{
  std::cout << std::setfill('x') << std::setw(10);
  std::cout << 77 << std::endl;
  return (0);
}
```
&rdsh; No exemplo acima o output do número 77 deverá ter no mínimo 10 chars (definido por `setw()`), e a função `setfill()` define qual deverá ser o char usado para preencher os espaços necessários para completar 10 chars.

&nbsp; Teremos então o output como `xxxxxxxx77`.
## setprecision
```cpp
/*unspecified*/ setprecision(int n);
```
&nbsp; Define a precisão decimal a ser usada para formatar valores de tipo  `float`  em operações de output.

&nbsp; Seu comportamento é similar à quando chamamos o membro `precision` com `n` como argumento na _stream_.

#### Exemplo
```cpp
#include <iostream>
#include <iomanip>
int main (void)
{
  double f =3.14159;
  std::cout << std::setprecision(5) << f << '\n';
  std::cout << std::setprecision(9) << f << '\n';
  std::cout << std::fixed;
  std::cout << std::setprecision(5) << f << '\n';
  std::cout << std::setprecision(9) << f << '\n';
  return (0);
}
```
&rdsh; No exemplo apresentado fazemos uso da função `setprecision()` para definir a precisão para 5 e 9.

Teremos então como output:
```cpp
```