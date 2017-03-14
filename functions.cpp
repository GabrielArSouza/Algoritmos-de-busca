#include "functions.h"


void Fill (std::vector<unsigned long long> &V, const std::size_t arrSz)
{
	auto j(0ull);
	for (auto i(0ull); i < arrSz; ++i)
	{
		V[i] = j;
		j++;
	}
	
}

bool SsequentialIt(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key)
{
	for (auto i(l); i <= r; ++i){
		if (V[i] == key) return true;
	}
	return false;

}

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

bool Sfind(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key)
{
	auto result = std::find(V.begin()+l, V.begin()+r+1, key);
	if (result != (V.begin()+r+1))
		return true;
	else return false;
}

bool Sbinary(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key)
{
	return std::binary_search(V.begin()+l, V.begin()+r+1, key);
}

