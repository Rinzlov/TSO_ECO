void recalculate_production(int nr, double prod[RES], double usage[RES])
{
  int i;
  for(i=1; i<=nr; i++)
  {
    // dodanie odpowiedniej ilosci surowcow na godzine do wlasciwej komorki tabeli
    prod[building[my_b[i].type].prod_res_nr]+=hourly(my_b[i].min, my_b[i].s)*my_b[i].buff*my_b[i].lvl;
    // jezeli jeden lub dwa surowce sa potrzebne do produkcji - odejmuje odpowiednia ilosc z wlasciwej komorki z tabeli
    if(building[my_b[i].type].need1_nr!=0)
    {
      usage[building[my_b[i].type].need1_nr]+=hourly(my_b[i].min, my_b[i].s)*building[my_b[i].type].need1*my_b[i].lvl;
    }
    if(building[my_b[i].type].need2_nr!=0)
    {
      usage[building[my_b[i].type].need2_nr]+=hourly(my_b[i].min, my_b[i].s)*building[my_b[i].type].need2*my_b[i].lvl;
    }
  }
}
