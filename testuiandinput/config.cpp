////////////////////////////////////////////////////////////////////
//DeRap: Trader\config.bin
//Produced from mikero's Dos Tools Dll version 7.46
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Thu Oct 07 16:59:23 2021 : 'file' last modified on Mon Feb 15 20:17:34 2021
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgMods
{
	class TestUiAndInput
	{
		dir = "Trader";
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
		inputs = "testuiandinput/data/modded_Inputs.xml";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"testuiandinput/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"testuiandinput/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"testuiandinput/scripts/5_Mission"};
			};
		};
	};
};
class CfgPatches
{
	class TestUiAndInput
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
