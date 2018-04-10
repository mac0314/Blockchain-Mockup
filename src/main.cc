#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

#include "block.h"
#include "blockchain.h"
#include "util/utiltime.h"
#include "mining.h"

#define BLOCK_MAX 10
#define DIFFICULTY 5

using namespace std;

string testData[BLOCK_MAX] = {"Genesis Block"};

Blockchain blockchain;

int main(void){
	ios::sync_with_stdio(false);

	cout << "------------------------" << "\n";
	cout << "Start Blockchain mockup!" << "\n\n";
	

	// Setting test block data
	cout << "\tData" << "\n";
	cout << " - " << testData[0] << "\n";
	for(int i=1; i<BLOCK_MAX; i++){
		testData[i] += "Block #" + boost::lexical_cast<string>(i);
		cout << " - " << testData[i] << "\n";
	}
	
	cout << "\n\n";

	// Mining until block number 10
	for(int i=0; i<BLOCK_MAX; i++){
		
		if(i==0){
			blockchain.push_back(new Block(miningBlock(" ", testData[i], getTime(), DIFFICULTY)));
		}else{
			blockchain.push_back(new Block(miningBlock(blockchain[i-1]->hash, testData[i], getTime(), DIFFICULTY)));
		}

		cout << "Block #" << i+1 << " " << blockchain[i]->hash << " " << testData[i] << " " << getTime() << "\n\n";
	}


	return 0;
}
