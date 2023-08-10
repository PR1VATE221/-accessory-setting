#define FILTERSCRIPT
#include "a_samp.inc"
#include "sscanf2.inc"

/* ���� ������ ������������ mysql ��� ������ � FS, ����� �������� ��� ����,
���� �� ���������� ������������� mxINI, ����� ���������� ���������������� ��������� �������: */
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
		printf("| ��� �������������: MySQL        |");
	#else
		printf("| ��� �������������: mxINI        |");
	#endif
	printf("Made for pawn's users");
	printf("--------------------------------");
	return true;
}

#include "module\main.inc"


#undef FILTERSCRIPT