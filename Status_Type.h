#pragma pack(push,1)

typedef	UINT16	STATUS_TYPE;

#pragma pack()

#define	STATUS_SUCCESS			0x00
#define	STATUS_ERROR			BIT(8*sizeof(STATUS_TYPE)-1)
#define	STATUS_ERROR_MEMERROR	(STATUS_ERROR | BIT(0))

