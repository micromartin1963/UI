
#define _ARMA_

class CfgMods
{
	class CheckItem
	{
		dir = "FOG";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "";
		credits = "";
		author = "Fod";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		inputs = "FOG/CheckItem/data/modded_Inputs.xml";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"FOG/CheckItem/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"FOG/CheckItem/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"FOG/CheckItem/scripts/5_Mission"};
			};
		};
	};
};
class CfgPatches
{
	class CheckItem
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};


class CfgVehicles
{





};
