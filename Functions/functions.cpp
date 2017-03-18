/* 
 * © copyright  2017 - Gabriel Araújo de Souza
 * Todos os direitos reservados - <gabriel_feg@hotmail.com>
 */

//Heades das funções
#include "functions.h"


/**
 * @brief      Esta função preenche o vetor com valores 
 *             sequenciais de 0 até o tamanho do vetor
 *
 * @param      V      Vetor alocado no main onde serão armazenados
 *                    os elementos que as funções de busca procurarão.
 * @param[in]  arrSz  tamanho do vetor alocado
 */
void Fill (std::vector<unsigned long long> &V, const std::size_t arrSz)
{
	auto j(0ull);
	for (auto i(0ull); i < arrSz; ++i)
	{
		V[i] = j;
		j++;
	}
	
}


/**
 * @brief      Busca Sequecial Iterativa, ao ser passado uma chave
 *             procura-se este valor posição por posição do vetor.
 *
 * @param[in]  V    Vetor com os elementos sobre qual será realizado a busca. 										  
 * @param[in]  l    Posição inicial do vetor, define em qual posição a busca será iniciada.					
 * @param[in]  r    Posição final do vetor, define o limite do intervalo do vetor, para se realizar a busca. 					
 * @param[in]  key  Valor que pretende-se verificar sua existência no vetor.
 *
 * @return     retorna true caso o valor seja encontrado e false se não for.
 */
bool SsequentialIt(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key)
{
	for (auto i(l); i <= r; ++i){
		if (V[i] == key) return true;
	}
	return false;

}


/**
 * @brief      Busca sequencial Recursiva, faz a mesma coisa da função
 *             anterior, no entanto sua implementação é de forma recursiva
 *
 * @param[in]  V    Vetor com os elementos sobre qual será realizado a busca. 										  
 * @param[in]  l    Posição inicial do vetor, define em qual posição a busca será iniciada.					
 * @param[in]  r    Posição final do vetor, define o limite do intervalo do vetor, para se realizar a busca. 					
 * @param[in]  key  Valor que pretende-se verificar sua existência no vetor.
 *
 * @return     Se o valor for encontrado true, senão retorna a chamada de função
 *             novamente, caso percorra todo intervalo do vetor e não tenha achado
 *             o valor procurado retorna false.
 */
bool SsequentialRec(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key)
{
	if (l > r)
	{
		return false;

	}else if (V[l] == key) {
		return true;
	}else{
		return SsequentialRec(V, l+1, r, key);
	}
}

/**
 * @brief      Busca Binária Iterativa, faz a busca de um elemento no vetor dividindo ele
 *             ao meio, caso ache a função encerra senão faz a busca em um intervalo que 
 *             corresponde a metade do analisádo.
 *
 * @param[in]  V    Vetor com os elementos sobre qual será realizado a busca. 										  
 * @param[in]  l    Posição inicial do vetor, define em qual posição a busca será iniciada.					
 * @param[in]  r    Posição final do vetor, define o limite do intervalo do vetor, para se realizar a busca. 					
 * @param[in]  key  Valor que pretende-se verificar sua existência no vetor.
 *
 * @return     Se o valor procurado for encontrado retorna true, senão false
 */
bool SbinaryIt(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key)
{
	auto half(0ul); 
	
	while (l <= r)
	{
		half = (l+r)/2;
		
		if (V[half] == key){
			return true;
		}else if (V[half] > key){
			r = half-1;
		}else if (V[half] < key){
			l = half+1;
		}
	}
	return false;
}

/**
 * @brief       Busca Binária Recursiva, faz a mesma coisa da função
 *              anterior, no entanto sua implementação é de forma recursiva
 *
 * @param[in]  V    Vetor com os elementos sobre qual será realizado a busca. 										  
 * @param[in]  l    Posição inicial do vetor, define em qual posição a busca será iniciada.					
 * @param[in]  r    Posição final do vetor, define o limite do intervalo do vetor, para se realizar a busca. 					
 * @param[in]  key  Valor que pretende-se verificar sua existência no vetor.
 *
 * @return     se o valor encontrado retorna true, se não retorna a chamada da função com
 *             novos índices de acordo com condições analisadas, se todo o intervalo do vetor
 *             for percorrido e valor não encontrado, retorna false.
 */

bool SbinaryRec(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key)
{
	if (l <= r)	 
	{
		int half = (l+r)/2;

		if (V[half] == key) {
			return true;
		}else if (V[half] > key){
			return SbinaryRec(V, l, half-1, key);
		}else if (V[half] < key){
			return SbinaryRec(V, half+1, r, key);
		}
	}
	return false;
}


/**
 * @brief      Busca Ternária Iterativa, faz a busca de um elemento em um vetor dividindo-o
 *             em três partes de mesmo tamanho.
 *
 * @param[in]  V    Vetor com os elementos sobre qual será realizado a busca. 										  
 * @param[in]  l    Posição inicial do vetor, define em qual posição a busca será iniciada.					
 * @param[in]  r    Posição final do vetor, define o limite do intervalo do vetor, para se realizar a busca. 					
 * @param[in]  key  Valor que pretende-se verificar sua existência no vetor.
 *
 * @return     Se o valor encontrado retorna true, caso contrário false.
 */
bool STernaryIt(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key)
{
	auto t1(0);
	auto t2(0);

	while (l <= r)
	{
		t1 = (r-l)/3 + l;
		t2 = ((r-l)/3)*2 + l;

		if(V[t1] == key){
			return true;
		}else if (V[t2] == key){
			return true;
		}else if (V[t1] > key){
			//evitar Falha de segmentação
			if ((t1-1) < 0){
				return false;
			}else r = t1-1;
		}else if (V[t2] > key){
			l = t1+1;
			//evitar falha de segmentação
			if ((t2-1) < 0){
				return false;
			}else r = t2-1;
		}else {
			l = t2+1;
		}
	}
	return true;
}


/**
 * @brief      Busca Ternária Recursiva, faz a mesma coisa da função anterior, no entanto
 *             sua implementação é de forma recursiva.
 *
 * @param[in]  V    Vetor com os elementos sobre qual será realizado a busca. 										  
 * @param[in]  l    Posição inicial do vetor, define em qual posição a busca será iniciada.					
 * @param[in]  r    Posição final do vetor, define o limite do intervalo do vetor, para se realizar a busca. 					
 * @param[in]  key  Valor que pretende-se verificar sua existência no vetor.
 *
 * @return     Caso o valor seja encontrado, retorna true, se não faz a chamada da função com novos
 *             parâmetros de acordo com certas condições, se todo o vetor for percorrido e o valor não for
 *             achad, retorna-se false.
 */
bool STernaryRec(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key)
{
	if (l > r)
	{
		return false;
	}else {
		int t1 = (r-l)/3 + l;
		int t2 = ((r-l)/3)*2 + l;

		if(V[t1] == key){
			return true;
		}else if (V[t2] == key){
			return true;
		}else if (V[t1] > key){
			//evitar Falha de segmentação
			if ((t1-1) < 0){
				return false;
			}else return STernaryRec(V, l, t1-1, key);
		}else if (V[t2] > key){
			//evitar falha de segmentação
			if ((t2-1) < 0){
				return false;
			}else return STernaryRec(V, t1+1, t2-1, key);
		}else {
			return STernaryRec(V, t2+1, r, key);
		}
	}
}

/**
 * @brief      Busca Find, utiliza a função std::find implementada em <algorithm> para 
 *             realizar a busca de um elemento em um vetor.
 *
 * @param[in]  V    Vetor com os elementos sobre qual será realizado a busca. 										  
 * @param[in]  l    Posição inicial do vetor, define em qual posição a busca será iniciada.					
 * @param[in]  r    Posição final do vetor, define o limite do intervalo do vetor, para se realizar a busca. 					
 * @param[in]  key  Valor que pretende-se verificar sua existência no vetor.
 *
 * @return     Se o valor encontrado retorna true, senão false.
 */
bool Sfind(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key)
{
	auto result = std::find(V.begin()+l, V.begin()+r+1, key);
	if (result != (V.begin()+r+1))
		return true;
	else return false;
}


/**
 * @brief     Busca Binary_Search, utiliza a função bynary_search implementada em <algorithm> para
 *            realiza a busca de um elemento em um vetor
 *
 * @param[in]  V    Vetor com os elementos sobre qual será realizado a busca. 										  
 * @param[in]  l    Posição inicial do vetor, define em qual posição a busca será iniciada.					
 * @param[in]  r    Posição final do vetor, define o limite do intervalo do vetor, para se realizar a busca. 					
 * @param[in]  key  Valor que pretende-se verificar sua existência no vetor.
 *
 * @return     Se o valor for encontrado retorna true, senão false.
 */
bool Sbinary(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key)
{
	return std::binary_search(V.begin()+l, V.begin()+r+1, key);
}

