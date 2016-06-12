#include <iostream>
#include <fstream>
#include "bmp.h"
#include "import.h"
#include "util.h"

using namespace std;

int main(int argc, char *argv[])
{	
	bmp bitmap;

	if (argc < 2) {
		throw_error("No image file specified.");
		return -1;
	}

	bitmap.f_path = argv[1];

	if (import(&bitmap) != 0) {
		throw_error("Error opening file");
		return -1;
	}
	
	return 0;
}
