#include "import.h"
#include "util.h"
#include "bmp.h"
#include <fstream>
#include <iostream>

using namespace std;

int import(bmp *bmp)
{	
	ifstream file;
	streampos f_size;

	file.open(bmp->f_path, ios::binary|ios::ate);
	if (!file.is_open()) {
		return -1;
	}
	f_size = file.tellg();
	file.seekg(0, ios::beg);

	//Read and parse
	file.read((char*)&(bmp->header.id), sizeof(bmp->header.id));
	file.read((char*)&(bmp->header.size), sizeof(bmp->header.size));
	file.read((char*)&(bmp->header.reserved1), sizeof(bmp->header.reserved1));
	file.read((char*)&(bmp->header.reserved2), sizeof(bmp->header.reserved2));
	file.read((char*)&(bmp->header.offset_to_pxl_array), sizeof(bmp->header.offset_to_pxl_array));

	file.close();
	return 0;
}
