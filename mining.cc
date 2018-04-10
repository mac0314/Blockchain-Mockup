
#include <iostream>

#include "mining.h"
#include "hash.h"

std::string miningBlock(std::string preHash, std::string data, int64_t timestamp, int64_t difficulty){
	std::string* target = new std::string(difficulty, '0');
	std::string hash;
	int64_t nonce = 0;

	std::cout << "target : " << *target << "\n";

	while(true){
		hash = calcHash(preHash, data, timestamp, nonce++);
		if(hash.substr(0, difficulty) == *target){
			break;
		}
	}

	std::cout << "Mining Block : " << hash << "\n";

	return hash;
}
