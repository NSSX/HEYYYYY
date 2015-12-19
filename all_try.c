#include "fillit.h"

int try_1(char *chaine)
{
  int i;

  i = 0;
  while(chaine[i] != '\0')
    {
      if(chaine[i] != '.' && chaine[i] != '#' && chaine[i] != '\n')
	return (0);
      i++;
    }
  return (1);
}

int try_2(char *chaine, int count, int time, int i)
{
  while(chaine[i] != '\0')
    {
      while(time < 4)
	{
	  while(chaine[i] != '\n')
	    {
	      if(chaine[i] == '.' || chaine[i] == '#')
		count++;
	      i++;
	    }
	  if(count != 4)
	    return (0);
	  count = 0;
	  i++;
	  time++;
	}
      time = 0;
      if(chaine[i] == '\0')
	return (1);
      i++;
    }
  return (0);
}

int try_3(char *chaine, int count, int time, int i)
{
  while(chaine[i] != '\0')
    {
      while(time < 4)
	{
	  while(chaine[i] != '\n')
	    {
	      if(chaine[i] == '#')
		count++;
	      i++;
	    }
	  i++;
	  time++;
	}
      if(count != 4)
	return (0);
      if(chaine[i] == '\0')
	return (1);
      count = 0;
      time = 0;
      i++;
    }
  return (1);
}

int all_try(char *chaine)
{
  if(try_1(chaine) && try_2(chaine, 0, 0, 0)
	&& try_3(chaine, 0, 0, 0))
    return (1);
  return (0);
}
