#include <iostream>

#include "TestExtins.h"
#include "TestScurt.h"
using namespace std;


int main() {
	testAll();
	testAllExtins();
	cout<<"End";
}

/*
*
i        0        1        2        3
info   (10,1)   (5,1)   (20,1)   (7,1)
st       1       -1       -1      -1
dr       2        3       -1      -1
 *
 */
