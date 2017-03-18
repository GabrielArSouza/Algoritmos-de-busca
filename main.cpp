/* 
 * © copyright  2017 - Gabriel Araújo de Souza
 * Todos os direitos reservados - <gabriel_feg@hotmail.com>
 */


#include "Functions/functions.h"

//Tamanho default do vetor a ser alocado
//Representa o tamanho máximo que a máquina usada suporta
#define N 536870912; //2^29

/**
 * Declaração de novo tipo: ponteiro para a assinatura 
 * das funções de busca criadas
 */
using SearchFuncType = bool ( * ) 
							(const std::vector<unsigned long long> &,
							 std::size_t,
							 std::size_t,
							 unsigned long long );
                    

int main (int argc, char * argv[]){

	/*ṔONTEIRO PARA AS FUNÇÕES*/
	SearchFuncType SearchesAlgo[] = {
		SsequentialIt, //0
		SsequentialRec, //1
		SbinaryIt,//2
		SbinaryRec,//3
		STernaryIt,//4
		STernaryRec,//5
		Sbinary,//6
		Sfind//7
	};

	auto arrSz(0ul);

	/**
	 *  Aqui queremos verificar se o usuário digiou o limite de
	 *  posições do vetor, caso ele não tenha passado esse valor
	 *  como parâmetro, o programa assumirá que o tamanho máximo 
	 *  do vetor é o N definido anteriormente.
	 */
	if (argc > 1) //usuário especificou tamanho máximo
	{
		std::stringstream(argv[1]) >> arrSz;
	}
	else // sem argumentos, assume valor N.
	{
		arrSz = N;
	}

	//Mostrar tamanho do vetor
	std::cout << ">>> O tamanho máximo do vetor é: " << arrSz  << std::endl;

	//alocando espaço no vetor
	std::vector<unsigned long long> V(arrSz);		

	//preencher o vetor com valores sequenciais
	Fill (V, arrSz);

	/*Análise emṕírica dos algoritmos implementos*/
	//criando um valor impossível de existir no vetor
	unsigned long long key;
	key = 60000000000;

	//variável que calcular a média de tempo para cada teste
	// com quantidades de elementos diferentes
	std::chrono::duration<double, std::milli> media(0);
	int f;

	//iniciando um arquivo para armazenar os resultados
	//da análise.
	std::ofstream collect;
	collect.open("AnaliseSequencial.txt");
	
	//Cabeçalho - Identifica as funções testadas
	collect << "#QTD" << "			"
	  		<< "#SSI" << "			"
	  		<< "#FIND" <<  std::endl;
	  		
	for (auto i(5300000ull); i <= arrSz; i += 5300000 )
	/*
	 *Aqui temos uma divisão do vetor original em subvetores,
	 *isso serve para fazer testes para quantidades menores e 
	 *assim poder gerar um gráfico com os dados coletádos. 
	 *Ele funciona em forma de uma PA.
	 */
	{
		//informar pelo terminal quantos elementos 
		//o algoritmo está testando.
		std::cout << "Analisando para " << i << " posições..." << std::endl;
		collect << i << "			";

		for(f = 0; f < 8; f += 7)
		//Aqui fazemos a seleção da função testada
		//modificar os parâmetros do for para anaĺisar funções 
		//diferentes.
		{
			//informa o terminal qual função está rodando
			std::cout << "\tRODANDO FUNÇÃO " << f << std::endl;

			for (auto j(1ul); j <= 10; ++j)
			//rodar cada função 100 vezes para ter a média de tempo
			{
				auto start = std::chrono::steady_clock::now();
				//=============================================== 
				// função em teste
					
					(SearchesAlgo[f])(V, 0, i-1, key);
				//=============================================== 
				auto end = std::chrono::steady_clock::now();

				//calcular o tempo levado para executar a função
				auto diff = end - start;

				//armazenar diferença e evitar erros de arredondamento
				media = media + (diff - media)/j;
			}
			
			collect << std::chrono::duration <double, std::milli> (media).count() << "			";
		}
		collect << std::endl;
	}
	//fechar arquivo
	collect.close();
	//informar que o programa terminou a análise
	std::cout << ">>>ANÁLISE EMPÍRICA CONCLUÍDA<<<" << std::endl;

	return 0;
}
