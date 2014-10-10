#ifndef EPA_H
#define EPA_H

/*
 * epaMote Header
 */
struct epa_hdr {
  unsigned char ptype; /* Packet type */
  unsigned short id;   /* Node ID. 0=broadcast */
  unsigned long ts;    /* Timestamp, seconds since epoch */
};  

/*
 * Packet Types
 */
#define PT_BOOT 0xB0 /* Boot Request */
#define PT_ID   0x1D /* ID Assignment */
#define PT_DATA 0xDA /* Sensor Data */
#define PT_EPI  0xED /* Epidemic Mode */
#define PT_ONL  0xA0 /* Online Mode */
#define PT_UPD  0x5D /* Software Update */

/*
 * Packet type payloads, max 25 octets
 */
struct PL_boot {
  unsigned char node_type; /* See node types below */
  long a;                  /* Node data range or other parameters */
  long b;                  /*   such as display resolution */
  long c;
};

struct PL_id {
  unsigned short id;
};

struct PL_data {
  double value; /* data value */
  double error; /* error */
};

struct PL_epi {
  unsigned long interval; /* wakeup interval in seconds */
};

struct PL_onl {
  unsigned short timeout; /* Transision to epidemic after this many
			     seconds of inactivity */
};

struct PL_upd {
  unsigned char[25] block; /* Block of code */
};


/*
 * Node Types
 */

/* System nodes */
#define NT_PLAIN  0x00 /* Plain node, no sensors */
#define NT_SRV    0x01 /* Server, collets data from sensor nodes */

/* Display nodes */
#define NT_BLCD   0x10 /* Basic text LCD, 16x2 */
#define NT_TLCD   0x11 /* Text LCD of any type, size a=cols, b=rows */
#define NT_GLCD   0x12 /* Graphics LCD, a=width, b=height, c=color depth */

/* Temperature sensor nodes */
#define NT_TEMP   0x20 /* Plain temperature sensor,
			  a=low, b=high, c=precision */

/* Light sensor nodes */
#define NT_LIGHT  0x30 /* Visible light sensor */
#define NT_IR     0x31 /* Infrared light sensor */
#define NT_UV     0x32 /* Ultraviolet light sensor */

/* Humidity */
#define NT_AH     0x40 /* Air Humidity */
#define NT_SH     0x41 /* Soil Humidity */
#define NT_RAIN   0x42 /* Rain sensor (esp. rain type 17) */

#endif
