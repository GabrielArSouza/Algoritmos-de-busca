********************************************************
|                   Desenvolvido por:                  |
|                Gabriel Araújo de Souza               |
|  Data: 13/03/2017  - Todos os Direitor reservados    |
|                                                      |
********************************************************

Objetivo: Implementar 6 algoritmos de busca e realizar a 
          análise empírica de cada um deles

-> Trabalho realizado para a disciplina de Estruturas de 
   dados básicas - IMD-UFRN
-> Curso de Tecnologia da Informação

**Nota: Antes de executar o programa alguns parametros 
devem ser observados

1º Por padrão o código roda a busca sequencial iterativa
e a busca std::find, caso outro algoritmo deseje ser testado,
o arquivo main.cpp necessita ser modificado.

2º A amostra padrão de testes é 2^29, tamanho máximo que a 
máquina consegue alocar de um vetor, caso deseje entrar com um
vetor de tamanho menor, isso pode ser feito como ./bin [tam].

3º Caso mude o tamanho do vetor padrão, o código main.cpp deve 
ser alterado. O programa utiliza a metodologia de alocar um 
vetor do tamanho maximo informado, preencher com valores 
sequenciais de 0 - max informado, dividir esse vetor em subvetores
menores e realizar os teste. Por padrão essa divisão começa com os
primeiro 5,3 milhões de elementos do vetor, o proximo teste com mais
10,6 mihões e assim por diante até o final do vetor, esses testes são
feitos em uma PA.

4º Por padrão, o programa salva os testes em um arquivo chamado
"AnaliseSequencial.txt", esse nome pode ser mudado facilmente no código.
Há tambem uma parte que imprime um cabeçalho neste arquivo para poder
identificar a que função os teste pertences e pode ser alterado facilmente.

** Descrição de Pastas e arquivos
Includes

-> Nesta pasta tem o arquivo "includes.h", este arquivo é responsável por 
conter todas as bibliotecas c++ utilizadas no projeto.

Functions

-> Esta pasta contén os arquivos "functions.cpp" e "functions.h", são as 
responsáveis por carregar todas as funções de busca e a de preencher o vetor
que são utilizadas pelos programas

main.cpp

->Este arquivo é parte principal do programa, nele faz-se a chamada das
funções e todas as alterações para resultados diferentes devem ser feitos
nesta parte.

Makefile

->Para instruções de como compilar o programa, verificar este arquivo. 


