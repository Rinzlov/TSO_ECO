void free_and_exit()
{
  erase();
	refresh();
	endwin();
	free(my_b);
	free(tmp);
	free(buff);
}
