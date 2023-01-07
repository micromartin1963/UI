modded class MissionGameplay
{	

    private ref CheckItem instance;











    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);
        Input input = GetGame().GetInput();



        if ( input.LocalPress("UAOpenTest", false) ) {
	Print("Pressed G xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

         //   LockControls();
        instance = CheckItem.Cast(GetUIManager().EnterScriptedMenu(TEST_MENU, null));
        instance.SetMenuOpen(true);
            
        }

 
    }
	

}