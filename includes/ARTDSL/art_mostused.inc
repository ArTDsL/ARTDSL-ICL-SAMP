/*

	(c) 2022 Arthur 'ArTDsL' Dias dos Santos Lasso.
	https://www.artdsl.space/

	* PROJECT MADE PUBLIC UNDER MIT LICENSE *

	- https://github.com/ArTDsL/ARTDSL-ICL-SAMP/


	##
		Name: ART_MOSTUSED.inc
		Creation date: 2022/04/24
		Last Update: 2022/05/03
	##

*/
stock PlayerPlayAnimWithPlayer(playerid, targetid, const anim_lib[], const anim_name[], anim_time, bool:InFront = false){
	new Float:pp_x, Float:pp_y, Float:pp_z, Float: pp_r;
	GetPlayerPos(playerid, pp_x, pp_y, pp_z);
	GetPlayerFacingAngle(playerid, pp_r);
	if(InFront == true || InFront == 1){
		SetPlayerPos(targetid, pp_x + 1.0, pp_y + 1.0, pp_z);
		SetPlayerFacingAngle(targetid, pp_r + 180.0);
	}
	ClearAnimations(targetid, 1);
	ClearAnimations(playerid, 1);
	SetTimerEx("__ARTDSL_PPAWP_Exec", 1000, false, "ddssd", playerid, targetid, anim_lib, anim_name, anim_time);
}
stock is_integer(const number[]){ //TESTED [OK]
	if(strlen(number) == 0){
		return 0;
	}
	new isNegative = 0;
	new tpos = 0;
	if(strfind(number, "-") != -1){
		isNegative = 1;
		tpos = strfind(number, "-");
	}
	if(isNegative == 1){
		new stkey[11];
		strcat(stkey, number, sizeof(stkey));
		strdel(stkey, tpos, tpos + 1);
		for(new n = 0; n < strlen(stkey); n++){
			if(stkey[n] < '0' || stkey[n] > '9' || stkey[n] == '!' || stkey[n] == '%'){
				return 0;
			}
		}
		return 1;
	}else{
		for(new n = 0; n < strlen(number); n++){
			if(number[n] < '0' || number[n] > '9' || number[n] == '!' || number[n] == '%'){
				return 0;
			}
		}
		return 1;
	}
}
stock is_float(const number[]){ // TESTED [OK]
	new hasDot = 0;
	new hasMinus = 0;
	new dotPos = 0;
	new minusPos = 0;
	if(strfind(number, ".") != -1){
		hasDot = 1;
		dotPos = strfind(number, ".");
	}
	if(strfind(number, "-") != -1){
		hasMinus = 1;
		minusPos = strfind(number, "-");
	}
	if(hasDot == 1){
		new strNum[30];
		strcat(strNum, number, sizeof(strNum));
		strdel(strNum, dotPos, dotPos + 1);
		if(hasMinus == 1){
			strdel(strNum, minusPos, minusPos + 1);
		}
		if(is_integer(strNum) == 1){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}
stock RemoveVendingMachines(playerid){ //TESTED [OK]
	RemoveBuildingForPlayer(playerid, 18885, 0.0, 0.0, 0.0, 15000.0);
	RemoveBuildingForPlayer(playerid, 1209, 0.0, 0.0, 0.0, 15000.0);
	RemoveBuildingForPlayer(playerid, 1776, 0.0, 0.0, 0.0, 15000.0);
	RemoveBuildingForPlayer(playerid, 955, 0.0, 0.0, 0.0, 15000.0);
	RemoveBuildingForPlayer(playerid, 1775, 0.0, 0.0, 0.0, 15000.0);
	RemoveBuildingForPlayer(playerid, 956, 0.0, 0.0, 0.0, 15000.0);
	RemoveBuildingForPlayer(playerid, 1302, 0.0, 0.0, 0.0, 15000.0);
	RemoveBuildingForPlayer(playerid, 1977, 0.0, 0.0, 0.0, 15000.0);
}
stock GetXYInFrontOfCordinate(Float:x_cord, Float:y_cord, Float:r_cord, Float:distance = 10.0, &Float:return_x_cord, &Float:return_y_cord){ //TESTED [OK]
	return_x_cord = x_cord + (distance * floatsin(-r_cord, degrees));
	return_y_cord =  y_cord + (distance * floatcos(-r_cord, degrees));
}
stock GetXYInFrontOfPlayer(playerid, Float:distance = 10.0, &Float:return_x_cord, &Float:return_y_cord){ //TESTED [OK]
	new Float:ppos_x, Float:ppos_y, Float:ppos_z, Float:ppos_r;
	GetPlayerPos(playerid, ppos_x, ppos_y, ppos_z);
	GetPlayerFacingAngle(playerid, ppos_r);
	return_x_cord = ppos_x + (distance * floatsin(-ppos_r, degrees));
	return_y_cord =  ppos_y + (distance * floatcos(-ppos_r, degrees));
}
stock __ARTDSL_ret_inlineMsg(){
	return __ARTDSL_inlinemsg;
}
stock GetVehicleSeatsInfo(vehicleid, &driver, &passager, &left_backseat, &right_backseat){ //TESTED [OK]
	if(!IsValidVehicle(vehicleid)){
		return -1;
	}
	driver = false;
	passager = false;
	left_backseat = false;
	right_backseat = false;
	for(new i = 0; i < MAX_PLAYERS; i++){
		if(IsPlayerInVehicle(i, vehicleid)){
			new seat;
			seat = GetPlayerVehicleSeat(i);
			switch(seat){
				case 0: driver = true;
				case 1: passager = true;
				case 2: left_backseat = true;
				case 3: right_backseat = true;
			}
		}
	}
}
stock ClearChat(){ //TESTED [OK]
	for(new i = 0; i < 100; i++){
		SendClientMessageToAll(-1, " ");
	}
	SendClientMessageToAll(-1, "Chat clear by an Administrator");
}
forward __ARTDSL_PPAWP_Exec(playerid, targetid, const anim_lib[], const anim_name[], anim_time);
public __ARTDSL_PPAWP_Exec(playerid, targetid, const anim_lib[], const anim_name[], anim_time){
	ApplyAnimation(playerid, anim_lib, anim_name, 4.1, false, 0, 0, false, anim_time, 1);
	ApplyAnimation(targetid, anim_lib, anim_name, 4.1, false, 0, 0, false, anim_time, 1);
}
