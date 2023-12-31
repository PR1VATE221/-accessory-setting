DialogCreate:attach_main(playerid) {
	Dialog_Open(
		playerid,
		Dialog:attach_main,
		DIALOG_STYLE_INPUT,
		"�������� ������ ���������� - ��������������",
		"{FFFFFF}������� ID �������, ������ � ����� ����� �������.",
		"����", "�������"
	);
	return true;
}

DialogResponse:attach_main(playerid, response, listitem, inputtext[]) {
	new
		object_id,
		object_index,
		object_bone;
	
	if(sscanf(inputtext, "p<,>iii", object_id, object_index, object_bone)) {
		SendClientMessage(playerid, 0xAFAFAFFF, "�� ����� �� ��� ���������.");
		Dialog_Show(playerid, Dialog:attach_main);
		return true;
	}

	SetPlayerSkin(playerid, 1);

	SetPlayerAttachedObject(
		playerid,
		object_index,
		object_id,
		object_bone
	);

	EditAttachedObject(playerid, object_index);
	

	attach_info[playerid][current_skin] = 1;
	attach_info[playerid][attach_object] = object_id;
	attach_info[playerid][attach_index] = object_index;
	attach_info[playerid][attach_bone] = object_bone;
	attach_info[playerid][attach_status] = true;

	SendClientMessage(playerid, 0xFFFFFFFF, "�� ������ ��������� ����������.");
	SendClientMessage(playerid, 0xFFFFFFFF, "����� ��������� (��������) ���������, ������� /stop_creating");
	SendClientMessage(playerid, 0xFFFFFFFF, "��� ���������� ����������, ������� '��������', ��� �������� �����, ������� 'ESC'.");
	
	#if defined mysql_using

	#else
		new player_name[MAX_PLAYER_NAME];

		GetPlayerName(playerid, player_name, sizeof(player_name));

		format(string_text, sizeof(string_text), "%s-objid-%i.ini",
		player_name, object_id);

		format(string_small, sizeof(string_small), "[ OBJECT ID: %i | BONE: %i ]", object_id, object_bone);

		ini_createFile ( string_text , string_small);
	#endif
	return true;
}