#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_

	#include "includes.h"

	void Fill (std::vector<unsigned long long> &V, const std::size_t arrSz);
	bool SsequentialIt(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key);
	bool SsequentialRec(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key);
	bool SbinaryIt(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key);
	bool SbinaryRec(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key);
	bool STernaryIt(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key);
	bool STernaryRec(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key);
	bool Sfind(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key);
	bool Sbinary(const std::vector<unsigned long long> &V, std::size_t l, std::size_t r, unsigned long long key);


#endif
