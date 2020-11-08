#ifndef _PICTURE_H
#define _PICTURE_H

#include <iostream>

class Picture {

	friend std::ostream& operator<<(std::ostream&, const Picture&);
	friend Picture frame(const Picture& );
	friend Picture operator&(const Picture&, const Picture&);
	friend Picture operator|(const Picture&, const Picture&);
public:
	Picture() : height(0), width(0), data(nullptr) {};
	Picture(const char* const *, int);
	Picture(const Picture&);
	~Picture();

	Picture& operator=(const Picture&);

private:
	int height, width;
	char *data;
	
	// 直接读写给定字符的左值
	char& position(int row, int col) {
		return data[row * width + col];
	}

	// 返回一个副本
	char position(int row, int col) const {
		return data[row * width + col];
	}
	void init(int h, int w);
	static int max(int, int);
	void copyblock(int, int, const Picture&);
	void clear(int, int, int, int);


};

std::ostream& operator<<(std::ostream& os, const Picture&);

Picture frame(const Picture& );
Picture operator&(const Picture&, const Picture&);
Picture operator|(const Picture&, const Picture&);

#endif
