# Algoritmos
&nbsp; Algoritmo é um processo/conjunto de regras a se seguir para a resolução
de uma dada tarefa.

&nbsp; Para aplicar um algoritmo corretamente, é necessário primeiro:

- Entender o problema em si.

- Quebrar o problema em partes menores, de forma a se denfinir claramente quais
são os possíveis inputs e outputs de cada parte.

- Decidir qual o passo ideal para solucionar cada um das partes.

## Construindo um Algoritmo

### Passo 1: Determinar o Objetivo do Algoritmo.
&nbsp; Para tal, definimos claramente qual é o problema e quais são os inputs e
outputs válidos.

### Passo 2: Dividir o Problema em partes menores.
&nbsp; Dividimos o problema de forma a diminuir sua complexidade e então criamos
uma regra pra solucionar cada parte desse problema.

### Passo 3: Definir as Regras do Algoritmo.
Cada passo do algoritmo precisa ser simples e explícito, de forma a ser impossível
dividir um passo em 2 diferentes.

### Passo 4: Definir o Resultado do Algoritmo.
Para o algoritmo funcionar, é necessário que o mesmo produza um resultado, de
forma a sabermos que o mesmo funcionou, mesmo que o resultado seja vazio.
Importante notar que o algoritmo não pode ter uma duração infinita.

## Analisando Algoritmos
&nbsp; Antes de avaliarmos a eficiência de um algoritmo, primeiro devemos
verificar se o mesmo é um algoritmo válido, para tal, verificamos se em todas
as vezes que o algoritmo corre com algum *input* possível, nós sempre temos o
*output* esperado. Para além disso, podemos também declarar que para cada input
possível, o algoritmo deve finalizar, caso ele corra infinitamente, o algoritmo
não é válido.

### Eficiência de um Algoritmo

&nbsp; Existem dois parâmetros a se verificar quando falamos da eficiência de
um algoritmo, são elas: tempo e espaço.

###### Time Complexity
&nbsp; É a medida definida pelo tempo o algoritmo levou para terminar o seu
trabalho.

###### Space Complexity
&nbsp; É a medida definida pela memória que o algoritmo utilizou para completar
o seu trabalho.

#### Medindo a Eficiência Temporal.
&nbsp; Para podermos verificar a eficiência temporal de um dado algoritmo,
observamos quantas tentativas o algoritmo necessita para encontrar a resposta no:

1. Melhor caso.

2. Pior caso.

3. Caso mediano.

&nbsp;Como exemplo, em um jogo de advinhar números, sendo os possíveis inputs [1;100]
, para um algoritmo que tenta cada número de forma crescente, teríamos:

1. Melhor caso = 1.

2. Pior caso = 100.

3. Caso mediano = 50.

&nbsp; Verificar o pior caso nos dá o benefício de saber qual o máximo de tempo
que o nosso algoritmo pode levar. Por conta disso, a eficiência temporal de um
algoritmo é baseada no tempo levado pelo pior caso. Desta forma criamos testes
com uma amostra de inputs cada vez maior, e é através destes teste que nós
definimos a forma padrão de se avaliar um algoritmo, o Growth Rate.

## Growth Rate / Order of Growth
&nbsp; Também conhecido como "*Big O*", é uma definição teórica da complexidade
de um algoritimo em função de seu tamanho. Podemos dizer que o mesmo é uma
notação usada para descrever a complexidade, neste caso, reduzindo esta a apenas
uma variável.

&nbsp; Um exemplo de complexidade escrita em forma de *Big O*, possui a seguinte
aparência:

###### O(n)
 - Neste simbolo, "**O**" significa "Ordem de magnetude da complexidade",sendo
esta complexidade os testes exercidos para encontrar a eficiência de um dado
algoritmo.

- Enquanto o "**(n)**" representa "Uma função de tamanho **n**", isso significa que o
 *Big O* mede a complexidade conforme o tamanho aumenta.

&nbsp; No caso temos que o *Big O* é uma função "O" que recebe como argumento um
tamanho "n" e retorna uma variável que representa o nível de complexidade de um
algoritmo.

&nbsp; A variável usada pelo **O(n)** reduz a informação para que ao ser lida,
sejamos capazes de notar a diferença sem termos que recorrer a métodos complicados.

> [!NOTE]
> &nbsp; É importante notar que a complexidade é algo relativo, quando avaliamos a
>complexidade de um algoritmo, fazemos isso comparando o mesmo com outros algoritmos.
>
> &nbsp; *Big O* é uma notação para entender a complexidade temporal e espacial,
>mas serve apenas quando fazemos comparações entre algoritmos que resolvem o
>mesmo problema.

### Tipos Comuns de *Big O*

&nbsp; Primeiramente é importante notar que não é apenas o algoritmo como um todo
que possui um *Big O*, todos os passos realizados pelo algoritmo possuem um
*Big O* próprio. O passo que é considerado menos eficiente é conhecido como *upper bound*
e é ele que define o *Big O* do Algoritmo.

##### Runtimes Considerados Eficientes

>- **O(1)** (Constant Time): Representa um algoritmo constante, onde o valor da amostra
não interfere em sua complexidade.
>
>Ex: Um teste de comparação entre o valor atual e o desejado.

>- **O(log n) ou O(ln n)** (Logarithmic Runtime): Representa um algoritmo que aumenta
de complexidade de acordo com "log<sub>x</sub> n". Este é um exemplo de um *Big O*
sublinear.
>
>Ex: Uma busca binária, onde procuramos sempre a partir da metade, depois
descartamos a metade que sabemos que não precisamos, funciona como
"log<sub><sub>2</sub></sub>n".

>- **O(n)** (Linear Time): Representa um algoritmo que aumenta de complexidade
linearmente conforme aumentamos o tamanho da amostra.
>
> Ex: Uma busca linear em um array de inteiros.

>- **O(n log n)** (Quasilinear Runtime): Representa um algoritmo em que para cada
valor de n, iremos executar (log n) operações.
>
>Ex: Quase todas operações de ordenação possuem um *Big O* deste tipo, merge sort
é um ótimo exemplo deste tipo.

>- **O(n<sup>2</sup>)** (Quadratic Time): Representa um algoritmo que possui uma
complexidade igual ao quadrado de "n".
>
> Ex: Uma busca linear em uma matriz de n * n.

>- **O(n<sup>3</sup>)** (Cubic Runtime): Representa um algoritmo que para uma
amostra de tamanho n, executa n<sup>3</sup> operações. Não é tão comum quanto
um Quadratic Runtime.



&nbsp; Os *Runtimes* descritos acima, são todos conhecidos como *Polynomial Runtime*.
Diz-se que um algoritimo possui um *polynomial runtime*, quando o seu
*Big O* possui um *Worst Case* na forma **O(n<sup>k</sup>)** para cada valor n
. Algoritmos que possuem um *polynomial runtime* são considerados algoritmos
eficientes.

##### Runtimes Considerados Ineficientes

>- **O(x<sup>n</sup>)** (Exponential Runtime): Representa um algoritmo em que
para cada caso "n", temos "x" possibilidades, sempre que aumentamos "n" passamos
a ter " x<sup>n</sup> " combinações.
>
> Ex: Uma palavra passe, para cada casa "x", temos "n" possibilidades, por tanto,
para cada casa que acrescentamos, aumentamos exponencialmente o número de possibilidades.

>- **O(n!)** (Factorial / Combinatorial Runtime): Representa um algoritmo em que
o *Big O* cresce de forma fatorial.
