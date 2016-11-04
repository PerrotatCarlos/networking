#ifndef USERDATA_H
#define USERDATA_H
typedef enum{NETWORK,KEYBOARD} UserDataEvIdentifier;

class UserData
{
	public:
		char fileName[256];
		NetworkEG networkEG;
		KeyboardEG keyboardEG;
		FILE * file; //VER EN C++ FLUJOS ARCHIVOS
		Networking networking;
		UserDataEvIdentifier whichEvent;
	private:
		

};
#endif // !USERDATA_H
