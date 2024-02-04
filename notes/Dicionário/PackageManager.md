## O que é o APT?
&nbsp; O _**Advanced Packaging Tool**_ (APT) é uma ferramenta da linha de comando padrão do Linux, não possuindo interface gráfica, para gerenciar as ferramentas que já estão ou serão instaladas.

&nbsp;Possui diversos sub-comandos para que os pacotes sejam "automaticamente" instalados, atualizados, deletados ou consertados.

- `apt install <package>`
>&nbsp; Instala pacotes através do APT.

- `apt remove <package>`
>&nbsp; Remove o pacote desejado através do APT.

- `apt update`
>&nbsp; Atualiza a lista de pacotes no arquivo `/etc/apt/sources.list` e no diretório `/etc/apt/sources.list.d`, adicionando as alterações feitas recentemente.

- `apt upgrade`
>&nbsp; Atualiza os pacotes registrados com o sub-comando `update`, efetuando as alterações mais recentes no repositório dos pacotes.

- `apt list`
>&nbsp; Lista todos os pacotes disponíveis, instalados e que podem ser atualizados.

- `apt search <package>`
>&nbsp; Procura por um pacote específico na lista de pacotes disponíveis.

- `apt show <package>`
>&nbsp; Apresenta as informações do pacote, entre elas: dependências, tamanho, fonte, etc. Pode ser útil antes de remover ou instalar novos pacotes.

## O que é o Aptitude?

&nbsp; O *Aptitude* é uma ferramenta similar ao APT, porém, diferente do APT, ela não vem pré-instalada nos sistemas Linux. Para tal, é necessário usar o comando `apt install aptitude`. Diferente do APT, o Aptitude possui interface gráfica.

&nbsp; Quando o comando `aptitude` é usado, um menu será apresentado no terminal, sendo uma opção mais "*user-friendly*". A maior parte das funções de um gerenciador de pacotes pode ser realizada no Aptitude com comandos simples.

| Botão | Ação |
|-------|------|
|&larr;&uarr;&rarr;&darr;| Movimenta-se através do menu.|
|Enter| Abre a categoria selecionada.|
|+| Adiciona o pacote atual para instalação.|
|-| Adiciona o pacote atual para remoção.|
|g| Apresenta um sumário das ações a serem realizadas, caso seja apertado novamente, realiza tais ações|
|u| Realiza a mesma ação que `apt update`|
|U| Adiciona todos os pacotes com atualizações à lista de ações.|
|i| Altera as informações apresentadas no menu.|
|q| Fecha o Aptitude.|
|?| Apresenta um guia de como usar o menu.|

### APT vs. Aptitude
&nbsp; Principais diferenças do APT para o Aptitude.

- Apenas o Aptitude possui interface gráfica.
- Quando se depara com conflitos entre os pacotes, apenas o Aptitude sugere soluções.
- Aptitude é capaz de apresentar a "*CHANGELOG*" do Debian de todos os pacotes disponíveis.
