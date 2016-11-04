#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FSM.h"






struct fsm			//struct the main uses to interact with the fsm
{
    cellType const *fsmMat;
    eventType currentEvent;
    eventType previousEvent;
    stateType currentState;
    eventType prevEventCopy;
    int esCount;
    int evCount;
};



int cicleFsm(fsmDataType fsm, void *userData)		//update fsm
{
    if((*(fsm->fsmMat + (fsm->currentState) * fsm->evCount + (fsm->currentEvent) )).nextState != noState)
	{
		(*(fsm->fsmMat + (fsm->currentState) * fsm->evCount + (fsm->currentEvent) )).action(userData);
		fsm->currentState = (*(fsm->fsmMat + (fsm->currentState) * fsm->evCount + (fsm->currentEvent) )).nextState;
		return 1;
	}
    return 0;
}

fsmDataType  createClientFsm( cellType const *sourceMat,stateType firstState,int stateCount,int eventCount)
{
    fsmDataType fsm =(fsmDataType)malloc(sizeof(struct fsm));
    if(fsm!=NULL)
    {   
        const cellType *mat=(cellType * )malloc(sizeof(cellType [stateCount][eventCount]));//space for fsm table
        if(mat!=NULL ) 
        {

            memcpy((void *)mat,sourceMat,sizeof(cellType [stateCount][eventCount]));//copy the fsm table
            fsm->currentEvent = noEvent;			//initial event
            fsm->previousEvent = noEvent;
            fsm->currentState = firstState;
            fsm->fsmMat=mat;
            fsm->esCount=stateCount;
            fsm->evCount=eventCount;
        }
        else { free(fsm);  fsm=NULL; }
    }
    return fsm;
}

void destroyClientFsm(fsmDataType fsm)
{
    if(fsm!=NULL)
    {    
        if(fsm->fsmMat!=NULL)
        {    
            free(fsm->fsmMat);
            free(fsm);
            fsm=NULL;
        }
    }
}

eventType getCurrentEvent(fsmDataType fsm)
{
    if(fsm != NULL)
        return fsm->currentEvent;
    else
        return noEvent;
}
eventType getPreviousEvent(fsmDataType fsm)
{
    if(fsm != NULL)
        return fsm->previousEvent;
    else
        return noEvent;
}
stateType getCurrentState(fsmDataType fsm)
{
    if(fsm != NULL)
        return fsm->currentState;
    else
        return noState;
    
}
int event(fsmDataType fsm,eventType ev)
{
    int retVal=-1; 
    if(fsm!=NULL && (ev < fsm->evCount || ev== noEvent))
    {
        fsm->previousEvent=fsm->currentEvent;
        fsm->currentEvent=ev;
        retVal=0;
    }
    return retVal;
}



