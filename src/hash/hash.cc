
#include "hash.h"

std::string calcHash(std::string preHash, std::string data, int64_t timestamp, uint32_t nonce){
	std::string text = preHash + boost::lexical_cast<std::string>(timestamp) + boost::lexical_cast<std::string>(nonce);
	std::string hash = sha256(text);

	return hash;
}
