
#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <string>

#include <stddef.h>
#include <stdint.h>


class Block {
	public:
		std::string hash;

		Block(std::string hash);

		~Block();
	private:
		size_t _size;
		bool _owned;
};

#endif
