public OnPlayerConnect(playerid) {
	attach_info[playerid][attach_status] = false;
	return true;
}

public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ ) {
	if(response == 1) {

		new
			player_name[MAX_PLAYER_NAME];

		GetPlayerName(playerid, player_name, sizeof(player_name));

		format(string_text, sizeof(string_text), "%s-objid-%i.ini",
		player_name, attach_info[playerid][attach_object]);

		format(string_small, sizeof(string_small), "[FS] Скин {AFAFAF}%i{FFFFFF} записан в файл.", attach_info[playerid][current_skin]);
		SendClientMessage(playerid, 0xFFFFFFFF, string_small);

		new iniFile = ini_openFile ( string_text );

		format(string_small, sizeof(string_small), "SKIN № %i", attach_info[playerid][current_skin]);
		format(string_text, sizeof(string_text), 
		"SetPlayerAttachedObject(playerid, %i, %i, %i, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, 0, 0)",
		index, modelid, boneid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ);

		ini_setString  ( iniFile, string_small, string_text );

		ini_closeFile  ( iniFile );

		attach_info[playerid][current_skin]++;
		SetPlayerSkin(playerid, attach_info[playerid][current_skin]);
		EditAttachedObject(playerid, index);		
		
		return true;
	} else {
		format(string_small, sizeof(string_small), "[FS] Скин {AFAFAF}%i{FFFFFF} пропущен", attach_info[playerid][current_skin]);
		SendClientMessage(playerid, 0xFFFFFFFF, string_small);
		attach_info[playerid][current_skin]++;
		SetPlayerSkin(playerid, attach_info[playerid][current_skin]);
		EditAttachedObject(playerid, index);
	}
	return true;
}