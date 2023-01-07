modded class MissionGameplay
{	

    private ref testuiandinput instance;











    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);
        Input input = GetGame().GetInput();



        if ( input.LocalPress("UAOpenTest", false) ) {
	Print("Pressed G xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

         //   LockControls();
        instance = testuiandinput.Cast(GetUIManager().EnterScriptedMenu(TEST_MENU, null));
        instance.SetMenuOpen(true);
            
        }

 
    }
	

}