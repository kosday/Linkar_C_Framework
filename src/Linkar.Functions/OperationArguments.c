/*	
	File: OperationArguments.c 
	Library: Linkar.Functions

    Auxiliary functions to obtain the 3 items of every LinkarSERVER operation.

    These items are: CUSTOMVARS, OPTIONS and INPUTDATA.

    Unit Separator character (31) is used as separator between these items.

   	CUSTOMVARS: String for database custom subroutines.
	
    OPTIONS: The options of every operation.
    
	INPUT: The necesary data for perform every operation.

	CUSTOMVARS US_char OPTIONS US_char INPUT
	
	Note:
	All functions comments here, return a char* value. That memory was allocated dynamically, so once those string is not needed anymore, the memory assigned to them *must be released*.
	See <Release Memory> for known how to do.1
*/

#include "OperationArguments.h"
#include "LinkarStringsHelper.h"
#include "OperationOptions.h"
#ifndef _MSC_VER
	#include <malloc.h>
#endif

/* 
	Function: LkGetReadArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the Read operation.
	
	Arguments:
		filename - File name to read.
		recordIds - It's the records codes list to read, separated by the Record Separator character (30). Use <LkComposeRecordIds> to compose this string.
		dictionaries - List of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer.
		readOptions - String that defines the different reading options of the Function: Calculated, dictClause, conversion, formatSpec, originalRecords.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePermanentOperation>.
	
	Example:
		See <DirectFunctions.c> and <PersistentFunctions.c> for examples.
		
	See Also:
		<LkComposeRecordIds>
		
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetReadArgs(const char* const filename, const char* const recordIds, const char* const dictionaries, const char* const readOptions, const char* const customVars)
{
	char* readOpt;
	if(readOptions == NULL || *readOptions == 0)
		readOpt = LkCreateReadOptions(FALSE, FALSE, FALSE, FALSE);
	else
		readOpt = (char*)readOptions;
	
	//inputData = filename + DBMV_Mark.AM + recordIds + DBMV_Mark.AM + dictionaries;
	char* aux = LkCatString(filename, recordIds, DBMV_Mark_AM_str);
	char* inputData = LkCatString(aux, dictionaries, DBMV_Mark_AM_str);
	free (aux);
		
	//operationArguments = customVars + ASCII_Chars.US_str + options + ASCII_Chars.US_str + inputData;
	aux = LkCatString(customVars, readOpt, ASCII_US_str);
	char* operationArguments = LkCatString(aux, inputData, ASCII_US_str);
		
	free(aux);
	free(inputData);
	
	if(readOptions != readOpt)
		free(readOpt);
	
	return operationArguments;
}


/* 
	Function: LkGetUpdateArgs
		Compose the 3 items ( CUSTOMVARS, OPTIONS and INPUTDATA) of the Update operation.
	
	Arguments:
		filename - File name where you are going to write.
		records - Are the records you want to update. Inside this string are the recordIds, the records, and the originalRecords. Use <LkComposeUpdateBuffer> function to compose this string.
		updateOptions - String that defines the different writing options of the Function: optimisticLockControl, readAfter, calculated, dictionaries, conversion, formatSpec, originalRecords.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:
		<LkComposeUpdateBuffer>
		
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetUpdateArgs(const char* const filename, const char* const records, const char* const updateOptions, const char* const customVars)
{
	char* updateOpt;
	if(updateOptions == NULL || *updateOptions == 0)
		updateOpt = LkCreateUpdateOptions(FALSE, FALSE, FALSE, FALSE, FALSE, FALSE);
	else
		updateOpt = (char*)updateOptions;
	
	//inputData = filename + DBMV_Mark.AM + records;
	char* inputData = LkCatString(filename, records, DBMV_Mark_AM_str);

	//operationArguments = customVars + ASCII_Chars.US_str + options + ASCII_Chars.US_str + inputData;
	char*aux = LkCatString(customVars, updateOpt, ASCII_US_str);
	char* operationArguments= LkCatString(aux, inputData, ASCII_US_str);
	free(aux);
	free(inputData);
	
	if(updateOptions != updateOpt)
		free(updateOpt);
	
	return operationArguments;
}

/* 
	Function: LkGetUpdatePartialArgs
		Compose the 3 items ( CUSTOMVARS, OPTIONS and INPUTDATA) of the UpdatePartial operation.
	
	Arguments:
		filename - File name where you are going to write.
		records - Are the records you want to update. Inside this string are the recordIds, the records, and the originalRecords. Use <LkComposeUpdateBuffer> function to compose this string.
		dictionaries - List of dictionaries to write, separated by space. In MV output format is mandatory.
		updateOptions - String that defines the different writing options of the Function: optimisticLockControl, readAfter, calculated, dictionaries, conversion, formatSpec, originalRecords.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:
		<LkComposeUpdateBuffer>
		
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetUpdatePartialArgs(const char* const filename, const char* const records, const char* const dictionaries, const char* const updateOptions, const char* const customVars)
{
	char* updateOpt;
	if(updateOptions == NULL || *updateOptions == 0)
		updateOpt = LkCreateUpdateOptions(FALSE, FALSE, FALSE, FALSE, FALSE, FALSE);
	else
		updateOpt = (char*)updateOptions;
	
	//inputData = filename + DBMV_Mark.AM + records + ASCII_Chars.FS_str + dictionaries;
	char* partialInputData = LkCatString(filename, records, DBMV_Mark_AM_str);
	char* inputData = LkCatString(partialInputData, dictionaries, ASCII_FS_str);
	free(partialInputData);

	//operationArguments = customVars + ASCII_Chars.US_str + options + ASCII_Chars.US_str + inputData;
	char*aux = LkCatString(customVars, updateOpt, ASCII_US_str);
	char* operationArguments= LkCatString(aux, inputData, ASCII_US_str);
	free(aux);
	free(inputData);
	
	if(updateOptions != updateOpt)
		free(updateOpt);
	
	return operationArguments;
}


/* 
	Function: LkGetNewArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the New operation.
	
	Arguments:
		filename - File name where you are going to write.
		records - Are the records you want to write. Inside this string are the recordIds, and the records. Use <LkComposeNewBuffer> function to compose this string.
		newOptions - String that defines the following writing options of the Function: recordIdType, readAfter, calculated, dictionaries, conversion, formatSpec, originalRecords.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.</returns>
		
	See Also:	
		<LkComposeNewBuffer>
		
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetNewArgs(const char* const filename, const char* const records, const char* const newOptions, const char* const customVars)
{
	char* newOpt;
	if(newOptions == NULL || *newOptions == 0)
		newOpt = LkCreateNewOptions(NULL, FALSE, FALSE, FALSE, FALSE, FALSE);
	else
		newOpt = (char*)newOptions;
	
	//inputData = filename + DBMV_Mark.AM + records;
	char* inputData = LkCatString(filename, records, DBMV_Mark_AM_str);

	//operationArguments = customVars + ASCII_Chars.US_str + options + ASCII_Chars.US_str + inputData;
	char*aux = LkCatString(customVars, newOpt, ASCII_US_str);
	char* operationArguments= LkCatString(aux, inputData, ASCII_US_str);
	free(aux);
	free(inputData);
	
	if(newOptions != newOpt)
		free(newOpt);
	
	return operationArguments;
}


/* 
	Function: LkGetDeleteArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the Delete operation.
	
	Arguments:
		filename - It's the file name where the records are going to be deleted. DICT in case of deleting a record that belongs to a dictionary.
		records - It's the records list to be deleted. Use <LkComposeDeleteBuffer> function to compose this string.
		deleteOptions - String that defines the different Function options: optimisticLockControl, recoverRecordIdType.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:
		<LkComposeDeleteBuffer>
		
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetDeleteArgs(const char* const filename, const char* const records, const char* deleteOptions, const char* const customVars)
{
	char* deleteOpt;
	if(deleteOptions == NULL || *deleteOptions == 0)
		deleteOpt = LkCreateDeleteOptions(FALSE, NULL);
	else
		deleteOpt = (char*)deleteOptions;
	
	//inputData = filename + DBMV_Mark.AM + records;
	char* inputData = LkCatString(filename, records, DBMV_Mark_AM_str);
	
	//operationArguments = customVars + ASCII_Chars.US_str + options + ASCII_Chars.US_str + inputData;
	char*aux = LkCatString(customVars, deleteOpt, ASCII_US_str);
	char* operationArguments= LkCatString(aux, inputData, ASCII_US_str);
	free(aux);
	free(inputData);
	
	if(deleteOptions != deleteOpt)
		free(deleteOpt);
	
	return operationArguments;
}


/* 
	Function: LkGetSelectArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the Select operation.
	
	Arguments:
		filename - File name where the select operation will be perform. For example LK.ORDERS
		selectClause - Fragment of the phrase that indicate the selection condition. For example WITH CUSTOMER = '1'
		sortClause - Fragment of the phrase that indicates the selection order. If there is a selection rule, Linkar will execute a SSELECT, otherwise Linkar will execute a SELECT. For example BY CUSTOMER
		dictClause - Is the list of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer. For example CUSTOMER DATE ITEM. Use <LkComposeDictionaries> function to compose this string.
		preSelectClause - It's an optional statement that will execute before the main Select.
		selectOptions - Object that defines the different reading options of the Function: calculated, dictionaries, conversion, formatSpec, originalRecords, onlyItemId, pagination, regPage, numPage.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:	
		<LkComposeDictionaries>
		
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetSelectArgs(const char* const filename, const char* const selectClause,
							 const char* const sortClause, const char* const dictClause, const char* const preSelectClause,
							 const char* const selectOptions, const char* const customVars)
{
	char* selectOpt;
	if(selectOptions == NULL || *selectOptions == 0)
		selectOpt = LkCreateSelectOptions(FALSE, FALSE, 0, 0, FALSE, FALSE, FALSE, FALSE);
	else
		selectOpt = (char*)selectOptions;
	
	//inputData = filename + DBMV_Mark.AM + selectClause + DBMV_Mark.AM + sortClause + DBMV_Mark.AM + dictClause + DBMV_Mark.AM + preSelectClause;
	char* aux = LkCatString(filename, selectClause, DBMV_Mark_AM_str);
	char* inputData = LkCatString(aux, sortClause, DBMV_Mark_AM_str);
	free(aux);
	aux = inputData;
	inputData = LkCatString(inputData, dictClause, DBMV_Mark_AM_str);
	free(aux);
	aux = inputData;
	inputData = LkCatString(inputData, preSelectClause, DBMV_Mark_AM_str);
	free(aux);
	
    //operationArguments  = customVars + ASCII_Chars.US_str + options + ASCII_Chars.US_str + inputData;
	aux = LkCatString(customVars, selectOpt, ASCII_US_str);	
	char* operationArguments = LkCatString(aux, inputData, ASCII_US_str);
	free(aux);
	free(inputData);
	
	if(selectOptions != selectOpt)
		free(selectOpt);
	
	return operationArguments;
}


/* 
	Function: LkGetSubroutineArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the Subroutine operation.
	
	Arguments:
		subroutineName - Subroutine name you want to execute.
		argsNumber - Number of arguments. Use LkComposeSubroutineArgs function to compose this string
		arguments - The subroutine arguments list.  Use <LkComposeSubroutineArgs> function to compose this string.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:
		<LkComposeSubroutineArgs>
		
		<Release Memory>
*/
DllEntry char* LkGetSubroutineArgs(const char* const subroutineName, uint32_t argsNumber, const char* const arguments, const char* const customVars)
{
	char argsNumberStr[100];
	sprintf(argsNumberStr,"%d",argsNumber);
	
	//inputData = inputData1 + ASCII_Chars.FS_str + inputData2;
	char* inputData1 = LkCatString(subroutineName, argsNumberStr, DBMV_Mark_AM_str);
	char* inputData2 = (char*)arguments;
	char* inputData = LkCatString(inputData1, inputData2, ASCII_FS_str);
	free(inputData1);
	
    //operationArguments  = customVars + ASCII_Chars.US_str + options + ASCII_Chars.US_str + inputData;
	char* options = NULL;
	char* aux = LkCatString(customVars, options, ASCII_US_str);	
	char* operationArguments = LkCatString(aux, inputData, ASCII_US_str);
	free(aux);
	free(inputData);

	return operationArguments;	
}


/* 
	Function: LkGetConversionArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the Conversion operation.
	
	Arguments:
		expression - The data or expression to convert. It can have MV marks, in which case the conversion will execute in each value obeying the original MV mark.
		code - The conversion code. It will have to obey the Database conversions specifications.
		conversionOptions - Indicates the conversion type, input or output: Input=ICONV(); OUTPUT=OCONV()
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:	
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetConversionArgs(const char* const expression, const char* const code, CONVERSION_TYPE conversionType, const char* const customVars)
{
	const char* strConversionType;
	if(conversionType == CONVERSION_TYPE_ICONV)
		strConversionType = "I";
	else
		strConversionType = "O";
		//inputData = code + ASCII_Chars.FS_str + expression;
	char* inputData = LkCatString(code, expression, ASCII_FS_str);
	
	//operationArguments = customVars + ASCII_Chars.US_str + strConversionType + ASCII_Chars.US_str + inputData;
	char* aux = LkCatString(customVars, strConversionType, ASCII_US_str);
	char* operationArguments = LkCatString(aux, inputData, ASCII_US_str);
	free(aux);
	free(inputData);
	
	return operationArguments;
}


/* 
	Function: LkGetFormatArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the Format operation.
	
	Arguments:
		expression - The data or expression to format. It can contain MV marks, in which case the conversion in each value will be executed according to the original MV mark.
		formatSpec - Specified format
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:	
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetFormatArgs(const char* const expression, const char* const formatSpec, const char* const customVars)
{
	char* options = NULL;
	char* inputData = LkCatString(formatSpec, expression, ASCII_FS_str);
	
	char* aux = LkCatString(customVars, options, ASCII_US_str);
	char* operationArguments = LkCatString(aux, inputData, ASCII_US_str);
	free(aux);
	
	return operationArguments;
}


/* 
	Function: LkGetDictionariesArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the Dictionaries operation.
	
	Arguments:
		filename - File name.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:	
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetDictionariesArgs(const char* const filename, const char* const customVars)
{
	char* options = NULL;
	char* aux = LkCatString(customVars, options, ASCII_US_str);
	char* operationArguments = LkCatString(aux, filename, ASCII_US_str);
	free(aux);
	
	return operationArguments;
}


/* 
	Function: LkGetExecuteArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the Execute operation.
	
	Arguments:
		statement - The command you want to execute in the Database.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:	
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetExecuteArgs(const char* const statement, const char* const customVars)
{
	char* options = NULL;
	char* aux = LkCatString(customVars, options, ASCII_US_str);
	char* operationArguments = LkCatString(aux, statement, ASCII_US_str);
	free(aux);
	
	return operationArguments;
}


/* 
	Function: LkGetGetVersionArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the Version operation.
	   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:	
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetGetVersionArgs()
{
	char* customVars = NULL;
	char* options = NULL;
	char* inputData = NULL;
	char* aux = LkCatString(customVars, options, ASCII_US_str);
	char* operationArguments = LkCatString(aux, inputData, ASCII_US_str);
	free(aux);
	
	return operationArguments;
}


/* 
	Function: LkGetLkSchemasArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the LkSchemas operation.
	
	Arguments:
		lkSchemasOptions - This string defines the different options in base of the asked Schema Type: LKSCHEMAS, SQLMODE o DICTIONARIES.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.		
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:
		<LkCreateSchOptionsTypeLKSCHEMAS>
		<LkCreateSchOptionsTypeSQLMODE>
		<LkCreateSchOptionsTypeDICTIONARIES>
		<LkExecuteDirectOperation>
		<LkExecutePersistentOperation>
		<Release Memory>
*/
DllEntry char* LkGetLkSchemasArgs(const char* const lkSchemasOptions, const char* const customVars)
{
	char* inputData = NULL;
	
	char* lkSchemasOpt;
	if(lkSchemasOptions == NULL || *lkSchemasOptions == 0)
		lkSchemasOpt = LkCreateSchOptionsTypeLKSCHEMAS(RowHeadersTYPE_MAINLABEL, FALSE, FALSE, FALSE, 0, 0);
	else
		lkSchemasOpt = (char*)lkSchemasOptions;

	char* aux = LkCatString(customVars, lkSchemasOptions, ASCII_US_str);
	char* operationArguments = LkCatString(aux, inputData, ASCII_US_str);
	free(aux);
	
	if(lkSchemasOptions != lkSchemasOpt)
		free(lkSchemasOpt);

	return operationArguments;
}


/* 
	Function: LkGetLkPropertiesArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the LkProperties operation.
	
	Arguments:
		filename - File name to LkProperties.
		lkPropertiesOptions - This string defines the different options in base of the asked Schema Type: LKSCHEMAS, SQLMODE o DICTIONARIES.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:
		<LkCreatePropOptionsTypeLKSCHEMAS>
		
		<LkCreatePropOptionsTypeSQLMODE>
		
		<LkCreatePropOptionsTypeDICTIONARIES>
		
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetLkPropertiesArgs(const char* const filename, const char* const lkPropertiesOptions, const char* const customVars)
{
	char* lkPropertiesOpt;
	if(lkPropertiesOptions == NULL || *lkPropertiesOptions == 0)
		lkPropertiesOpt = LkCreatePropOptionsTypeLKSCHEMAS(RowHeadersTYPE_MAINLABEL, FALSE, FALSE, FALSE, FALSE, 0, 0);
	else
		lkPropertiesOpt = (char*)lkPropertiesOptions;

	char* aux = LkCatString(customVars, lkPropertiesOptions, ASCII_US_str);
	char* operationArguments = LkCatString(aux, filename, ASCII_US_str);
	free(aux);
	
	if(lkPropertiesOptions != lkPropertiesOpt)
		free(lkPropertiesOpt);

	return operationArguments;	
}


/* 
	Function: LkGetGetTableArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the GetTable operation.
	
	Arguments:
		filename - File or table name defined in Linkar Schemas. Table notation is: MainTable[.MVTable[.SVTable]]
		selectClause - Fragment of the phrase that indicate the selection condition. For example WITH CUSTOMER = '1'
		dictClause - Is the list of dictionaries to read, separated by space. If dictionaries are not indicated the function will read the complete buffer. For example CUSTOMER DATE ITEM
		sortClause - Fragment of the phrase that indicates the selection order. If there is a selection rule Linkar will execute a SSELECT, otherwise Linkar will execute a SELECT. For example BY CUSTOMER
		tableOptions - Different function options: rowHeaders, rowProperties, onlyVisibe, usePropertyNames, repeatValues, applyConversion, applyFormat, calculated, pagination, regPage, numPage.
		customVars - It's a free text that will travel until the database to make the admin being able to manage additional behaviours in the standard routine SUB.LK.MAIN.CONTROL.CUSTOM. This routine will be called if the argument has content.
   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:
		<LkCreateTableOptionsTypeLKSCHEMAS>
		
		<LkCreateTableOptionsTypeSQLMODE>
		
		<LkCreateTableOptionsTypeDICTIONARIES>
		
		<LkCreateTableOptionsTypeNONE>
		
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetGetTableArgs(const char* const filename, const char* const selectClause, const char* const dictClause, const char* const sortClause,
                               const char* const tableOptions, const char* const customVars)
{
   char* aux = LkCatString(filename, selectClause, DBMV_Mark_AM_str);   
   char* inputData = LkCatString(aux, dictClause, DBMV_Mark_AM_str);
   free(aux);
   aux = inputData;
   inputData = LkCatString(inputData, sortClause, DBMV_Mark_AM_str);
   free(aux);

	char* tableOpt;
	if(tableOptions == NULL || *tableOptions == 0)
		tableOpt = LkCreateTableOptionsTypeLKSCHEMAS(RowHeadersTYPE_MAINLABEL, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0, 0);
		
		
	else
		tableOpt = (char*)tableOptions;
   
   aux = LkCatString(customVars, tableOptions, ASCII_US_str);
   char* operationArguments = LkCatString(aux, inputData, ASCII_US_str);
   free(aux);
   free(inputData);

	if(tableOptions != tableOpt)
		free(tableOpt);
   
   return operationArguments;
}


/* 
	Function: LkGetResetCommonBlocksArgs
		Compose the 3 items (CUSTOMVARS, OPTIONS and INPUTDATA) of the ResetCommonBlocks operation.
	   
	Returns:      
		A string ready to be used in <LkExecuteDirectOperation> and <LkExecutePersistentOperation>.
		
	See Also:	
		<LkExecuteDirectOperation>
		
		<LkExecutePersistentOperation>
		
		<Release Memory>
*/
DllEntry char* LkGetResetCommonBlocksArgs()
{
	char* customVars = NULL;
	char* options = NULL;
	char* inputData = NULL;
	char* aux = LkCatString(customVars, options, ASCII_US_str);
	char* operationArguments = LkCatString(aux, inputData, ASCII_US_str);
	free(aux);
	
	return operationArguments;
}
