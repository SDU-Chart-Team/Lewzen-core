#ifndef __LZ_UTILS_WARNING__
#define __LZ_UTILS_WARNING__
#include <iostream>

#ifdef debug
#define _LZ_WARNING(text) { std::cout  << "Warning: " << text << std::endl; }
#else
#define _LZ_WARNING(text) {  }
#endif

#endif