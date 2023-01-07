class testuiandinput extends UIScriptedMenu
{


    private bool m_Initialized = false;
    private bool m_IsMenuOpen;

    MultilineTextWidget m_InfoBox;
    ButtonWidget m_Btnenable;
	ButtonWidget m_Btndisable;
	ButtonWidget m_BtnCancel;
	protected TextWidget m_TextCenter;



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
	m_TextCenter = TextWidget.Cast(layoutRoot.FindAnyWidget("TextCenter"));
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

		//PPEffects.SetBlurMenu(0.5);
		

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
		m_TextCenter.SetText(CountItems().ToString());
		//m_TextCenter.SetText("Items Counted =");
		}
		
		if ( w == m_Btndisable )
		{
		m_TextCenter.SetText("disable");
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
	

	


    void SetMenuOpen(bool isMenuOpen) {
      //  m_IsMenuOpen = isMenuOpen;
      //  if (m_IsMenuOpen)
         //   PPEffects.SetBlurMenu( 0.5 );
       // else
        //    PPEffects.SetBlurMenu( 0 );
    }


	
	int CountItems() 
	{
	int items = 0;
	int itemsTotal = 0;
	int builderitems = 0;
	string tmp ;
        Building building;
	ItemBase m_items;
	Inventory_Base IvItems;
	Container_Base ContainerItems;
	CargoBase cargo; 
	EntityAI Ent_Ai;



		ref array<Object> objects = new array<Object>;

		GetGame().GetObjectsAtPosition3D(GetGame().GetPlayer().GetPosition(), 15, objects, NULL);
		for (int i = 0; i < objects.Count(); i++) 
		{

			//Class.CastTo(ContainerItems, objects.Get(i));
			//if(!ContainerItems)
			//{
			//items++;
			//}

			Class.CastTo(m_items, objects.Get(i));
			if(m_items)
			{
			items = m_items.ListAllMyItems(m_items);
			itemsTotal = itemsTotal + items;
			//items++;
			}
		

			//Class.CastTo(IvItems, objects.Get(i));
			//if(IvItems)
			//{
			//items++;
			//}

			//Class.CastTo(Ent_Ai, objects.Get(i));
			//if(Ent_Ai)
			//{
			//items++;
			//}


		}

		return itemsTotal;

		
	}







}