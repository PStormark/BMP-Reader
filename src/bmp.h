#ifndef BMP_H
#define BMP_H

struct bmp_header {
	char16_t id;
	int size;
	char16_t reserved1;
	char16_t reserved2;
	int offset_to_pxl_array;
};

class bmp {
	public: 
		char *f_path;
		bmp_header header;	
};

#endif
