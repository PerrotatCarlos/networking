
bool hayEvento(UserData &data);

int main(void)
{
	//ip hardcodeada, al final ponemos parsecmdline
	initAll();
	UserData myData;
	Client myClient;
	bool quit;
	while (quit != false)
	{
		if (hayEvento(myData))
			myData.ev=getEvento(myData)
		if (myData.ev == QUIT)
			quit = true;
		else if (myData.ev == SHOWHELP)
			showhelp();
		else
			myClient.handleEvent(myData);
	}
	destroyAll();
}

bool hayEvento(UserData &data)
{
	//Pregunto hay evento de network
	//Pregunto hay evento de keyboard
	//Guardo en userData que evento hubo en una variable
}
eventT getEvento(UserData &data)
{
	//me fijo cual fue, obtengo el evento que sea. Si es de teclado tmb obtengo el nombre del file en string para mandar
}