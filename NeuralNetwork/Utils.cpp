#include "Utils.h"

using namespace std;

double RandFloat() {
	return (rand()) / (RAND_MAX + 1.0);
}

double RandomClamped() {
	return RandFloat() - RandFloat();
}