#define	MAX_FIFO_NAME	32

#define	SERV_FIFO	"./.fifo"

//message type
typedef struct  {
	//Name of FIFO for return
	char	returnFifo[MAX_FIFO_NAME];
	//Buffer to store data
	char	data[128];
}
MsgType;
