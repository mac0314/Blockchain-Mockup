
#include "block.h"


Block::Block(int32_t version, std::string preHash, std::string hash, int64_t nTime, uint32_t nBits, uint32_t nNonce){
	this->version = version;
	this->preHash = preHash;
	this->hash = hash;
	this->nTime = nTime;
	this->nBits = nBits;
	this->nNonce = nNonce;
}

Block::~Block(){

}

std::string Block::toString(){
	char msg[1024];

	std::sprintf(msg, "{\"version\": %d, \"preHash\": \"%s\", \"hash\": \"%s\", \"nTime\": %lld, \"nBits\": %d, \"nNonce\": %d}", this->version, this->preHash.c_str(), this->hash.c_str(), this->nTime, this->nBits, this->nNonce);

	//std::cout << msg << "\n";

	return msg;
}
