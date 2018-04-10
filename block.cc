
#include "block.h"
#include "crypto/sha256.h"

#include <atomic>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>


Block::Block(std::string data, std::string preHash){
	this->hash = sha256(data);
	this->preHash = preHash;
	this->setTime();
}

Block::~Block(){
	
}

void Block::setTime(){
	this->timestamp = (boost::posix_time::microsec_clock::universal_time() -
                   boost::posix_time::ptime(boost::gregorian::date(1970,1,1))).total_milliseconds();
}
