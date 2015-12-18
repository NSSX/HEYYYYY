void ft_erase(char *chaine, char carac)
{
  int i;

  i = 0;
  while(chaine[i] != '\0')
    {
      if(chaine[i] == carac)
	chaine[i] == '.';
      i++;
    }
}


int backtrack(int iprec, char *chaine, char *piece, char carac, int length, int chainei)
{
  int piecei;

  piecei = first_di(tab[tetri]);
  while(!try(ft_strdup(chaine), ft_strdup(tab[tetri]), chainei, piecei,length) && chaine[chainei] != '\0')
  {
    chainei++;
  }
 if(try(chaine, ft_strdup(tab[tetri]), chainei, piecei,length))
    {
      if(tetri + 1 == nb_piece(piece))
	return (0);
      chaine = trans_di(chaine, carac);
      backtrack(chainei, chaine, tetri++, carac++,length,0);
    }
  else
    {
      ft_erase(chaine, carac--);
      backtrack(0, chaine, --tetri, --carac,length,iprec + 1);
    }
  return (0);
}


a = 1;

terrain = malloc(sizof(a + 1));

a = a + 1;
