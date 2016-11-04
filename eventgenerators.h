#ifndef EVENTGENERATORS_H
#define EVENTGENERATORS_H

typedef enum{ WRQ, RRQ, ACK, LAST_ACK, DATA, LAST_DATA, TIMEOUT, ERROR, NO_EVENT } eventT;

class EventGenerator
{
	public:
		virtual bool hayEvento()=0;
		virtual eventT getEvent()=0;

};

class KeyboardEG :public EventGenerator
{
	public:
		bool hayEvento();
		eventT getEvent();
		string getFileName();

	private:
		char buffer[255];
		eventT cmpStr4Event();
		bool flagStrRecieved;
};
class NetworkEG :public EventGenerator
{
	public:
		bool hayEvento();
		eventT getEvent();
	private:
		//apr pool
		//apr socket
		//timer para timeout
};


#endif // !EVENTGENERATORS_H
