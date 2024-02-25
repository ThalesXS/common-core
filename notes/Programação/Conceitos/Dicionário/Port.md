## O que é uma "Porta" no Computador?
&nbsp; *Ports* são locais virtuais dentro de um OS (*Operating System*) por onde conexões de rede começam e acabam. Elas ajudam os computadores a organizar o trafego que recebem.

&nbsp; Cada porta é associada à um processo ou serviço específico o que faz com que *e-mails* e *websites* façam uso de portas diferentes por exemplo, mesmo que ambas cheguem através da mesma conexão de *internet*.

## O que é o Número da Porta?
&nbsp; As portas são padronizadas por todos os dispositivos conectados a rede, sendo designado um número especifico para cada porta. A maior parte desses números é reservado para certos [protocolos](), por exemplo, toda mensagem do *[Hypertext Transfer Protocol (HTTP)]()* é enviada para porta 80 **(*port* 80)**.

Enquanto *[endereços IP]()* permitem que mensagens sejam enviadas de um dispositivos à outro, o número da porta permite escolher o serviço ou aplicação para onde a mensagem deve ser enviada dentro de tal dispositivo.

## Algumas das Portas Mais Usadas.

&nbsp; Existem ao todo **65.535 números de porta**, embora nem todas sejam usadas no cotidiano. Segue abaixo alguma das portas mais usadas e seus respectivos protocolos:

<details><summary><i><b>Port Numbers</b></i></summary>

>- **Port 20/21**: *[File Transfer Protocol (FTP)]()*. Serve para transferir arquivos entre um cliente e o servidor.
>
>
>- **Port 22**: *[Secure Shell (SSH)]()*. Um dos muitos protocolos de atrelamento para criação de redes seguras.
>
>
>- **Port 25**: Historicamente, *[Simple Mail Transfer Protocol (SMTP)]()* é usado para *e-mails*.
>
>
>- **Port 53**: *[Domain Name System (DNS)]()* é um processo essencial na *internet* moderna, ela associa nomes de domínios legíveis pelo ser humano, à [endereços IP](), permitindo aos usuários carregar *websites* e aplicações sem ter que memorizar listas de endereços IP.
>
>
>- **Port 80**: *[Hypertext Transfer Protocol (HTTP)]()* é o protocolo que permite o *[World Wide Web (WWW)]()* existir.
>
>
>- **Port 123**: *[Network Time Protocol (NTP)]()* permite o relógio dos computadores sincronizarem uns com os outros, esse processo é essencial para encriptação.
>
>
>- **Port 179**: *[Border Gateway Protocol](BGP)*. Essencial para estabelecer rotas eficientes entre a grandes redes que formam a *internet*. Sistemas autônomos usam o *BGP* para transmitir qual endereço IP eles contralam.
>
>
>- **Port 443**: *[HTTP Secure (HTTPS)]()* é a versão segura e encriptada do HTTP. Todo trafego da rede HTTPS usa esta porta, e serviços de encriptação que usam HTTP (como o DNS sobre HTTPS), também usam esta porta.
>
>

>- **Port 3389**: *[Remote Desktop Protocol (RDP)]()* permite aos usuários se conectarem remotamente à seus computadores a partir de outro dispositivo.

</details>

## Por quê as Vezes *Firewalls* Bloqueiam Algumas Portas Específicas?
&nbsp; Um *[firewall]()* é um sistema de segurança que bloqueia ou permite o trafego de rede baseado em uma série de regras de segurança. Estando geralmente entre uma rede confiável e uma rede insegura, sendo esta a maior parte das vezes a *internet*.

&nbsp; Alguns *hackers* tentam enviar tráfegos maliciosos para portar aleatórias à espera de que alguma delas tenha sido deixada "aberta", o que significa que está disponível para receber trafego. Por esta razão, os *firewalls* devem ser configurados para bloquear o trafego de internet para a maior parte das portas disponíveis, uma vez que não há um motivo plausível para essas portas receberem algum conteúdo.
