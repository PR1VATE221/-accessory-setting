CMD:create_attach(playerid) {
	Dialog_Show(playerid, Dialog:attach_main);
	return true;
}

CMD:stop_creating(playerid) {
	if(!attach_info[playerid][attach_status]) {
		return true;
	} else {
		RemovePlayerAttachedObject(playerid, attach_info[playerid][attach_index]);
		attach_info[playerid][current_skin] = -1;
		attach_info[playerid][attach_object] = -1;
		attach_info[playerid][attach_index] = -1;
		attach_info[playerid][attach_bone] = -1;
		attach_info[playerid][attach_status] = false;

		SendClientMessage(playerid, -1, "Вы прервали установку аксессуара.");

		CancelEdit(playerid);

		return true;
	}
}