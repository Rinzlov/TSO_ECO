void color(int Y, int X, int menu, int menuX)
{
  if(menu==Y && menuX==X) attrset(COLOR_PAIR(1));
      else attrset(COLOR_PAIR(0));
}

void show_menu(double prod[RES], double usage[RES], int hours, int menu, int menuX)
{
  int w1=4, w2=w1+19, w3=w2+15, w4=w3+13;
  int i;
  mvprintw(1,w1,"k-exit h,j-hours +/-");
  mvprintw(2,w1,"Hours: %i", hours);
    
  mvprintw(3, w1, "Resource");
  mvprintw(3, w2+1, "Remains");
  mvprintw(3, w3-2, "Production");
  mvprintw(3, w4+2, "Needed");
  // wypisanie surowców  
  for(i=1;i<RES ;i++)
  {
    // nazwa i surowce pozostale
    color(i, 0, menu, menuX);
    mvprintw(4+i, w1, "%s", resource[i].name);
    mvprintw(4+i, w2, "%8.2f", (prod[i]-usage[i])*hours);
    mvprintw(4+i, w2+9, "=");
    // ilosc wyprodukowanych surowcow
    color(i, 1, menu, menuX);
    mvprintw(4+i, w3, "%8.2f", prod[i]*hours);
      
    // zu¿ycie surowcow
    mvprintw(4+i, w4-3, "-");
    color(i, 2, menu, menuX);
    mvprintw(4+i, w4, "%8.2f", usage[i]*hours);
      
    attrset(COLOR_PAIR(0));
  }
}
