/**
 * Kyaa Command
 *
 * Author: AsteriskRin
 * Version: 1.0
 */

#if defined _kyaa_included
	#endinput
#endif

#define _kyaa_included

#include <a_samp>

#define MAX_KYAA_NAME (24)

#define KYAA:%1(%2)			\
			forward kyaa_%1(%2); \
			public kyaa_%1(%2)

#if !defined isnull
 	#define isnull(%1) \
 		((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

public OnPlayerKyaa(playerid, kyaa_text[], status);

#if defined FILTERSCRIPT

	public OnFilterScriptInit() {
		return CallLocalFunction("kyaa_OnFilterScriptInit", "");
	}

	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif

	#define OnFilterScriptInit kyaa_OnFilterScriptInit

	forward kyaa_OnFilterScriptInit();

#else

	public OnGameModeInit() {
		if (funcidx("kyaa_OnGameModeInit") != -1)
		{
			return CallLocalFunction("kyaa_OnGameModeInit", "");
		}	
		return 1;
	}

	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit kyaa_OnGameModeInit
	forward kyaa_OnGameModeInit();

#endif

public OnPlayerText(playerid, text[]) {
	if(!isnull(text)) {
		if(text[0] == '!') {
			new pos = 0, kyaa_name[MAX_KYAA_NAME];
			while(text[++pos] > ' ') {
				kyaa_name[pos - 1] = tolower(text[pos]);
			}
			format(kyaa_name, sizeof kyaa_name, "kyaa_%s", kyaa_name);
			while(text[pos] == ' ') pos++;

			// No parameter is passed
			if(!text[pos]) {
				return CallLocalFunction("OnPlayerKyaa", "isi", playerid, text, CallLocalFunction(kyaa_name, "is", playerid, "\1"));
			}
			else {
				return CallLocalFunction("OnPlayerKyaa", "isi", playerid, text, CallLocalFunction(kyaa_name, "is", playerid, text[pos]));
			}
		}
	}
	#if defined kyaa_OnPlayerText
		return kyaa_OnPlayerText(playerid, text);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerText
	#undef OnPlayerText
#else
	#define _ALS_OnPlayerText
#endif
#define OnPlayerText kyaa_OnPlayerText
#if defined kyaa_OnPlayerText
	forward kyaa_OnPlayerText(playerid, text[]);
#endif