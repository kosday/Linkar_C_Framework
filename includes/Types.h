/*
	File: Types.h
	Header file.
*/
#include <stdint.h>

//Operation codes for LkExecuteDirectOperation and LkExecutePersistentOperation functions of Linkar Library
#define OP_CODE_LOGIN 1
#define OP_CODE_READ 2
#define OP_CODE_UPDATE 3
#define OP_CODE_NEW 4
#define OP_CODE_DELETE 5
#define OP_CODE_CONVERSION 6
#define OP_CODE_FORMAT 7
#define OP_CODE_LOGOUT 8
#define OP_CODE_GETVERSION 9
#define OP_CODE_SELECT 10
#define OP_CODE_SUBROUTINE 11
#define OP_CODE_EXECUTE 12
#define OP_CODE_DICTIONARIES 13
#define OP_CODE_LKSCHEMAS 14
#define OP_CODE_LKPROPERTIES 15
#define OP_CODE_GETTABLE 16
#define OP_CODE_RESETCOMMONBLOCKS 17
#define OP_CODE_COMMAND_XML 150
#define OP_CODE_COMMAND_JSON 151

#ifndef BOOLTYPEDEFINED
#define BOOLTYPEDEFINED 1
	typedef uint8_t BOOL;
	#define TRUE 1
	#define FALSE 0
#endif

/*
	typedef: CONVERSION_TYPE
	The conversion type for LkConversion functions.
	
		--- Code
		typedef char CONVERSION_TYPE;
		---

	There are 2 possible options:
	
		ICONV - Perform ICONV type conversions. 
		OCONV - Perform OCONV type conversions. 
	
	Defined constants of RowHeadersTYPE::
		Used to define the options ICONV and OCONV.
	
		--- Code
		#define CONVERSION_TYPE_ICONV 'I'
		#define CONVERSION_TYPE_OCONV 'O'
		---
*/
typedef char CONVERSION_TYPE;
#define CONVERSION_TYPE_ICONV 'I'
#define CONVERSION_TYPE_OCONV 'O'

/*
	typedef: DataFormatTYPE
	Indicates in what format you want to receive the data resulting from the operation.
	For some operations, also the format in you want to send the data.
	There are 3 possible options: MV, XML and JSON.
	
		--- Code
		typedef uint8_t DataFormatTYPE;	
		---
		
	Defined constants of DataFormatTYPE::
		Used to define the options MV, XML and JSON.
	
		--- Code
		#define DataFormatTYPE_MV 0x01
		#define DataFormatTYPE_XML 0x02
		#define DataFormatTYPE_JSON 0x03
		---	
*/	
typedef uint8_t DataFormatTYPE;
#define DataFormatTYPE_MV 0x01
#define DataFormatTYPE_XML 0x02
#define DataFormatTYPE_JSON 0x03

/*
	typedef: DataFormatSchTYPE
	Specify the output formats of LkSchemas and LkProperties operations(For other operations, see <DataFormatTYPE> )
	Used only by LkSchemas and LkProperties functions.
	There are 4 possible options: MV, XML, JSON and TABLE.
		--- Code
		typedef uint8_t DataFormatSchTYPE;
		---
		
	Defined constants of DataFormatSchTYPE:
		Used to define the options MV, XML, JSON and TABLE.
	
		--- Code
		#define DataFormatSchTYPE_MV 0x01
		#define DataFormatSchTYPE_XML 0x02
		#define DataFormatSchTYPE_JSON 0x03
		#define DataFormatSchTYPE_TABLE 0x04
		---			
*/
typedef uint8_t DataFormatSchTYPE;
#define DataFormatSchTYPE_MV 0x01
#define DataFormatSchTYPE_XML 0x02
#define DataFormatSchTYPE_JSON 0x03
#define DataFormatSchTYPE_TABLE 0x04

/*
	typedef: DataFormatCruTYPE
	Specify the output formats of Read, Update, New and Select operations(For other operations, see <DataFormatTYPE> )
	Used only by LkRead, LkUpdate, LkNew and LkSelect
	There are 7 possible options: MV, XML, XML_DICT, XML_SCH, JSON, JSON_DICT and JSON_SCH.
		--- Code
		typedef uint8_t DataFormatCruTYPE;
		---
		
	Defined constants of DataFormatCruTYPE:
		Used to define the options MV, XML, XML_DICT, XML_SCH, JSON, JSON_DICT and JSON_SCH.
	
		--- Code
			#define DataFormatCruTYPE_MV 0x01
			#define DataFormatCruTYPE_XML 0x02
			#define DataFormatCruTYPE_JSON 0x03
			#define DataFormatCruTYPE_XML_DICT 0x05
			#define DataFormatCruTYPE_XML_SCH 0x06
			#define DataFormatCruTYPE_JSON_DICT 0x07
			#define DataFormatCruTYPE_JSON_SCH 0x08
		---			
*/
typedef uint8_t DataFormatCruTYPE;
#define DataFormatCruTYPE_MV 0x01
#define DataFormatCruTYPE_XML 0x02
#define DataFormatCruTYPE_JSON 0x03
#define DataFormatCruTYPE_XML_DICT 0x05
#define DataFormatCruTYPE_XML_SCH 0x06
#define DataFormatCruTYPE_JSON_DICT 0x07
#define DataFormatCruTYPE_JSON_SCH 0x08

/*
	typedef: EnvelopeFormatTYPE
	Indicates in what format you want to send the command for LkSendCommnad operation.
	There are 2 possible options: XML and JSON.
	
		--- Code
		typedef uint8_t EnvelopeFormatTYPE;	
		---
		
	Defined constants of EnvelopeFormatTYPE::
		Used to define the options XML and JSON.
	
		--- Code
		#define EnvelopeFormatTYPE_XML 0x02
		#define EnvelopeFormatTYPE_JSON 0x03
		---	
*/	
typedef uint8_t EnvelopeFormatTYPE;
#define EnvelopeFormatTYPE_XML 0x02
#define EnvelopeFormatTYPE_JSON 0x03

/*
	typedef: RowHeadersTYPE
	Indicates options to include headers in the first row or not.
	Used only by LkSchmasOptions, LkPropertiesOptions and TableOptions.
	There are 3 possible options:
	
		MAINLABEL - Main headings
		SHORTLABEL - Short label headings
		NONE - Without headings
		
		--- Code
		typedef uint8_t RowHeadersTYPE;
		---
		
	Defined constants of RowHeadersTYPE:
		Used to define the options MAINLABEL, SHORTLABEL and NONE.
	
		--- Code
		#define RowHeadersTYPE_MAINLABEL 0x01
		#define RowHeadersTYPE_SHORTLABEL 0x02
		#define RowHeadersTYPE_NONE 0x03
		---
*/
typedef uint8_t RowHeadersTYPE;
#define RowHeadersTYPE_MAINLABEL 0x01
#define RowHeadersTYPE_SHORTLABEL 0x02
#define RowHeadersTYPE_NONE 0x03

typedef uint8_t SchemaTYPE;
#define SchemaTYPE_LKSCHEMAS 0x01
#define SchemaTYPE_DICTIONARIES 0x02
#define SchemaTYPE_NONE 0x03


/*
	Constants: DBMV_Mark (char)

	Special ASCII characters used by Multivalued Databases.

		DBMV_Mark_IM - ('\xFF') Character ASCII 255. IM Multi-value mark.
		DBMV_Mark_AM - ('\xFE') Character ASCII 254. AM Multi-value mark.
		DBMV_Mark_VM - ('\xFD') Character ASCII 253. VM Multi-value mark.
		DBMV_Mark_SM - ('\xFC') Character ASCII 252. SM Multi-value mark.
		DBMV_Mark_TM - ('\xFB') Character ASCII 251. TM Multi-value mark.
*/
#define DBMV_Mark_IM '\xFF'
#define DBMV_Mark_AM '\xFE'
#define DBMV_Mark_VM '\xFD'
#define DBMV_Mark_SM '\xFC'
#define DBMV_Mark_TM '\xFB'

/*
	Constants: DBMV_Mark (string)

	Special ASCII characters used by Multivalued Databases.
		
		DBMV_Mark_IM - ("\xFF") Character ASCII 255. IM Multi-value mark.
		DBMV_Mark_AM - ("\xFE") Character ASCII 254. AM Multi-value mark.
		DBMV_Mark_VM - ("\xFD") Character ASCII 253. VM Multi-value mark.
		DBMV_Mark_SM - ("\xFC") Character ASCII 252. SM Multi-value mark.
		DBMV_Mark_TM - ("\xFB") Character ASCII 251. TM Multi-value mark.
*/
#define DBMV_Mark_IM_str "\xFF"
#define DBMV_Mark_AM_str "\xFE"
#define DBMV_Mark_VM_str "\xFD"
#define DBMV_Mark_SM_str "\xFC"
#define DBMV_Mark_TM_str "\xFB"

/*
	Constants: ASCII (uint8_t)

	Some ASCII characters used by Linkar.

		ASCII_DC4 - (0x14) Used as separator of the arguments of a subroutine.
		ASCII_FS - (0x1C) When the responses of the operations are of MV type, this character is used to separate the header (the ThisList property) from the data.
		ASCII_RS - (0x1E) Used by Linkar as separator of items in lists. For example, list of records.
*/	
#define ASCII_DC4 (uint8_t) 0x14
#define ASCII_FS (uint8_t) 0x1C
#define ASCII_RS (uint8_t) 0x1E
#define ASCII_US (uint8_t) 0x1F

/*
	Constants: ASCII (string)

	Some ASCII characters used by Linkar.

		ASCII_DC4_str - ("\x14") Used as separator of the arguments of a subroutine. 
		ASCII_FS_str - ("\x1C") When the responses of the operations are of MV type, this character is used to separate the header (the ThisList property) from the data.
		ASCII_RS_str - ("\x1E") Used by Linkar as separator of items in lists. For example, list of records.
*/	
#define ASCII_DC4_str "\x14"
#define ASCII_FS_str "\x1C"
#define ASCII_RS_str "\x1E"
#define ASCII_US_str "\x1F"
