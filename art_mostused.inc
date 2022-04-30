/*

	(c) 2022 Arthur 'ArTDsL' Dias dos Santos Lasso.
	https://www.artdsl.space/

	* PROJECT MADE PUBLIC UNDER MIT LICENSE *

	- https://github.com/ArTDsL/ARTDSL-ICL-SAMP/


	##
		Name: ART_MOSTUSED.inc
		Creation date: 2022/04/24
		Last Update: 2022/04/30
	##

*/
stock PlayerPlayAnimWithPlayer(playerid, targetid, animid, bool:InFront = false){

}
stock is_integer(const number[]){ 
	new num_size = strlen(number);
	if(num_size == 0){
		return false;
	}else{
		for(new nm = 0; nm < num_size; nm++){
			if(number[nm] < '0' || number[nm] > '9' || number[nm] == '!' || number[nm] == '%'){
				return false;
			} 
		}
	}
	return true;
}
stock is_float(const number[]){
	new hasDot = 0;
	new dotPos = 0;
	if(strfind(number, ".") != -1){
		hasDot = 1;
		dotPos = strfind(number, ".");
	}
	if(hasDot == 1){
		new strNum[30];
		strcat(strNum, number, sizeof(strNum));
		strdel(strNum, dotPos, dotPos);
		if(is_integer(strNum)){
			return true;
		}else{
			return true;
		}
	}else{
		return false;
	}
}
stock GetXYInFrontOfCordinate(Float:x_cord, Float:y_cord, Float:r_cord, Float:distance = 10.0, &Float:return_x_cord, &Float:return_y_cord){
	return_x_cord = x_cord + (distance * floatsin(-r_cord, degrees));
	return_y_cord =  y_cord + (distance * floatcos(-r_cord, degrees));
}
stock GetXYInFrontOfPlayer(playerid, Float:distance = 10.0, &Float:return_x_cord, &Float:return_y_cord){
	new Float:ppos_x, Float:ppos_y, Float:ppos_z, Float:ppos_r;
	GetPlayerPos(playerid, ppos_x, ppos_y, ppos_z);
	GetPlayerFacingAngle(playerid, ppos_r);
	return_x_cord = ppos_x + (distance * floatsin(-ppos_r, degrees));
	return_y_cord =  ppos_y + (distance * floatcos(-ppos_r, degrees));
}
stock inline_format(const formato[], params[]){
	#pragma warning disable 209 //remove warning de return
	new num_parameters = 0;
	for(new i = 0; i < sizeof(params[]); i++){
		num_parameters++;
	}
	switch(num_parameters){
		case 1:{ 
			new str[256];
			format(str, sizeof(str), formato, params[0]);
			return str;
		}
		case 2:{
			new str[256];
			format(str, sizeof(str), formato, params[0], params[1]);
			return str;
		}
		case 3:{
			new str[256];
			format(str, sizeof(str), formato, params[0], params[1], params[2]);
			return str;
		}
		case 4:{
			new str[256];
			format(str, sizeof(str), formato, params[0], params[1], params[2], params[3]);
			return str;
		}
		case 5:{
			new str[256];
			format(str, sizeof(str), formato, params[0], params[1], params[2], params[3], params[4]);
			return str;
		}
		case 6:{
			new str[256];
			format(str, sizeof(str), formato, params[0], params[1], params[2], params[3], params[4], params[5]);
			return str;
		}
		case 7:{
			new str[256];
			format(str, sizeof(str), formato, params[0], params[1], params[2], params[3], params[4], params[5], params[6]);
			return str;
		}
	}
}
#pragma warning enable 209 // Habilita warning de return, após carregar!
stock GetVehicleSeatsInfo(vehicleid, &driver, &passager, &left_backseat, &right_backseat){
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
stock ClearChat(){
	for(new i = 0; i < 100; i++){
		SendClientMessageToAll(-1, " ");
	}
	SendClientMessageToAll(-1, "Chat clear by an Administrator");
}