# ARTDSL INCLUDE LIBRARY FOR SA-MP


**Last Update:** 30/04/2022


## Functions
| COMMAND                                                                                         | DESCRIPTION                                                                                                      |
| ----------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| is_integer(NUMBER);                                                                             | Receive any string and check if it's have only numeric integer characters (0-9).                                 |
| is_float(NUMBER);                                                                               | Receive any string and check if it's have only float characters.                                                 |
| GetVehicleSeatsInfo(vehicleid, &driver, &passager, &left_backseat, &right_backseat);            | Return true if sit is occupied, false for unoccupied and -1 for no vehicle.                                      |
| ClearChat();                                                                                    | Do what he needs to do... (Bad a** joke ;-;)                                                                     |
| inline_format("The phrase %s", string_to_pass);                                                 | Supports up to 6 params (same as format function but is inline instead) * Support all formats: %s, %d, %i, %f... |
| GetXYInFrontOfCordinate(Float:x, Float:y, Float:r, distance, &Float:return_x, &Float:return_y); | Get cordinate X and Y in front of the cordinated point passed (based on distance!).                              |
| GetXYInFrontOfPlayer(playerid, distance, &Float:return_x, &Float:return_y);                     | Get cordinate X and Y in front of player (based on distance).                                                    |
| PlayerPlayAnimWithPlayer(playerid, targetid, animid, bool:InFront = true);                      | Play animation in sequence with other player (at the same time, great to use with hug, kiss, etc...)             |


## Definitions
| FUNCTION                                                       | DESCRIPTION                                                        |
| -------------------------------------------------------------- | ------------------------------------------------------------------ |
| PFWD::Function_Name(parameters)                                | Create a function and automatic foward and set as public.          |
| is_null(var)                                                   | Check if variable is null.                                         |
| PRESSED(KEY_)                                                  | Check if Key is Pressed (Works only in OnPlayerKeyStateChange).    |


## Parameters
| PARAMETER                                                      | DESCRIPTION                                                        |
| -------------------------------------------------------------- | ------------------------------------------------------------------ |
| INFINITY_LIFE                                                  | e.g GivePlayerHealth(playerid, INFINITY_LIFE); Infinity life.      |
