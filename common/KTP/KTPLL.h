#pragma once

// KTP Logic Link 

class KTPLL final 
{
public:
	KTPLL();
	~KTPLL();

	bool Parser(const char * rawBuffer, size_t bytes, size_t & begin , size_t & end);
	char* Packet(char * rawBuffer, size_t &size );
	
private:

};