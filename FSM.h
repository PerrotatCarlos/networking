#ifndef FSM_H
#define FSM_H
#define noEvent 666
#define noState 512



typedef unsigned int stateType;
typedef unsigned int eventType;

typedef struct fsm *fsmDataType;
typedef struct cell 
{
    stateType nextState;
    void (*action)(void *);
}cellType;


fsmDataType  createClientFsm( cellType const *sourceMat,stateType firstState,int stateCount,int eventCount);/* creates a FSM
(always call the destroy function after)*/

int cicleFsm(fsmDataType fsm, void *userData);
eventType getCurrentEvent(fsmDataType fsm);//gives the current event of the fsm (noEvent if its unable to retrieve it)
eventType getPreviousEvent(fsmDataType fsm);//gives the previous event of the fsm (noEvent if its unable to retrieve it)
stateType getCurrentState(fsmDataType fsm);//gives the current state of the fsm (noState if its unable to retrieve it)
int event(fsmDataType fsm,eventType ev);//recives a new event
void destroyClientFsm(fsmDataType fsm);







#endif /* FSM_H */

