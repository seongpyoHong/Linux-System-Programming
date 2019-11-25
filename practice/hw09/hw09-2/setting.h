#define MY_ID 				46
#define SHM_KEY  			(0x9000 + MY_ID)
#define SEM_KEY				(0x8000 + MY_ID)
#define SHM_MODE 			(SHM_R | SHM_W | IPC_CREAT)
#define SHM_SIZE			sizeof(int)

