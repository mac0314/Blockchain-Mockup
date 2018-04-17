
#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <iostream>
#include <string>
#include <cstring>

#include <stddef.h>
#include <stdint.h>

#include <nlohmann/json.hpp>

class Block {
	public:
		int32_t version;
		std::string preHash;
		std::string hash;
		int64_t nTime;
		uint32_t nBits;
		uint32_t nNonce;

		uint32_t nIndex;

		Block(int32_t version, std::string preHash, std::string hash, int64_t nTime, uint32_t nBits, uint32_t nNonce);

		~Block();

		std::string toString();
	private:
};

#endif


//nlohmann::json getJson(std::string toddle);
