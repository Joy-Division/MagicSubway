#ifndef INCLUDED_FMT_DATA_H
#define INCLUDED_FMT_DATA_H

#include "cmtypes.h"

/*---------------------------------------------------------------------------*
 * DPK Format Defines
 *---------------------------------------------------------------------------*/
#define DPK_FORMAT_ID   'DIRF' // Magic Number
#define DPK_BLOCK_SIZE  0x800  // CDROM Sector

/* ------------------------------ */
/* Little Endian MSB : 0b11100000 */
/*    Big Endian MSB : 0b10100000 */
/* ------------------------------ */
#if (CM_BYTE_ORDER == CM_BIG_ENDIAN)
#  define DPK_ATTR_LE  0x000000E0 // swapped
#  define DPK_ATTR_BE  0xA0000000
#elif (CM_BYTE_ORDER == CM_LIL_ENDIAN)
#  define DPK_ATTR_LE  0xE0000000
#  define DPK_ATTR_BE  0x000000A0 // swapped
#endif

#pragma pack(push, 1)
typedef struct tDPK_HEADER {
	u_int32 format_id;  // = DPK_FORMAT_ID
	u_int32 attribute;
	u_int32 block_size; // = DPK_BLOCK_SIZE
	u_int32 entry_num;
	u_int32 entry_end;
	u_int32 entry_size; // sizeof(DPK_ENTRY)
	byte    pad[8];
} DPK_HEADER;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct tDPK_ENTRY {
	char    name[12];
	u_int32 offset;
	u_int32 length;
	u_int32 checksum;
} DPK_ENTRY;
#pragma pack(pop)

/*---------------------------------------------------------------------------*
 * PAC Format Defines
 *---------------------------------------------------------------------------*/

//
// PLACEHOLDER
//

#endif /* END OF FILE */
