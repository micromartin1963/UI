modded class MissionBase {
    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = NULL;
        menu = super.CreateScriptedMenu(id);
        if (!menu) {
            switch (id) {
            case TEST_MENU:
                menu = new CheckItem;
                break;
            }
            if (menu) {
                menu.SetID(id);
            }
        }
        return menu;
    }
}