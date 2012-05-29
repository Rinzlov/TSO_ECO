struct b_types{
  char name[10];
  int base_time_min;
  int base_time_s;
  char res_name[10];
  char need1_name[10];
  int need1;
  char need2_name[10];
  int need2;
};
struct b_types building[40];

struct resources{
  int nr;
  char name[10];
} resource[40];

struct my_b{
  int nr;
  int lvl;
  int buff;
  int min;
  int s;
};
struct my_b my_buildings[400];
  
void color(int Y, int X, int menu, int menuX)
{
  if(menu==Y && menuX==X) attrset(COLOR_PAIR(1));
      else attrset(COLOR_PAIR(0));
}
