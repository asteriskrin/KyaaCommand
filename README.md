
# KyaaCommand
<p align="center">
	<img align="center" src="https://media.tenor.com/images/818a1df69200edd887d3bfc99969d65c/tenor.gif">
</p>

KyaaCommand is a library for sending command. Player can use ! symbol instead of / to run a command. 
### Example Commands:
```
!spawn
!help
!ping
etc.
```
## Installation
Install to your project simply by putting `kyaa.inc` to `pawno/includes`.
And then, include it in your code and begin using the library:
```c
#include <kyaa>
```
Don't forget to put a callback. Here it is the callback:
```c++
public OnPlayerKyaa(playerid, kyaa_text[], status) {
	if(!status) {
		// the command has NOT been performed
		// write code here
		
	}
	return 1;
}
```
This callback gets called when kyaa command is typed.
## Usage
Quick example how to use the library:
```c
KYAA:(playerid, parameter[]) {
	// write code here
	SetPlayerPos(playerid, 1234.5678, 910.1112, 1314.1516);
	return 1;
}
```
Return 1 means the command has been performed successfully.
Return 0 means the command has NOT been performed successfully.

## Example

 - Send `kyaa` when player types `!hello`
	```c++
	KYAA:hello(playerid, parameters[]) {
		return SendClientMessage(playerid, 0xFFFFFFFF, "kyaa");
	}
	```
- Redirect a kyaa command: !halo to !hello
	```c++
	KYAA:halo(playerid, parameters[]) {
		return kyaa_hello(playerid, parameters);
	}
	```
- Call multiple kyaa command in one kyaa command
	```c++
	KYAA:heal(playerid, parameters[]) {
		return SetPlayerHealth(playerid, 100.0);
	}
	KYAA:teleport(playerid, para[]) {
		SetPlayerPos(playerid, 1234.0, 320.0, 13.0);
		return 1;
	}
	KYAA:start(playerid, parameters[]) {
		// heal
		kyaa_heal(playerid, "");
		// teleport
		kyaa_teleport(playerid, "");
		// send `kyaa`
		kyaa_halo(playerid, "");
		return 1;
	}
	```