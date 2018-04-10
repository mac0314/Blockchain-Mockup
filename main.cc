#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

#include "block.h"
#include "utiltime.h"
#include "mining.h"

#define BLOCK_MAX 10

using namespace std;

string testData[BLOCK_MAX] = {"Genesis Block"};

Block* b[BLOCK_MAX];

int main(void){
	ios::sync_with_stdio(false);

	cout << "------------------------" << "\n";
	cout << "Start Blockchain mockup!" << "\n\n";
	

	// Setting test block data
	cout << "Data" << "\n";
	cout << testData[0] << "\n";
	for(int i=1; i<BLOCK_MAX; i++){
		testData[i] += "Block #" + boost::lexical_cast<string>(i);
		cout << testData[i] << "\n";
	}
	
	cout << "\n\n";

	for(int i=0; i<BLOCK_MAX; i++){
		
		if(i==0){
			b[i] = new Block(miningBlock(" ", testData[i], getTime(), 5));
		}else{
			b[i] = new Block(miningBlock(b[i-1]->hash, testData[i], getTime(), 5));
		}

		cout << "Block #" << i+1 << " " << b[i]->hash << " " << testData[i] << " " << getTime() << "\n\n";
	}


	return 0;
}
