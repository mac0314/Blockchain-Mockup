
#include <iostream>

#include "mining.h"
#include "hash.h"


Block* miningBlock(std::string preHash, std::string data, int64_t timestamp, int64_t difficulty){
	Block* newBlock;
	std::string* target = new std::string(difficulty, '0');
	std::string hash;
	int64_t version = 1;
	int64_t nNonce = 0;

	std::cout << "Mining... Target : " << *target << "\n";

	while(true){
		hash = calcHash(preHash, data, timestamp, nNonce++);
		if(hash.substr(0, difficulty) == *target){
			break;
		}
	}

	newBlock = new Block(version, preHash, hash, timestamp, difficulty, nNonce);

	std::cout << "Mining Block : " << hash << "\n";

	return newBlock;
}
