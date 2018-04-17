
#include "utiltime.h"


int64_t getTime(){
	int64_t now = (boost::posix_time::microsec_clock::universal_time() -
                   boost::posix_time::ptime(boost::gregorian::date(1970,1,1))).total_milliseconds();
	assert(now > 0);
	return now;
}
