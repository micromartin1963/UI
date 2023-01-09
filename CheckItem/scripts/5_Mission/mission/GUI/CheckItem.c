class CheckItem extends UIScriptedMenu
{
    	private bool m_Initialized = false;
  	private bool m_IsMenuOpen;
	int builderitems = 0;
	int CodeLocks = 0;
	int range = 15;
   	MultilineTextWidget m_InfoBox;
  	ButtonWidget m_Btnenable;
	ButtonWidget m_Btndisable;
	ButtonWidget m_BtnCancel;
	protected TextWidget m_TextCenter;
	protected TextWidget m_TextMoreInfo;
	protected TextWidget m_Range01;
	protected TextWidget m_Range02;
	protected TextWidget m_Range03;	
	protected CheckBoxWidget m_CheckBox15mtr;
	protected CheckBoxWidget m_CheckBox25mtr;
	protected CheckBoxWidget m_CheckBox35mtr;

	bool m_active = false;
	bool uncheck = false;

	void CheckItem()
	{		

	}	
	
	void ~CheckItem()
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

	layoutRoot = GetGame().GetWorkspace().CreateWidgets( "FOG/CheckItem/GUI/layouts/CheckItem.layout" );
	m_TextCenter = TextWidget.Cast(layoutRoot.FindAnyWidget("TextCenter"));
        m_Btnenable = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_enable" ) );
	m_Btndisable = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_disable" ) );
	m_BtnCancel = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_cancel" ) );
	m_TextMoreInfo = TextWidget.Cast(layoutRoot.FindAnyWidget("MoreInfo"));
	m_CheckBox15mtr = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("CheckBox15mtr"));
	m_CheckBox25mtr = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("CheckBox25mtr"));
	m_CheckBox35mtr = CheckBoxWidget.Cast(layoutRoot.FindAnyWidget("CheckBox35mtr"));
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
		m_CheckBox15mtr.SetChecked(true);
		m_CheckBox15mtr.Enable(false);
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
		m_TextCenter.SetText("Items in containers : " + CountItems().ToString());
		m_TextMoreInfo.SetText("Building items : " + builderitems.ToString() );
		}
		
		if ( w == m_CheckBox15mtr )
		{
		range = 15;
		m_CheckBox15mtr.Enable(false);
		m_CheckBox25mtr.Enable(true);
		m_CheckBox35mtr.Enable(true);
		m_CheckBox25mtr.SetChecked(false);
		m_CheckBox35mtr.SetChecked(false);
			return true;
		}

		if ( w == m_CheckBox25mtr )
		{
		range = 25;
		m_CheckBox25mtr.Enable(false);
		m_CheckBox15mtr.Enable(true);
		m_CheckBox35mtr.Enable(true);
		m_CheckBox15mtr.SetChecked(false);
		m_CheckBox35mtr.SetChecked(false);
			return true;
		}

		if ( w == m_CheckBox35mtr )
		{
		range = 35;
		m_CheckBox35mtr.Enable(false);
		m_CheckBox25mtr.Enable(true);
		m_CheckBox15mtr.Enable(true);
		m_CheckBox25mtr.SetChecked(false);
		m_CheckBox15mtr.SetChecked(false);
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
	int v_items = 0;
	int v_itemsTotal = 0;
	ItemBase m_items;
	builderitems = 0;

		ref array<Object> objects = new array<Object>;

		GetGame().GetObjectsAtPosition3D(GetGame().GetPlayer().GetPosition(), range, objects, NULL);
		for (int i = 0; i < objects.Count(); i++) 
		{
			Class.CastTo(m_items, objects.Get(i));
			if(m_items)
			{
			items = m_items.ListAllMyItems(m_items);
			itemsTotal = itemsTotal + items;
			//items++;
			if(m_items.ToString().Contains("wall") )builderitems ++;
			if(m_items.ToString().Contains("Wall") )builderitems ++;
			if(m_items.ToString().Contains("floor") )builderitems ++;
			if(m_items.ToString().Contains("Floor") )builderitems ++;
			if(m_items.ToString().Contains("roof") )builderitems ++;
			if(m_items.ToString().Contains("Roof") )builderitems ++;
			if(m_items.ToString().Contains("door") )builderitems ++;
			if(m_items.ToString().Contains("Door") )builderitems ++;
			if(m_items.ToString().Contains("flag") )builderitems ++;
			if(m_items.ToString().Contains("Flag") )builderitems ++;
			if(m_items.ToString().Contains("lock") )builderitems ++;
			if(m_items.ToString().Contains("CodeLock") )CodeLocks ++;
			}
		}

		return itemsTotal - builderitems - CodeLocks;
		
	}



	int Count_V_Items() 
	{
	int vitemsTotal = 0;
	CargoBase myCargo;

		ref array<Object> objects = new array<Object>;

		GetGame().GetObjectsAtPosition3D(GetGame().GetPlayer().GetPosition(), range, objects, NULL);
		for (int i = 0; i < objects.Count(); i++) 
		{
			Class.CastTo(myCargo, objects.Get(i));
			if(myCargo)
			{
			vitemsTotal = myCargo.GetItemCount();
			}


		}

		return vitemsTotal ;		
	}






}