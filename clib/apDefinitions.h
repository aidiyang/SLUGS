/* ==================================================
This is the definition file for the the UCSC AP code
it creates all the common defines, unions, enumerations
and data types.

 Code by: Mariano I. Lizarraga
 First Revision: Aug 18 2008 @ 17:42
 ====================================================*/
#ifndef _APDEFINITIONS_H_
#define _APDEFINITIONS_H_

#ifdef __cplusplus
       extern "C"{
#endif

// =========== Global Definitions ==========

// Circular Buffer Size
// ===================
#ifdef __cplusplus
       #define BSIZE			1024
#else
       #define BSIZE			512
#endif

// GPS Checksum Messages
// =====================
#define GGACS			86
#define RMCCS			75

// GPS Header IDs
// ==============
#define GGAID			1
#define RMCID			2
#define UNKID			254

// GPS Circular Buffers
// ====================
#define MSIZE			127
#define CSIZE			26 //[newBytes payload remaingBytes]  (comms buffer out of readGPS)

// Data Logger Values
// ================
#define LOGSEND					8
#define MAXSEND					103
#define MAXLOGSEND				56

#ifdef __cplusplus
       #define MAXLOGLEN		500
#else
       #define MAXLOGLEN		99
#endif

#define LOGRAW100	1



// Message Protocol Lengths and IDs
// ================================

// SENSOR MCU
// ==========
#define GPS_START 		0
#define GPSMSG_ID		1
#define GPSMSG_LEN		27 

#define LOAD_START		27
#define LOADMSG_ID		2
#define LOADMSG_LEN		4

#define RAW_START 		31
#define RAWMSG_ID		3
#define RAWMSG_LEN		18

#define ATT_START		49
#define ATTMSG_ID		4
#define ATTMSG_LEN		26

#define XYZ_START		75
#define XYZMSG_ID		11
#define XYZMSG_LEN		24

#define DYN_START		99
#define DYNMSG_ID		5
#define DYNMSG_LEN		10

#define BIA_START		109
#define BIAMSG_ID		6
#define BIAMSG_LEN		24

#define DIA_START		133
#define DIAMSG_ID		7
#define DIAMSG_LEN		18

#define HIL_START		151

#define PIL_START		152
#define PILMSG_ID		9
#define PILMSG_LEN		10



// CONTROL MCU
// ===========
#define AKNMSG_ID		105
#define AKNMSG_LEN		6

#define PWMMSG_ID		100
#define PWMMSG_LEN		20 

#define CALMSG_ID		102
#define CALMSG_LEN		14


// GROUND STATION
// ==============
// NOTE: for HIL simulator the GS uses the same IDs for the 
// simulated sensor readings, i.e. GPS, Raw, Air Data, etc. Than
// for the actual readings.

#define FILMSG_ID		205
#define FILMSG_LEN		1

#define PIDMSG_ID		202
#define PIDMSG_LEN		13

#define QUEMSG_ID		204
#define QUEMSG_LEN		10


// Communication Protocol Merging Offsets
// ======================================
#define GSMSG_IDX		99
#define AKMSG_IDX		202


// Standard characters used in the parsing of messages
// ===================================================
#define DOLLAR			36
#define STAR			42
#define CR				13
#define LF				10
#define AT				64

// Interprocessor Communication
// ============================
#define BEGINSPI		0xFFFF
#define ENDSPI			0xBEEF
#define SPIBUFSIZE		46

// Standard Units
// ==============
#define KTS2MPS 		0.514444444
#define PI              3.141592653589793
#define DEG2RAD			0.017453292519943
#define RAD2DEG			57.29577951308232

// Periphereal Configurations
// ==========================
#define APFCY			40000000

	
#define GPSBAUDF		19200
#define GPSBAUDI		4800
#define UCSCAP_UBRGF 	129
#define UCSCAP_UBRGI 	520

#define LOGBAUD			115200
#define LOG_UBRG		21

#define LOGMAT_BAUD		57600
#define LOGOMAT_UBRG	42


// ifdef switches for debugging and conditional inclusion
// ======================================================
#define __IN_DSPIC__ 	1 // switch for use in PC

#if __IN_DSPIC__
	#ifdef DEBUG
		#undef DEBUG
	#endif	
#else
	#define DEBUG 1
#endif


// ============= Unions Used for Data Transmission ====
//Type definitions for standard unions used in sending
// and receiving data
typedef union{
	unsigned char    chData[2];
	unsigned short   usData;
} tUnsignedShortToChar; 

typedef union{
	unsigned char    chData[2];
 	short   		 shData;
} tShortToChar; 

typedef union{
	unsigned char   chData[4];
 	unsigned int   	uiData;
} tUnsignedIntToChar; 

typedef union{
	unsigned char   chData[4];
 	int   			inData;
} tIntToChar; 

typedef union{
	unsigned char   chData[4];
	unsigned short	shData[2];
 	float   		flData;
} tFloatToChar; 

// ============= Structures used for data ============
typedef struct tGpsData{
	unsigned char	 		year;
	unsigned char			month;
	unsigned char			day;
	unsigned char			hour;
	unsigned char			min;
	unsigned char			sec;	 
	tFloatToChar 			lat;
	tFloatToChar 			lon;
	tFloatToChar 			height;
	tUnsignedShortToChar	cog;
	tUnsignedShortToChar	sog;
	tUnsignedShortToChar	hdop;	
	unsigned char			fix;
	unsigned char 			sats;	
	unsigned char			newValue;
}tGpsData;

typedef struct tRawData{
	tUnsignedShortToChar 	gyroX;
	tUnsignedShortToChar 	gyroY;
	tUnsignedShortToChar 	gyroZ;
	tUnsignedShortToChar 	accelX;
	tUnsignedShortToChar 	accelY;
	tUnsignedShortToChar 	accelZ;
	tUnsignedShortToChar 	magX;
	tUnsignedShortToChar 	magY;
	tUnsignedShortToChar 	magZ;
}tRawData;

typedef struct tAttitudeData{
	tFloatToChar			roll;
	tFloatToChar			pitch;
	tFloatToChar			yaw;
	tFloatToChar			p;
	tFloatToChar			q;
	tFloatToChar			r;
	tUnsignedShortToChar	timeStamp;
}tAttitudeData;

typedef struct tSensStatus{
	char					load;
	char					vdetect;
	tUnsignedShortToChar	bVolt;
}tSensStatus;

typedef struct tDynTempData{
	tFloatToChar	dynamic;
	tFloatToChar	stat;
	tShortToChar	temp;
}tDynTempData;

typedef struct tBiasData{
	tFloatToChar			axb;
	tFloatToChar			ayb;
	tFloatToChar			azb;
	tFloatToChar			gxb;
	tFloatToChar			gyb;
	tFloatToChar			gzb;	
}tBiasData;

typedef struct tDiagData{
	tFloatToChar			fl1;
	tFloatToChar			fl2;
	tFloatToChar			fl3;
	tShortToChar			sh1;
	tShortToChar			sh2;
	tShortToChar			sh3;	
}tDiagData;

typedef struct tXYZData{
	tFloatToChar	Xcoord;
	tFloatToChar	Ycoord;
	tFloatToChar	Zcoord;	
	tFloatToChar	VX;
	tFloatToChar	VY;
	tFloatToChar	VZ;	
}tXYZData;

typedef struct tAknData{
	unsigned char 	WP;
	unsigned char 	csCal;
	unsigned char 	pidCal;
	unsigned char 	csLimits;
	unsigned char 	filOnOff;	
	unsigned char	reboot;
}tAknData;

typedef struct tPilotData{
	tUnsignedShortToChar	dt ;
	tUnsignedShortToChar	dla;
	tUnsignedShortToChar	dra;
	tUnsignedShortToChar	dr ; 
	tUnsignedShortToChar	de ; 
}tPilotData;

typedef struct tPWMData{
	tUnsignedShortToChar	dt_c;
	tUnsignedShortToChar	dla_c;
	tUnsignedShortToChar	dra_c;
	tUnsignedShortToChar	dr_c; 
	tUnsignedShortToChar	dle_c; 
	tUnsignedShortToChar	dre_c; 
	tUnsignedShortToChar	dlf_c; 
	tUnsignedShortToChar	drf_c; 
	tUnsignedShortToChar	da1_c; 
	tUnsignedShortToChar	da2_c; 
}tPWMData;

typedef struct tPIDData{
	tFloatToChar 	P[10];
	tFloatToChar 	I[10];
	tFloatToChar 	D[10];	
}tPIDData;


typedef struct tQueryData{
	unsigned char 	pendingRequest;
	unsigned char 	idReq;
	unsigned char 	indxReq;
}tQueryData;


#ifdef __cplusplus
      }
#endif

#endif /* _APDEFINITIONS_H_ */
