modded class MissionGameplay
{	

    private ref testuiandinput instance;

//	override void OnInit()
//  	{

//		super.OnInit();
//	}
	
//	override void TickScheduler(float timeslice)
//	{
//		super.TickScheduler(timeslice);
			
		
//	}




//    override void OnKeyPress(int key) 
//    {
//		if ( key == KeyCode.KC_G )
//		{	
//		Print("Pressed G xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");	
//		}

//Print("In OnKey but not picking up G xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
//        super.OnKeyPress(key);
//    }




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