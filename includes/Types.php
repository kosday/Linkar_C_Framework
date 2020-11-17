<?php

//Operation codes for LkExecuteDirectOperation and LkExecutePersistentOperation functions of Linkar Library
class OpCode
{
	const OpLOGIN = 1;
	const OpREAD = 2;
	const OpUPDATE = 3;
	const OpNEW = 4;
	const OpDELETE = 5;
	const OpCONVERSION = 6;
	const OpFORMAT = 7;
	const OpLOGOUT = 8;
	const OpGETVERSION = 9;
	const OpSELECT = 10;
	const OpSUBROUTINE = 11;
	const OpEXECUTE = 12;
	const OpDICTIONARIES = 13;
	const OpLKSCHEMAS = 14;
	const OpLKPROPERTIES = 15;
	const OpGETTABLE = 16;
	const OpRESETCOMMONBLOCKS = 17;
	const OpCOMMAND_XML = 150;
	const OpCOMMAND_JSON = 151;
}

class CredentialOptions
{
	const HOST = 0;
	const ENTRYPOINT = 1;
	const PORT = 2;
	const USERNAME = 3;
	const PASSWORD = 4;
	const LANGUAGE = 5;
	const FREETEXT = 6;
	const PLUGINID = 7;
}

class ConnectionInfo
{
	const HOST = 0;
	const ENTRYPOINT = 1;
	const PORT = 2;
	const USERNAME = 3;
	const PASSWORD = 4;
	const LANGUAGE = 5;
	const FREETEXT = 6;
	const PLUGINID = 7;
	const SESSION_ID = 8;
	const ID = 9;
	const PUBLIC_KEY = 10;
	const RECEIVE_TIMEOUT = 11;
}

//The conversion type for LkConversion functions.
class ConversionType
{
	const I_CONV = 1;
	const O_CONV = 2;
}

//Indicates in what format you want to receive the data resulting from the operation.
//For some operations, also the format in you want to send the data.
class DataFormatType
{
	const MV = 1;
	const XML = 2;
	const JSON = 3;
}

//Specify the output formats of LkSchemas and LkProperties operations.
class DataFormatSchType
{
	const MV = 1;
	const XML = 2;
	const JSON = 3;
	const TABLE = 4;
}

//Specify the output formats of LkRead, LkUpdate, LkNew and LkSelect operations.
class DataFormatCruType
{
	const MV = 1;
	const XML = 2;
	const JSON = 3;
	const XML_DICT = 5;
	const XML_SCH = 6;
	const JSON_DICT = 7;
	const JSON_SCH = 8;
}

//Specify the output formats of LkRead, LkUpdate, LkNew and LkSelect operations
//in LinkarFunctionsDirectXML and LinakrFunctionsPersistentXML libraries
class XML_FORMAT
{
	const XML = 2;
	const XML_DICT = 5;
	const XML_SCH = 6;
}

//Specify the output formats of LkRead, LkUpdate, LkNew and LkSelect operations
//in LinkarFunctionsDirectJSON and LinakrFunctionsPersistentJSON libraries
class JSON_FORMAT
{
	const JSON = 3;
	const JSON_DICT = 7;
	const JSON_SCH = 8;
}

//Indicates in what format you want to send the command for LkSendCommnad operation.
class EnvelopeFormatType
{
	const XML = 2;
	const JSON = 3;
}

//Indicates options to include headers in the first row or not.
//Used only by LkSchmasOptions, LkPropertiesOptions and TableOptions.
class RowHeadersType
{
	const MAINLABEL = 1;
	const SHORTLABEL = 2;
	const NONE = 3;
}

class SchemaType
{
	const LKSCHEMAS = 1;
	const DICTIONARIES = 2;
	const NONE = 3;
}

//Special ASCII characters used by Multivalued Databases.
class DBMV_Mark
{
	const IM = 255; //Character ASCII 255. IM Multi-value mark.
	const AM = 254; //Character ASCII 254. AM Multi-value mark.
	const VM = 253; //Character ASCII 253. VM Multi-value mark.
	const SM = 252; //Character ASCII 252. SM Multi-value mark.
	const TM = 251; //Character ASCII 251. TM Multi-value mark.
}

//Some ASCII characters used by Linkar.
class ASCII
{
	const DC4 = 20;
	const FS = 28;
	const RS = 30;
	const US = 31;
	
	const TAB = 9;
	const LF = 10;
	const VT = 11;
	const CR = 13;
}

?>