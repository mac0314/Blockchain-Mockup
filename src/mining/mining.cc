
#include <iostream>

#include "mining.h"


Block* miningBlock(std::string preHash, std::string data, int64_t timestamp, uint32_t difficulty){
	Block* newBlock;
	std::string* target = new std::string(difficulty, '0');
	std::string hash;
	int32_t version = 1;
	uint32_t nNonce = 0;

	//std::cout << "Target : " << *target  << "\n";
	std::cout << "Mining...\n";

	while(true){
		hash = calcHash(preHash, data, timestamp, nNonce);
		if(hash.substr(0, difficulty) == *target){
			break;
		}
		nNonce++;
	}

	newBlock = new Block(version, preHash, hash, timestamp, difficulty, nNonce);

	std::cout << "Mining Block, hash : " << hash << "\n";

	return newBlock;
}
