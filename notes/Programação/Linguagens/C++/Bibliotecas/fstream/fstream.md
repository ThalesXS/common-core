# fstream
&nbsp; A biblioteca `fstream` nos permite trabalhar com ficheiros. Importante notar que para usar a mesma temos de incluir também a biblioteca `iostream`.

## Index

1. [`ofstream`](#ofstream)
	1. [Métodos Públicos](#Métodos%20Públicos)
	2. [Métodos Herdados de ostream]()
	3. [Métodos Herdados de ios]()
	4. [Métodos Herdados de ios_base]()
2. [ifstream](#ifstream)
3. [fstream](#fstream)
***
## ofstream
&nbsp; `ofstream` é uma das classes usada para realizar operação em ficheiros, através dela podemos criar ou abrir um ficheiro para escrevermos dentro.

```cpp
#include <iostream>
#include <fstream>

int main(void)
{
	std::ofstream my_file("filename");    //Create and open the file

	my_file << "Hello World!\n";
	my_file.close();                     //Close the file
	return (0);
}

```

### Métodos Públicos
* [(constructor)](#(constructor))
* [open](#open)
* [is_open](#is_open)
* [close](#close)
* [rdbuf](#rdbuf)
* [swap](#swap)

#### (constructor)
```cpp
//Prototype
explicit ofstream(const char *filename, ios_base::openmode mode = ios_base::out);
```
&nbsp; O constructor da classe `ofstream` funciona de forma similar ao seu método [`open`](#open).
###### Exemplos de Uso
&nbsp; O constructor da classe `ofstream` é responsável pela criação do objeto que estará associado ao ficheiro. Quando invocada com sua declaração padrão, o constructor cria um objeto sem o associar à qualquer ficheiro, podendo ser associado futuramente à um.
```cpp
//Default Constructor
#include <iostream>
#include <fstream>

int main(void)
{
	std::ofstream my_file;    //Only create the stream object
	my_file.open("filename");  //Associates an file to the stream
	
	return (0);
}
```


&nbsp; Quando utilizado como inicializador, podemos associar o objeto à um ficheiro no momento de sua criação. Para tal, enviamos o nome do ficheiro como primeiro argumento `filename`, podendo também enviar `mode` como segundo argumento.
```cpp
//Initialization Constructor
#include <iostream>
#include <fstream>

int main(void)
{
	std::ofstream my_file("filename");    //Create and open the file

	my_file << "Hello World!\n";
	my_file.close();                     //Close the file
	return (0);
}
```
***
#### open
```cpp
//Prototype
void open(const char *filename, ios_base::openmode mode = ios_base::out);
```
&rdsh; `filename`:  String representando o nome do ficheiro a ser aberto.
&rdsh; `mode`: _Flag_ descrevendo o modo desejado para o ficheiro. Por ser um objeto do tipo _bitmap_, pode conter uma combinação das seguintes constantes.

| member constant | Significado  | Acesso                                                                                                  |
| --------------- | ------------ | ------------------------------------------------------------------------------------------------------- |
| in              | **in**put    | Abre o ficheiro para leitura.                                                                           |
| out             | **out**put   | Abre o ficheiro para escrita.                                                                           |
| binary          | **binary**   | Operações são realizadas em binário ao invés de texto.                                                  |
| ate             | **at e**nd   | A **posição de output** começará no final do ficheiro.                                                  |
| app             | **app**end   | Todas as operações de output serão realizadas no final do ficheiro, concatenando ao conteúdo existente. |
| trunc           | **trunc**ate | Qualquer conteúdo que existia antes do ficheiro ser aberto será descartado.                             |

&nbsp; Essas _flags_ podem ser combinadas com o uso do operador `|`.
> [!NOTE] Lembre
> &nbsp; Caso a _stream_ já esteja associada à um ficheiro, a operação irá falhar.

>[!TIP] Dica
>  &nbsp; Caso o parâmetro `mode` não receba qualquer argumento externo. o mesmo será definido como `out` (como demonstrado no protótipo).

> [!WARNING] Atenção
> &nbsp; C++98: Caso os modos `trunc` e `app` sejam definidos em conjunto, a operação de abertura irá falhar. O mesmo é verdade para `app` e `in`.
>
> &nbsp; C++11: Caso os modos `trunc` e `app` sejam definidos em conjunto, a operação de abertura irá falhar.
###### Exemplos de Uso
```cpp
#include <iostream>
#include <fstream>

int main(void)
{
	std::ofstream my_file;
	my_file.open("filename", std::ofstream::out | std::ofstream::app);
	
	return (0);
}
```

***
#### is_open
&nbsp; Verifica se a _stream_ se encontra associada à algum ficheiro.

&nbsp; _Streams_ podem ser associadas à ficheiros com invocações bem sucedidas do método `open()` ou diretamente pelo constructor, e desassociadas pela invocação do método `close()` ou destruição.

&nbsp; Retorna `TRUE` caso a _stream_ se encontre aberta ou `false` caso contrário.

###### Exemplos de Uso
```cpp
#include <iostream>
#include <fstream>

int main(void)
{
	string file_name;
	std::ofstream my_file;

	file_name = "file.txt";
	my_file.open(file_name);
	if (my_file.is_open())
	{
		std::cout << file_name << "has been opened\n";
		my_file.close();
	}
	else
	{
		std::cout << "An error has happened while trying to open " << file_name;
	}
	return (0);
}
```
***
#### close
&nbsp; Fecha o ficheiro associado à _stream_. Caso a _stream_ não esteja associada à qualquer ficheiro, a operação irá falhas.
###### Exemplos de Uso
```cpp
#include <iostream>
#include <fstream>

int main(void)
{
	std::ofstream my_file("text.txt");

	std::cout << "Hello World!\n";
	my_file.close();
	return (0);
}
```
***
## ifstream
&nbsp; `ifstream` é uma das classes usada para realizar operação em ficheiros, através dela podemosabrir um ficheiro para lermos seus dados.

```cpp
#include <iostream>
#include <fstream>

int main(void)
{
	std::ifstream my_file("filename");    //Open the file

	while (getline (MyReadFile, myText))    // Read the lines from the file.
	{   
		cout << myText;                    // Print the lines.
	}
	my_file.close();                     //Close the file
	return (0);
}
```

### Métodos Públicos
* [(constructor)](#(constructor))
* [open](#open)
* [is_open](#is_open)
* [close](#close)
* [rdbuf](#rdbuf)
* [swap](#swap)

#### (constructor)
```cpp
//Prototype
explicit ifstream(const char* filename, ios_base::openmode mode = ios_base::in);
```
&nbsp; O constructor da classe `ifstream` funciona de forma similar ao seu método [`open`](#open).
###### Exemplos de Uso
&nbsp; O constructor da classe `ifstream` é responsável pela criação do objeto que estará associado ao ficheiro. Quando invocada com sua declaração padrão, o constructor cria um objeto sem o associar à qualquer ficheiro, podendo ser associado futuramente à um.
```cpp
//Default Constructor
#include <iostream>
#include <fstream>

int main(void)
{
	std::ifstream my_file;    //Only create the stream object
	my_file.open("filename");  //Associates an file to the stream
	
	return (0);
}
```


&nbsp; Quando utilizado como inicializador, podemos associar o objeto à um ficheiro no momento de sua criação. Para tal, enviamos o nome do ficheiro como primeiro argumento `filename`, podendo também enviar `mode` como segundo argumento.
```cpp
//Initialization Constructor
#include <iostream>
#include <fstream>

int main(void)
{
	std::ifstream my_file("filename");    //Open the file

	while (getline (MyReadFile, myText))    // Read the lines from the file.
	{   
		cout << myText;                    // Print the lines.
	}
	my_file.close();                     //Close the file
	return (0);
}
```
***
#### open
```cpp
//Prototype
void open(const char *filename, ios_base::openmode mode = ios_base::in);
```
&rdsh; `filename`:  String representando o nome do ficheiro a ser aberto.
&rdsh; `mode`: _Flag_ descrevendo o modo desejado para o ficheiro. Por ser um objeto do tipo _bitmap_, pode conter uma combinação das seguintes constantes.

| member constant | Significado  | Acesso                                                                                                  |
| --------------- | ------------ | ------------------------------------------------------------------------------------------------------- |
| in              | **in**put    | Abre o ficheiro para leitura.                                                                           |
| out             | **out**put   | Abre o ficheiro para escrita.                                                                           |
| binary          | **binary**   | Operações são realizadas em binário ao invés de texto.                                                  |
| ate             | **at e**nd   | A **posição de output** começará no final do ficheiro.                                                  |
| app             | **app**end   | Todas as operações de output serão realizadas no final do ficheiro, concatenando ao conteúdo existente. |
| trunc           | **trunc**ate | Qualquer conteúdo que existia antes do ficheiro ser aberto será descartado.                             |

&nbsp; Essas _flags_ podem ser combinadas com o uso do operador `|`.
> [!NOTE] Lembre
> &nbsp; Caso a _stream_ já esteja associada à um ficheiro, a operação irá falhar.

>[!TIP] Dica
>  &nbsp; Caso o parâmetro `mode` não receba qualquer argumento externo. o mesmo será definido como `in` (como demonstrado no protótipo).

> [!WARNING] Atenção
> &nbsp; C++98: Caso o modo `app` seja definido, a operação irá falhar. O mesmo é verdade caso `trunc` seja definido sem `out`.
>
> &nbsp; C++11: Caso os modos `trunc` e `app` sejam definidos em conjunto, a operação de abertura irá falhar. O mesmo é verdade caso `trunc` seja definido sem `out`.
###### Exemplos de Uso
```cpp
#include <iostream>
#include <fstream>

int main(void)
{
	std::ifstream my_file;
	my_file.open("filename");
	
	return (0);
}
```

***
#### is_open
&nbsp; Verifica se a _stream_ se encontra associada à algum ficheiro.

&nbsp; _Streams_ podem ser associadas à ficheiros com invocações bem sucedidas do método `open()` ou diretamente pelo constructor, e desassociadas pela invocação do método `close()` ou destruição.

&nbsp; Retorna `TRUE` caso a _stream_ se encontre aberta ou `false` caso contrário.

###### Exemplos de Uso
```cpp
#include <iostream>
#include <fstream>

int main(void)
{
	string file_name;
	std::ifstream my_file;

	file_name = "file.txt";
	my_file.open(file_name);
	if (my_file.is_open())
	{
		while (getline (MyReadFile, myText))
		{   
			cout << myText;
		}
		my_file.close();
	}
	else
	{
		std::cout << "An error has happened while trying to open " << file_name;
	}
	return (0);
}
```
***
#### close
&nbsp; Fecha o ficheiro associado à _stream_. Caso a _stream_ não esteja associada à qualquer ficheiro, a operação irá falhas.
###### Exemplos de Uso
```cpp
#include <iostream>
#include <fstream>

int main(void)
{
	std::ifstream my_file("text.txt");

	while (getline (MyReadFile, myText))
	{   
		cout << myText;
	}
	my_file.close();
	return (0);
}
```
***
## fstream
&nbsp; A classe `fstream` é capaz de abrir _streams_ tanto para _input_ quanto para _output_.

```cpp
#include <iostream>
#include <fstream>

int main(void)
{
	std::fstream my_file("text.txt", std::fstream::in | std::fstream::out);    // Open the file
	[...]                                // i/o operation
	my_file.close();                     // Close the file
	return (0);
}
```

### Métodos Públicos
* [(constructor)](#(constructor))
* [open](#open)
* [is_open](#is_open)
* [close](#close)
* [rdbuf](#rdbuf)
* [swap](#swap)

#### (constructor)
```cpp
//Prototype
explicit fstream (const char* filename, ios_base::openmode mode = ios_base::in | ios_base::out);
```
&nbsp; O constructor da classe `fstream` funciona de forma similar ao seu método [`open`](#open).
###### Exemplos de Uso
&nbsp; O constructor da classe `fstream` é responsável pela criação do objeto que estará associado ao ficheiro. Quando invocada com sua declaração padrão, o constructor cria um objeto sem o associar à qualquer ficheiro, podendo ser associado futuramente à um.
```cpp
//Default Constructor
#include <iostream>
#include <fstream>

int main(void)
{
	std::fstream my_file;

	my_file.open("text.txt", std::fstream::in | std::fstream::out);
	[...]                                // i/o operation
	my_file.close();                     // Close the file
	return (0);
}
```


&nbsp; Quando utilizado como inicializador, podemos associar o objeto à um ficheiro no momento de sua criação. Para tal, enviamos o nome do ficheiro como primeiro argumento `filename`, podendo também enviar `mode` como segundo argumento.
```cpp
//Initialization Constructor
#include <iostream>
#include <fstream>

int main(void)
{
	std::fstream my_file("text.txt", std::fstream::in | std::fstream::out);   // Open the file
	[...]                                // i/o operation
	my_file.close();                     // Close the file
	return (0);
}
```
***
#### open
```cpp
//Prototype
void open(const char *filename, ios_base::openmode mode = ios_base::in | ios_base::out);
```
&rdsh; `filename`:  String representando o nome do ficheiro a ser aberto.
&rdsh; `mode`: _Flag_ descrevendo o modo desejado para o ficheiro. Por ser um objeto do tipo _bitmap_, pode conter uma combinação das seguintes constantes.

| member constant | Significado  | Acesso                                                                                                  |
| --------------- | ------------ | ------------------------------------------------------------------------------------------------------- |
| in              | **in**put    | Abre o ficheiro para leitura.                                                                           |
| out             | **out**put   | Abre o ficheiro para escrita.                                                                           |
| binary          | **binary**   | Operações são realizadas em binário ao invés de texto.                                                  |
| ate             | **at e**nd   | A **posição de output** começará no final do ficheiro.                                                  |
| app             | **app**end   | Todas as operações de output serão realizadas no final do ficheiro, concatenando ao conteúdo existente. |
| trunc           | **trunc**ate | Qualquer conteúdo que existia antes do ficheiro ser aberto será descartado.                             |

&nbsp; Essas _flags_ podem ser combinadas com o uso do operador `|`.
> [!NOTE] Lembre
> &nbsp; Caso a _stream_ já esteja associada à um ficheiro, a operação irá falhar.

> [!WARNING] Atenção
> &nbsp; C++98: Caso o modo `trunc` e `app` sejam definidos, a operação irá falhar. O mesmo é verdade caso um dos dois seja definido sem `out`, ou caso `app` sejá definido com `in`.
>
> &nbsp; C++11: Caso o modo `trunc` e `app` sejam definidos, a operação irá falhar. O mesmo é verdade caso `trunc` sem `out`.
###### Exemplos de Uso
```cpp
#include <iostream>
#include <fstream>

int main(void)
{
	std::fstream my_file;
	my_file.open("filename");
	
	return (0);
}
```

***
#### is_open
&nbsp; Verifica se a _stream_ se encontra associada à algum ficheiro.

&nbsp; _Streams_ podem ser associadas à ficheiros com invocações bem sucedidas do método `open()` ou diretamente pelo constructor, e desassociadas pela invocação do método `close()` ou destruição.

&nbsp; Retorna `TRUE` caso a _stream_ se encontre aberta ou `false` caso contrário.

###### Exemplos de Uso
```cpp
#include <iostream>
#include <fstream>

int main(void)
{
	string file_name;
	std::ifstream my_file;

	file_name = "file.txt";
	my_file.open(file_name);
	if (my_file.is_open())
	{
		while (getline (MyReadFile, myText))
		{   
			cout << myText;
		}
		my_file.close();
	}
	else
	{
		std::cout << "An error has happened while trying to open " << file_name;
	}
	return (0);
}
```
***
#### close
&nbsp; Fecha o ficheiro associado à _stream_. Caso a _stream_ não esteja associada à qualquer ficheiro, a operação irá falhas.
###### Exemplos de Uso
```cpp
#include <iostream>
#include <fstream>

int main(void)
{
	std::ifstream my_file("text.txt");

	while (getline (MyReadFile, myText))
	{   
		cout << myText;
	}
	my_file.close();
	return (0);
}
```
***
