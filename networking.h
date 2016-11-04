#ifndef NETWORKING_H
#define NETWORKING_H

class Networking
{
	public:
		Networking(char * ip, int port);
		bool initOK();
		bool SendDataPacket();
		bool RecieveDataPacket();
};

#endif 