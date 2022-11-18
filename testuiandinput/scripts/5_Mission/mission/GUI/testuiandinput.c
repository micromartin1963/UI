class testuiandinput extends UIScriptedMenu
{

    private bool m_Initialized = false;
    private bool m_IsMenuOpen;

    MultilineTextWidget m_InfoBox;
    ButtonWidget m_Btnenable;
	ButtonWidget m_Btndisable;
	ButtonWidget m_BtnCancel;



	bool m_active = false;




	void testuiandinput()
	{		

	}	
	
	void ~testuiandinput()
	{
        GetGame().GetUIManager().Back();
        g_Game.GetUIManager().ShowCursor(true);
        g_Game.GetUIManager().ShowUICursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetMission().GetHud().Show( true );


	}

    override Widget Init()
    {

	layoutRoot = GetGame().GetWorkspace().CreateWidgets( "TestUiAndInput/GUI/layouts/testuiandinput.layout" );
        m_Btnenable = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_enable" ) );
	m_Btndisable = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_disable" ) );
	m_BtnCancel = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_cancel" ) );


	m_active = true;
		
        return layoutRoot;
    }
	



	override void Update(float timeslice)
	{
	super.Update(timeslice);

        autoptr Widget underCursor = GetWidgetUnderCursor();
        if (underCursor == null) return;


		if (!m_active)
		GetGame().GetUIManager().Back();
	}


	override void OnShow()
	{
		super.OnShow();

//		//PPEffects.SetBlurMenu(0.5);

		GetGame().GetInput().ChangeGameFocus(1);

		SetFocus( layoutRoot );
	}

	override void OnHide()
	{
		super.OnHide();

		PPEffects.SetBlurMenu(0);

		GetGame().GetInput().ResetGameFocus();

		Close();
	}


	override bool OnClick( Widget w, int x, int y, int button )
	{
		super.OnClick(w, x, y, button);

		PlayerBase m_Player = g_Game.GetPlayer();
		

		
		if ( w == m_Btnenable )
		{
		Print("Pressed enable");

		}
		
		if ( w == m_Btndisable )
		{

			Print("Pressed disable");
			return true;
		}
		
		if ( w == m_BtnCancel )
		{
			GetGame().GetUIManager().Back();

			return true;
		}
		


		return false;
	}
	
//	override bool OnChange( Widget w, int x, int y, bool finished )
//	{
//		super.OnChange(w, x, y, finished);
//
//
//	}
	


    void SetMenuOpen(bool isMenuOpen) {
      //  m_IsMenuOpen = isMenuOpen;
      //  if (m_IsMenuOpen)
         //   PPEffects.SetBlurMenu( 0.5 );
       // else
        //    PPEffects.SetBlurMenu( 0 );
    }


}