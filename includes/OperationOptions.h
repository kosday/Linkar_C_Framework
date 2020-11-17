/*
	File: OperationOptions.h
	Header file for OperationOptions.c

	Prototype Functions:
	--- Code
	static char* LkCreateCommonOptions(BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords);
	static char* LkCreateReadAfterCommonOptions(BOOL readAfter, BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords);
	
	DllEntry char* LkCreateReadOptions(BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords);
	DllEntry char* LkCreateUpdateOptions(BOOL optimisticLock, BOOL readAfter, BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords);
	
	DllEntry char* LkCreateNewOptions(const char* const newItemIdType, BOOL readAfter, BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords);
	DllEntry char* LkCreateNewRecordIdTypeNone();
	DllEntry char* LkCreateNewRecordIdTypeLinkar(const char* const prefix, const char* const separator, const char* const formatSpec);
	DllEntry char* LkCreateNewRecordIdTypeCustom();
	DllEntry char* LkCreateNewRecordIdTypeRandom( BOOL numeric, uint32_t length);
	
	DllEntry char* LkCreateDeleteOptions(BOOL optimisticLock, const char* const recoverIdType);
	DllEntry char* LkCreateRecoverRecordIdTypeNone();
	DllEntry char* LkCreateRecoverRecordIdTypeLinkar(const char* const prefix, const char* const separator);
	DllEntry char* LkCreateRecoverRecordIdTypeCustom();
	
	DllEntry char* LkCreateSelectOptions(BOOL onlyRecordId, BOOL pagination, uint32_t regPage, uint32_t numPage, BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords);
	DllEntry char* LkAddArgumentSubroutine(const char* const arguments, const char* newArgument);
	
	//SCHEMAS
	
	static const char* const GetStrSchemaType(SchemaTYPE schemaType);
	static const char* const GetStrRowHeadersType(RowHeadersTYPE rowHeadersType);
	
	static char* LkCreateLkSchemasOptions(SchemaTYPE schemaType, RowHeadersTYPE rowHeaders, BOOL sqlMode, BOOL rowProperties, BOOL onlyVisibles, BOOL pagination, uint32_t regPage, uint32_t numPage);
	DllEntry char* LkCreateSchOptionsTypeLKSCHEMAS(RowHeadersTYPE rowHeaders, BOOL rowProperties, BOOL onlyVisibles, BOOL pagination, uint32_t regPage, uint32_t numPage);
	DllEntry char* LkCreateSchOptionsTypeSQLMODE(BOOL onlyVisibles, BOOL pagination, uint32_t regPage, uint32_t numPage);
	DllEntry char* LkCreateSchOptionsTypeDICTIONARIES(RowHeadersTYPE rowHeaders, BOOL pagination, uint32_t regPage, uint32_t numPage);
	
	static char* LkCreateLkPropertiesOptions(SchemaTYPE schemaType, RowHeadersTYPE rowHeaders, BOOL sqlMode, BOOL rowProperties, BOOL onlyVisibles, BOOL usePropertyNames, BOOL pagination, uint32_t regPage, uint32_t numPage);
	DllEntry char* LkCreatePropOptionsTypeLKSCHEMAS(RowHeadersTYPE rowHeaders, BOOL rowProperties, BOOL onlyVisibles, BOOL usePropertyNames, BOOL pagination, uint32_t regPage, uint32_t numPage);
	DllEntry char* LkCreatePropOptionsTypeSQLMODE(BOOL onlyVisibles, BOOL pagination, uint32_t regPage, uint32_t numPage);
	DllEntry char* LkCreatePropOptionsTypeDICTIONARIES(RowHeadersTYPE rowHeaders, BOOL pagination, uint32_t regPage, uint32_t numPage);
	
	static char* LkCreateLkGetTableOptions(SchemaTYPE schemaType, RowHeadersTYPE rowHeaders, BOOL sqlMode, BOOL rowProperties, BOOL onlyVisibles, BOOL usePropertyNames, BOOL repeatValues, BOOL applyConversion, BOOL applyFormat, BOOL calculated, BOOL pagination, uint32_t regPage, uint32_t numPage);
	DllEntry char* LkCreateTableOptionsTypeLKSCHEMAS(RowHeadersTYPE rowHeaders, BOOL rowProperties, BOOL onlyVisibles, BOOL usePropertyNames, BOOL repeatValues, BOOL applyConversion, BOOL applyFormat, BOOL calculated, BOOL pagination, uint32_t regPage, uint32_t numPage);
	DllEntry char* LkCreateTableOptionsTypeSQLMODE(BOOL onlyVisibles, BOOL applyConversion, BOOL applyFormat, BOOL calculated, BOOL pagination, uint32_t regPage, uint32_t numPage);
	DllEntry char* LkCreateTableOptionsTypeDICTIONARIES(RowHeadersTYPE rowHeaders, BOOL repeatValues, BOOL applyConversion, BOOL applyFormat, BOOL calculated, BOOL pagination, uint32_t regPage, uint32_t numPage);
	DllEntry char* LkCreateTableOptionsTypeNONE(RowHeadersTYPE rowHeaders, BOOL repeatValues, BOOL pagination, uint32_t regPage, uint32_t numPage);
	---	
*/
#include "CompilerOptions.h"
#include "Types.h"

static char* LkCreateCommonOptions(BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords);
static char* LkCreateReadAfterCommonOptions(BOOL readAfter, BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords);

DllEntry char* LkCreateReadOptions(BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords);
DllEntry char* LkCreateUpdateOptions(BOOL optimisticLock, BOOL readAfter, BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords);

DllEntry char* LkCreateNewOptions(const char* const newItemIdType, BOOL readAfter, BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords);
DllEntry char* LkCreateNewRecordIdTypeNone();
DllEntry char* LkCreateNewRecordIdTypeLinkar(const char* const prefix, const char* const separator, const char* const formatSpec);
DllEntry char* LkCreateNewRecordIdTypeCustom();
DllEntry char* LkCreateNewRecordIdTypeRandom( BOOL numeric, uint32_t length);

DllEntry char* LkCreateDeleteOptions(BOOL optimisticLock, const char* const recoverIdType);
DllEntry char* LkCreateRecoverRecordIdTypeNone();
DllEntry char* LkCreateRecoverRecordIdTypeLinkar(const char* const prefix, const char* const separator);
DllEntry char* LkCreateRecoverRecordIdTypeCustom();

DllEntry char* LkCreateSelectOptions(BOOL onlyRecordId, BOOL pagination, uint32_t regPage, uint32_t numPage, BOOL calculated, BOOL conversion, BOOL formatSpec, BOOL originalRecords);
DllEntry char* LkAddArgumentSubroutine(const char* const arguments, const char* newArgument);

//SCHEMAS

static const char* const GetStrSchemaType(SchemaTYPE schemaType);
static const char* const GetStrRowHeadersType(RowHeadersTYPE rowHeadersType);

static char* LkCreateLkSchemasOptions(SchemaTYPE schemaType, RowHeadersTYPE rowHeaders, BOOL sqlMode, BOOL rowProperties, BOOL onlyVisibles, BOOL pagination, uint32_t regPage, uint32_t numPage);
DllEntry char* LkCreateSchOptionsTypeLKSCHEMAS(RowHeadersTYPE rowHeaders, BOOL rowProperties, BOOL onlyVisibles, BOOL pagination, uint32_t regPage, uint32_t numPage);
DllEntry char* LkCreateSchOptionsTypeSQLMODE(BOOL onlyVisibles, BOOL pagination, uint32_t regPage, uint32_t numPage);
DllEntry char* LkCreateSchOptionsTypeDICTIONARIES(RowHeadersTYPE rowHeaders, BOOL pagination, uint32_t regPage, uint32_t numPage);

static char* LkCreateLkPropertiesOptions(SchemaTYPE schemaType, RowHeadersTYPE rowHeaders, BOOL sqlMode, BOOL rowProperties, BOOL onlyVisibles, BOOL usePropertyNames, BOOL pagination, uint32_t regPage, uint32_t numPage);
DllEntry char* LkCreatePropOptionsTypeLKSCHEMAS(RowHeadersTYPE rowHeaders, BOOL rowProperties, BOOL onlyVisibles, BOOL usePropertyNames, BOOL pagination, uint32_t regPage, uint32_t numPage);
DllEntry char* LkCreatePropOptionsTypeSQLMODE(BOOL onlyVisibles, BOOL pagination, uint32_t regPage, uint32_t numPage);
DllEntry char* LkCreatePropOptionsTypeDICTIONARIES(RowHeadersTYPE rowHeaders, BOOL pagination, uint32_t regPage, uint32_t numPage);

static char* LkCreateLkGetTableOptions(SchemaTYPE schemaType, RowHeadersTYPE rowHeaders, BOOL sqlMode, BOOL rowProperties, BOOL onlyVisibles, BOOL usePropertyNames, BOOL repeatValues, BOOL applyConversion, BOOL applyFormat, BOOL calculated, BOOL pagination, uint32_t regPage, uint32_t numPage);
DllEntry char* LkCreateTableOptionsTypeLKSCHEMAS(RowHeadersTYPE rowHeaders, BOOL rowProperties, BOOL onlyVisibles, BOOL usePropertyNames, BOOL repeatValues, BOOL applyConversion, BOOL applyFormat, BOOL calculated, BOOL pagination, uint32_t regPage, uint32_t numPage);
DllEntry char* LkCreateTableOptionsTypeSQLMODE(BOOL onlyVisibles, BOOL applyConversion, BOOL applyFormat, BOOL calculated, BOOL pagination, uint32_t regPage, uint32_t numPage);
DllEntry char* LkCreateTableOptionsTypeDICTIONARIES(RowHeadersTYPE rowHeaders, BOOL repeatValues, BOOL applyConversion, BOOL applyFormat, BOOL calculated, BOOL pagination, uint32_t regPage, uint32_t numPage);
DllEntry char* LkCreateTableOptionsTypeNONE(RowHeadersTYPE rowHeaders, BOOL repeatValues, BOOL pagination, uint32_t regPage, uint32_t numPage);
