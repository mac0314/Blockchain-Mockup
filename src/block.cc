
#include "block.h"

#include <string>


Block::Block(int64_t version, std::string preHash, std::string hash, int64_t nTime, int64_t nBits, int64_t nNonce){
	this->version = version;
	this->preHash = preHash;
	this->hash = hash;
	this->nTime = nTime;
	this->nBits = nBits;
	this->nNonce = nNonce;
}

Block::~Block(){

}
