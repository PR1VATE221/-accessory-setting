#define FILTERSCRIPT
#include "a_samp.inc"
#include "sscanf2.inc"

/* Если хотите использовать mysql при работе с FS, тогда оставьте как есть,
Если же необходимо использование mxINI, тогда необходимо закомментировать следующую строчку: */
// #define mysql_using

#if defined mysql_using
		#include "a_mysql.inc"
		new MySQL:dbHandle;		
	#else
		#include "mxINI.inc"
#endif



#include "dc_cmd.inc"
#include "mdialog.inc"


#define FILTERSCRIPT

public OnFilterScriptInit() {

	#if defined mysql_using
		dbHandle = mysql_connect("", "", "", "");
	#endif

	printf("---------------------------------");
	printf("| Accessory Setting script loaded |");
	printf("| Author: James                   |");
	#if defined mysql_using
		printf("| Тип использования: MySQL        |");
	#else
		printf("| Тип использования: mxINI        |");
	#endif
	printf("Made for pawn's users");
	printf("--------------------------------");
	return true;
}

#include "module\main.inc"


#undef FILTERSCRIPT