#include "includes.h"
#include "functions.h"


#define N 536870912; //2^29

using SearchFuncType = bool ( * ) 
							(const std::vector<unsigned long long> &,
							 std::size_t,
							 std::size_t,
							 unsigned long long );
                    

int main (int argc, char * argv[]){

	/*ṔONTEIRO PARA AS FUNÇÕES*/
	SearchFuncType SearchesAlgo[] = {
		SsequentialIt,
		SsequentialRec,
		SbinaryIt,
		SbinaryRec,
		STernaryIt,
		STernaryRec,
		Sfind,
		Sbinary
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

	//preencher o vetor com valores aleatórios
	Fill (V, arrSz);

	/*Análise emṕírica dos algoritmos implementos*/
	unsigned long long key;
	std::chrono::duration<double, std::milli> media(0);
	key = 600000000;
	int f;

	std::ofstream collect;
	collect.open("AnaliseEmpiricaIt.txt");
	//cabeçalho
	collect << "#QTD" << "			"
			<< "#SSI" << "			"
			<< "#SBI" << "			"
			<< "#STI" << std::endl;

	for (auto i(5300000ull); i <= arrSz; i += 5300000)
	{
		std::cout << "Analisando para " << i << " posições..." << std::endl;
		collect << i << "			";
		for(f = 0; f < 5; f = f+2)
		{
			std::cout << "\tRODANDO FUNÇÃO " << f << std::endl;
			for (auto j(1ul); j <= 100; ++j)
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
	collect.close();
	std::cout << ">>>ANÁLISE EMPÍRICA CONCLUÍDA<<<" << std::endl;

	// std::ofstream collect;
	// collect.open("AnaliseEmpirica.txt");
	// for (auto k(0); k < 3; ++k)
	// {
	// 	for(auto b(0); b < 16; ++b)
	// 	{
	// 		collect << std::chrono::duration <double, std::milli> (timeFunc[b][k]).count() << "\t";
	// 	}
	// 	collect << std::endl;
	// }
	// collect.close();
	

	return 0;
}