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

	SetPlayerSkin(playerid, 0);

	SetPlayerAttachedObject(
		playerid,
		object_index,
		object_id,
		object_bone
	);

	
	return true;
}