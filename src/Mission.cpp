#include <ScriptUtils.h>

// Import table from the game, defined here, declared in ScriptUtils.h, note that the time field will always be 0
// for some reason, if you want the true time value use misnExport.misnImport->time
MisnImport misnImport{};

// Export table from the DLL, it's not defined in the function block because it needs
// to stay in scope for the duration of the game.
MisnExport misnExport{};

void DLLAPI InitialSetup()
{
	
}

bool DLLAPI Save(bool missionSave)
{
	return true;
}

bool DLLAPI Load(bool missionSave)
{
	return true;
}

bool DLLAPI PostLoad(bool missionSave)
{
	return true;
}

void DLLAPI AddObject(Handle h)
{

}

void DLLAPI DeleteObject(Handle h)
{

}

void DLLAPI Update()
{

}

void DLLAPI PostRun()
{

}

bool DLLAPI AddPlayer(DPID id, int Team, bool ShouldCreateThem)
{
	return true;
}

void DLLAPI DeletePlayer(DPID id)
{

}

EjectKillRetCodes DLLAPI PlayerEjected(Handle DeadObjectHandle)
{
	return DoEjectPilot;
}

EjectKillRetCodes DLLAPI ObjectKilled(Handle DeadObjectHandle, Handle KillersHandle)
{
	return DoEjectPilot;
}

EjectKillRetCodes DLLAPI ObjectSniped(Handle DeadObjectHandle, Handle KillersHandle)
{
	return DoEjectPilot;
}

const char* DLLAPI GetNextRandomVehicleODF(int ForTeam)
{
	return "PLAYER";
}

void DLLAPI SetWorld(int nextWorld)
{

}

void DLLAPI ProcessCommand(unsigned long crc)
{

}

void DLLAPI SetRandomSeed(unsigned long seed)
{

}

/*
* Define this function in your DLL and fill the export table completely for it to work in-game.
* Also save the import table in the variable we defined earlier.
*/
MisnExport* DLLAPI GetMisnAPI(MisnImport* import)
{	
	misnImport = *import;

	misnExport.misnImport = import;
	misnExport.version = LATEST_DLL_VERSION;
	misnExport.VersionModifier = LATEST_DLL_VERSION_MODIFIER;
	misnExport.InitialSetup = InitialSetup;
	misnExport.Save = Save;
	misnExport.Load = Load;
	misnExport.PostLoad = PostLoad;
	misnExport.AddObject = AddObject;
	misnExport.DeleteObject = DeleteObject;
	misnExport.Update = Update;
	misnExport.PostRun = PostRun;
	misnExport.AddPlayer = AddPlayer;
	misnExport.DeletePlayer = DeletePlayer;
	misnExport.PlayerEjected = PlayerEjected;
	misnExport.ObjectKilled = ObjectKilled;
	misnExport.ObjectSniped = ObjectSniped;
	misnExport.GetNextRandomVehicleODF = GetNextRandomVehicleODF;
	misnExport.SetWorld = SetWorld;
	misnExport.ProcessCommand = ProcessCommand;
	misnExport.SetRandomSeed = SetRandomSeed;

	return &misnExport;
}