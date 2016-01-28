#pragma once

enum Business :char
{
	ADAPTER = 1,
};

//enum Class : char
//{
//	HEARTBEAT = 0x04,
//};

enum OpcodeFlag :char
{
	DIRECTION = 0x80,
	ACK = 0x40,
	FILENAME = 0x20
};

enum Operation : char
{
	NONE = 0x00,
	NEW  = 0x01,
    DELETE = 0x02,
	READ = 0x03,
	WRITE = 0x04,
	NOTIFY = 0x05,
	UNDEFINED = 0x06,
};

class PacketObject
{
public:
	PacketObject();
	~PacketObject();

	virtual Parser(const char * rawbuffer, size_t bytes);
protected:

	Business business_;

	
};