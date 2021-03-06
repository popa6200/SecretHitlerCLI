#pragma once

#include <WinSock2.h>

enum class Policy
{
	Fascist,
	Liberal,
};

struct PlayerData
{
	char len;
	char name[30];
	char chair;
};

struct ClientData
{
	bool isFascist;
	bool isHitler;
};

union Endpoint
{
	struct
	{
		unsigned int address;
		unsigned short port;
	};
	unsigned long combo;
};

struct Client
{
	Endpoint endpoint;
	ClientData data;
	PlayerData pData;
	bool alive = true;
	bool ready = false;

	sockaddr_in addr();
};
