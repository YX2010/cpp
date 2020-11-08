#include <iostream>
#include "Picture.h"

const char *init[] = {"Paris", "in the", "Spring"};

int main() {
	
	Picture p(init, 3);
	std::cout << p << std::endl;

	Picture q = frame(p);
	std::cout << q << std::endl;

	Picture r = p | q;
	std::cout << r << std::endl;

	Picture s = q & r;
	std::cout << s << std::endl << frame(s) << std::endl;
}
