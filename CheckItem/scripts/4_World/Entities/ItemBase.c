modded class ItemBase
{
	int ListAllMyItems(ItemBase myitem)
	{
		array<EntityAI> itemsArray = new array<EntityAI>;
		array<string> FodsArray = new array<string>;
		ItemBase item;
		GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
		int count = itemsArray.Count();

		
		for (int i = 0; i < itemsArray.Count(); i++)
		{
			Class.CastTo(item, itemsArray.Get(i));
			
			if (item  &&  !item.IsInherited(Container_Base))	
			{
				if(item.ToString().Contains("CodeLock") )
				{
				}
				else
				{
				FodsArray.Insert(item.ToString());
				}
			}
		}
	return FodsArray.Count();	

	}





}