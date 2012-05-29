void init_ncurses()
{
  initscr ();
	cbreak ();
	noecho ();
	start_color ();
	keypad (stdscr, TRUE);
	curs_set(0);
	
	init_pair (1, COLOR_GREEN, COLOR_BLACK);
	init_pair (0, COLOR_WHITE, COLOR_BLACK);
}
