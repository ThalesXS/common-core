## *Uncomplicated Firewall* (UFW)
&nbsp; *Uncomplicated Firewall* é um programa para gerenciar *netfilter firewall* de forma fácil e prática através da linha de comandos.

### Comandos UFW.
&nbsp; O UFW usa o [CLI](Linux\1.%20Command%20Line%20Interface.md) para gerenciar de forma conveniente o *firewall*.

#### Estado
<br>

- *`ufw status`*
>&nbsp; Indica se o *Firewall* se encontra ativo ou não, bem como informações relativas a regras criadas.

- *`ufw status verbose`*
>&nbsp; Concede informações mais relevantes sobre o estado atual do *UFW* quando o mesmo encontra-se ativo.

- *`ufw status numbered`*
>&nbsp; Similar a opção anterior, porém passa a enumerar as regras criadas.

#### Ativar e Desativar
<br>

- *`ufw enable`*
>&nbsp; Caso o UFW esteja desativado, irá ativar o mesmo.

- *`ufw disable`*
>&nbsp; Caso o UFW esteja ativado, irá desativar o mesmo.


#### Gerenciando Portas
<br>

- *`ufw allow <port>/<protocol>`*
>&nbsp; Permite a entrada de pacotes que façam uso do protocolo designado na porta descrita, caso nenhum protocolo seja designado, todos serão aceitos pela porta.
>
> <details><summary><i><b>Examples</b></i></summary>
><br>
>
>- *`ufw allow 42`*
>>&nbsp; Permite a entrada de pacotes pela porta 42.
>
>- *`ufw allow 42/tcp`*
>>&nbsp; Apenas os pacotes de protocolo TCP serão aceitos na porta 42.

</details>

- *`ufw deny <port>/<protocol>`*
>&nbsp; Bloqueia a entrada de pacotes que façam uso do protocolo designado na porta descrita, caso nenhum protocolo seja designado, todos serão bloqueados pela porta.
>
> <details><summary><i><b>Examples</b></i></summary>
><br>
>
>- *`ufw deny 53`*
>>&nbsp; Bloqueia todos os pacotes na porta 53, efetivamente bloqueando a porta como um todo.
>
>- *`ufw deny 53/ucp`*
>>&nbsp; Bloqueia a entrada de pacotes UCP na porta 53.

</details>

#### Gerenciando Serviços
<br>

- *`ufw allow <service name>`*
>&nbsp; Permite o funcionamento do serviço através de seu nome.
> <details><summary><i><b>Examples</b></i></summary>
><br>
>
>- *`ufw allow ssh`*
>>&nbsp; Permite o funcionamento do serviço "_**ssh**_".

</details>

- *`ufw deny <service name>`*
>&nbsp; Bloqueia o funcionamento do serviço através de seu nome.
> <details><summary><i><b>Examples</b></i></summary>
><br>
>
>- *`ufw deny ssh`*
>>&nbsp; Bloqueia o funcionamento do serviço "_**ssh**_"

</details>

#### Gerenciando Endereços IP
<br>

- *`ufw allow from <ip address>`*
>&nbsp; Permite pacotes vindos do endereço IP especificado.
> <details><summary><i><b>Examples</b></i></summary>
><br>
>
>- *`ufw allow from 207.46.232.182`*
>>&nbsp; Permite a entrada dos pacotes vindo do IP "207.46.232.182".

</details>

- *`ufw deny from <ip address>`*
>&nbsp; Bloqueia os pacotes vindo do endereço IP indicado.
> <details><summary><i><b>Examples</b></i></summary>
><br>
>
>- *`ufw deny from 207.46.232.182`*
>>&nbsp; Bloqueia todos os pacotes vindo do endereço "207.46.232.182".

</details>


#### Gerencimento Avançado
<br>

- *`ufw allow from <ip address> to <destination> port <port number> proto <protocol>`*
>&nbsp; Adiciona mais restrições sobre o que será permitido, podemos adicionar apenas a porta específica, ou protocolo específico, ou então, ambos.
> <details><summary><i><b>Examples</b></i></summary>
><br>
>
>- *`ufw allow from 207.46.232.182 to any port 41`*
>>&nbsp; Permite todo pacote vindo do endereço "207.46.232.182" para a porta 41.
>
>- *`ufw allow from 207.46.232.182 to any port 41 proto tcp`*
>>&nbsp; Permite todo pacote de protocolo TCP vindo do endereço "207.46.232.182" para a porta 41".

</details>

- *`ufw deny from <ip address> to <destination> port <port number> proto <protocol>`*
>&nbsp; Bloqueia os pacotes do protocolo designado vindos do endereço IP para a porta específica.
> <details><summary><i><b>Examples</b></i></summary>
><br>
>
>- *`ufw deny from 207.46.232.182 to any port 33`*
>>&nbsp; Bloqueia todo pacote vindo do endereço "207.46.232.182" para a porta 33.
>
>- *`ufw deny from 207.46.232.182 to any port 33 proto ucp`*
>>&nbsp; Bloqueia todo pacote de protocolo UCP vindo do endereço "207.46.232.182" para a porta 33.

</details>

#### Apagar Regras Existentes
&nbsp; Para apagar regras criadas anteriormente, devemos saber a regra criada como um todo, ou então o número específico da regra criada (algo similar a um ID da regra).

- *`ufw delete <rule or rule number>`*
>&nbsp; Elimina a regra indicada no comando.
> <details><summary><i><b>Examples</b></i></summary>
><br>
>
>- *`ufw delete deny from 207.46.232.182`*
>>&nbsp; Apaga a regra que bloqueia todo pacote vindo do endereço "207.46.232.182".
>>
>>Supondo que esta regra tivesse como número correspondente "15", poderíamos também usar *`ufw delete 15`* para apagar tal regra.

</details>

#### Registro de Entradas (*Logging*).
&nbsp; Podemos definir se queremos registrar ou não as entradas efetuadas em nosso *firewall*, para tal, usamos:

- *`ufw logging on`*
>&nbsp; Ativa o registro de entradas.

- *`ufw logging off`*
>&nbsp; Desativa o registro de entradas.

Podemos também alterar o quanto de informação será registrado por cada entrada.

- *`ufw logging <logging_level>`*
> &nbsp; Altera o nível de informação que será registrado, temos como argumentos para _**\<logging_level\>**_:
><details><summary><i><b>Arguments</b></i></summary>
><br>
>
>- *`low`*
>>&nbsp; Guarda registros relacionados à pacotes que foram bloqueados por não obedecer as regras do firewall e apresenta registros relacionados às regras de registro.
>>
>>*PS: É possível definir regras para registros.*
>
>- *`medium`*
>>&nbsp; Para além dos registros guardados pelo nível *`low`*, você receberá registros para pacotes inválidos e novas conexões.
>
>- *`high`*
>> &nbsp; Inclui também registros para pacotes com e sem "*rate limiting*".
>
>- *`full`*
>> &nbsp; Similar ao *`high`*, porém não inclui o "*rate limiting*".

</details>

É possível também adicionar regras aos serviço de registro.
- *`ufw allow log <service_name>`*
>&nbsp; Permite o registro de entradas no _**\<service_name\>**_.

## Interpretando o Registro de Entradas (*Log Entries*).
&nbsp; Os valores **SPT**, **DPT**, **SRC** e **DST** são geralmente os valores que merecem mais atenção ao se analisar os registros do *firewall*.

Exemplo de uma *Log Entry*:
```bash
Feb  4 23:33:37 hostname kernel: [ 3529.289825] [UFW BLOCK] IN=eth0 OUT=
MAC=00:11:22:33:44:55:66:77:88:99:aa:bb:cc:dd SRC=444.333.222.111 DST=111.222.333.444 LEN=103 TOS=0x00
PREC=0x00 TTL=52 ID=0 DF PROTO=UDP SPT=53 DPT=36427 LEN=83
```

|Item|Descrição|
|---|---|
|\<*date*\>|Data e horário da criação da entrada.|
|\<*hostname*\>| Nome do Host do servidor.|
|\<*uptime*\>|Tempo em segundos desde o *boot*.|
|\<*logged event*\>|Uma curta descrição do evento registrado, neste caso [UFW BLOCK]|
|IN|Caso possua valor, significa que foi um evento de entrada.|
|OUT|Caso possua valor, foi um evento de saída.|
|MAC| Apresenta uma combinação de 14-bytes do destino MAC e fonte MAC, seguindo a ordem encontrada em *[Ethernet II header](https://en.wikipedia.org/wiki/Ethernet_frame)*. |
|SRC| Indica o IP fonte, no caso, quem enviou o pacote inicialmente.|
|DST| Indica o IP de destino, no caso, quem deverá receber o pacote. podemos usar o comando `whois` no *CLI* para determinar quem é o dono do endereço IP.|
|LEN|Indica o comprimento do pacote.|
|TOS|*Type of Service field* como indicado em *[IPv4 header](https://datatracker.ietf.org/doc/html/draft-xiao-tcp-prec-02)*.|
|PREC|*Precedence Field* como indicado em *[IPv4 header](https://datatracker.ietf.org/doc/html/draft-xiao-tcp-prec-02)*.|
|TTL|"*Time to Live*", basicamente cada pacote irá viajar entre um dado número de *routers* antes de desaparecer. Caso não consiga chegar ao destino antes atingir o número indicado pelo TTL, o pacote irá desaparecer, esse campo serve para impedir que pacotes de informações perdidos ocupem espaço na *internet* eternamente. Para mais informações veja a página da *[Wikipedia sobre TTL](https://en.wikipedia.org/wiki/Time_to_live)*.|
|ID| Apresenta um ID único do IP.|
|PROTO|Indica o protocolo do pacote.|
|SPT|Indica a porta fonte do pacote.|
|DPT|Indica a porta de destino do pacote.|
|WINDOW|Mostra o tamanho de pacote que o remetente está disposto a receber.|
|RES|Indica bits reservados.|
|SYN URGP| Indica que essa conexão necessita de |
