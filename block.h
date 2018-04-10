
#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <string>

#include <stddef.h>
#include <stdint.h>


class Block {
	public:
		std::string hash;
		std::string preHash;

		Block(std::string hash, std::string preHash);

		
		~Block();

		void setTime();

		int64_t getTime() const {
			return timestamp;
		};
	private:
		int64_t timestamp;
		int64_t nonce;
		
};

#endif
