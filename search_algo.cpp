#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


int Sbinary_recursive (std::vector<int> V, std::size_t l, std::size_t r, int key);
int Sbinary_iterative (std::vector<int> V, std::size_t l, std::size_t r, int key);
int Ssequential_iterative (std::vector<int> V, std::size_t l, std::size_t r, int key);
int Ssequential_recursive (std::vector<int> V, std::size_t l, std::size_t r, int key);
int Sternary_iterative (std::vector<int> V, std::size_t l, std::size_t r, int key);
int Sternary_recursive (std::vector<int> V, std::size_t l, std::size_t r, int key);

int main (){

	std::vector<int> V = {1, 2, 3, 4, 5, 6, 7, 24, 32, 64};
	//auto arrSz = V.size();
	std::cout << "Que número dejesa buscar? " << std::endl;
	int num;
	std::cin >> num;

	// int position = Sbinary_iterative(V, 0, arrSz-1, num);

	// if (position == -1){
	// 	std::cout << "Número não encontrado" << std::endl;
	// }else{
	// 	std::cout << "O índice do valor procurado é: " << position << std::endl;
	// }	
	
	//auto position = std::find(V.begin(), V.end(), num);
	auto position = std::binary_search(V.begin(), V.end(), num);
	// if (position != V.end()){
	// 	std::cout << *position << std::endl;
	// }else {
	// 	std::cout << "Valor não encontrado" << std::endl;
	// }
	
	if (position){
		std::cout << "Valor encontrado" << std::endl;
	}else{
		std::cout << "Valor não encontrado" << std::endl;
	}
	
	return 0;
}


int Sternary_recursive (std::vector<int> V, std::size_t l, std::size_t r, int key)
{
	if (l > r)
	{
		return -1;
	}else {
		int t1 = (r-l)/3 + l;
		int t2 = ((r-l)/3)*2 + l;

		if(V[t1] == key){
			return t1;
		}else if (V[t2] == key){
			return t2;
		}else if (V[t1] > key){
			//evitar Falha de segmentação
			if ((t1-1) < 0){
				return -1;
			}else return Sternary_recursive(V, l, t1-1, key);
		}else if (V[t2] > key){
			//evitar falha de segmentação
			if ((t2-1) < 0){
				return -1;
			}else return Sternary_recursive(V, t1+1, t2-1, key);
		}else {
			return Sternary_recursive(V, t2+1, r, key);
		}
	}
}

int Sternary_iterative (std::vector<int> V, std::size_t l, std::size_t r, int key)
{
	auto t1(0);
	auto t2(0);

	while (l <= r)
	{
		t1 = (r-l)/3 + l;
		t2 = ((r-l)/3)*2 + l;

		if(V[t1] == key){
			return t1;
		}else if (V[t2] == key){
			return t2;
		}else if (V[t1] > key){
			//evitar Falha de segmentação
			if ((t1-1) < 0){
				return -1;
			}else r = t1-1;
		}else if (V[t2] > key){
			l = t1+1;
			//evitar falha de segmentação
			if ((t2-1) < 0){
				return -1;
			}else r = t2-1;
		}else {
			l = t2+1;
		}
	}
	return -1;
	
}

int Ssequential_recursive (std::vector<int> V, std::size_t l, std::size_t r, int key)
{
	if (l > r)
	{
		return -1;

	}else if (V[l] == key) {
		return l;
	}else{
		return Ssequential_recursive(V, l+1, r, key);
	}

}

int Ssequential_iterative (std::vector<int> V, std::size_t l, std::size_t r, int key)
{
	for (auto i(l); i <= r; ++i){
		if (V[i] == key) return i;
	}
	return -1;
}

int Sbinary_iterative (std::vector<int> V, std::size_t l, std::size_t r, int key)
{

	auto half(0ul); 
	
	while (l <= r)
	{
		half = (l+r)/2;
		
		if (V[half] == key){
			return half;
		}else if (V[half] > key){
			r = half-1;
		}else if (V[half] < key){
			l = half+1;
		}
	}
	return -1;

}


int Sbinary_recursive (std::vector<int> V, std::size_t l, std::size_t r, int key)
{
	if (l > r)
	{
		return -1;
	}else 
	{
		int half = (l+r)/2;

		if (V[half] == key) {
			return half;
		}else if (V[half] > key){
			return Sbinary_recursive(V, l, half-1, key);
		}else if (V[half] < key){
			return Sbinary_recursive(V, half+1, r, key);
		}
	}
}