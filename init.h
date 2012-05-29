struct b_types{
  int prod_res_nr;
  int need1_nr;
  int need1;
  int need2_nr;
  int need2;
  //
  char name[18];
  int base_time_min;
  int base_time_s;
};
struct b_types building[40];

struct resources{
  char name[18];
} resource[RES+1];

struct my_buildings{
  int type;
  int lvl;
  int buff;
  int min;
  int s;
};
struct my_buildings *my_b;
struct my_buildings *buff;
struct my_buildings *tmp;

double hourly(int min, int s)
{
  double perH;
  perH=3600.0/(min*60+s);
  return perH;
}

set_my_b(int nr, int type, int lvl, int buff, int min, int s)
{
  my_b[nr].type=type;
  my_b[nr].lvl=lvl;
  my_b[nr].buff=buff;
  my_b[nr].min=min;
  my_b[nr].s=s;
}

void set_b_type(int nr, int prod_res_nr, int need1_nr, int need1, int need2_nr, int need2)
{
  building[nr].prod_res_nr=prod_res_nr;
  building[nr].need1_nr=need1_nr;
  building[nr].need1=need1;
  building[nr].need2_nr=need2_nr;
  building[nr].need2=need2;
}
void initialize_structs()
{
  // inicjalizacja wszystkich struktur
  my_b=calloc(4, sizeof(*tmp));
  //strcpy(building.name, ""
  //building[0].name=coinage
  //building[0].need1_nr=1; building[0].need1=4;
  //       nr|prod|nr1|v|nr2|v
  set_b_type(1, 1, 2, 4, 0, 0); // coinage
  set_b_type(2, 2, 3, 2, 4, 8); // gold smelter
  //     nr|type|lvl|buff|min|s
  set_my_b(1, 1, 1, 1, 24, 0);
  set_my_b(2, 1, 1, 1, 24, 35);
  set_my_b(3, 2, 5, 1, 13, 7);
  
  if( (buff = realloc(my_b, 6 * sizeof(*tmp))) == NULL )
  {
    printf("Memory reallocating error.\n");
    system("pause");
  }
  else
  {
    my_b = buff;
  }

  set_my_b(4, 2, 5, 1, 12, 0);
  set_my_b(5, 2, 5, 1, 12, 0);
  //for(i=0;i<20;i++)
  //{set_my_b(6+i, 2, 5, 1, 12, 0);}
  
  strcpy(resource[0].name, " ");
  strcpy(resource[1].name, "gold coins");
  strcpy(resource[2].name, "gold bars");
  strcpy(resource[3].name, "gold ore");
  strcpy(resource[4].name, "coal");
  strcpy(resource[5].name, "ewp");
  strcpy(resource[6].name, "steel swords");
  strcpy(resource[7].name, "steel");
  strcpy(resource[8].name, "bronze swords");
  strcpy(resource[9].name, "bronze");
}
