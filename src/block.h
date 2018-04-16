
#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <string>

#include <stddef.h>
#include <stdint.h>


class Block {
	public:
		int64_t version;
		std::string preHash;
		std::string hash;
		int64_t nTime;
		int64_t nBits;
		int64_t nNonce;

		Block(int64_t version, std::string preHash, std::string hash, int64_t time, int64_t bits, int64_t nonce);

		~Block();
	private:

};

#endif
