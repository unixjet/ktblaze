#include "KTPLL.h"
#include <iostream>

KTPLL::KTPLL()
{

}

KTPLL::~KTPLL()
{

}

/// [begin, end)
bool KTPLL::Parser(const char * rawbuffer, size_t bytes, size_t & begin, size_t & end)
{
	for (size_t i = 0; i < bytes; ++i)
		std::cout.put(rawbuffer[i]);
	return false;
}

char * KTPLL::Packet(char * buffer, size_t & size)
{
	return 0;
}



