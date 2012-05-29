#include "include_and_defines.h"

int main () {
	int mh=5, mw1=10, mw2=30, inc=1; // mh=menu_height, mw=menu_width 1-name 2-variables, inc-lines_increaser
	int i, key=' ', menu=1, menuX=0, hours=1; // obsluga menu
	double prod[RES]={}, usage[RES]={}; // tablice przechowujace produkcje i zuzycie poszczegolnych surowcow
  int recalculate=1; // zmienna decydujaca czy ponowic obliczenia ilosci surowcow
  
  init_ncurses();
  initialize_structs();
	
	while(key!='k')
	{
    // obliczanie wydobycia i uzycia surowcow
    if(recalculate==1)
    {
      recalculate_production(5, prod, usage); recalculate=0;
    }
    
    // wyswietlenie menu
    clear();
    show_menu(prod, usage, hours, menu, menuX);
    refresh();
    
    // pobranie klawisza i wykonanie akcji
    key=getch();
    switch(key)
    {
      case KEY_UP:
        menu--;
        if(menu<1) menu=RES;
        break;
      case KEY_DOWN:
        menu++;
        if(menu>RES) menu=1;
        break;
      case KEY_LEFT:
        menuX--;
        if(menuX<0) menuX=2;
        break;
      case KEY_RIGHT:
        menuX++;
        if(menuX>2) menuX=0;
        break;
      case 'h':
        hours--;
        if(hours<1) hours=24;
        break;
      case 'j':
        hours++;
        if(hours>24) hours=1;
        break;
    }
  }
  
  // zwolnienie pamieci struktur i okien
	free_and_exit();
	return 0;
}
