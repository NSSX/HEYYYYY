#include <stdio.h>
int *go_rightz(char *chaine, char *piece, int chainei, int piecei, int *count, int length);
int *go_downz(char *chaine, char *piece, int chainei, int piecei, int *count, int length);
int *go_upz(char *chaine, char *piece, int chainei, int piecei, int *count, int length);
int *go_leftz(char *chaine, char *piece, int chainei, int piecei, int *count, int length);

int *zone(char *chaine, int chainei, int *count, int length)
{
  if(chaine[chainei + 1] >= 'A' && chaine[chainei + 1] <= 'Z')
    {
      count[0]++;
    }
  if(chaine[chainei + length] >= 'A' && chaine[chainei + length] <= 'Z')
    {
      count[0]++;
    }
  if(chaine[chainei - length] >= 'A' && chaine[chainei - length] <= 'Z')
    {
      count[0]++;
    }
  if(chaine[chainei - 1] >= 'A' && chaine[chainei - 1] <= 'Z')
    {
      count[0]++;
    }
  return (count);
}

int *go_rightz(char *chaine, char *piece, int chainei, int piecei, int *count, int length)
{
  count[1]++;
  if(count[1] < 4)
    {
  piece[piecei] = 'x';
  piecei = piecei + 1;
  chainei = chainei + 1;
  count = zone(chaine, chainei, count, length);
  if(piece[piecei + 1] == '#' && chaine[chainei + 1] == '.')
    {
      count = go_rightz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei + 5] == '#' && chaine[chainei + length] == '.')
    {
      count = go_downz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei - 5] == '#' && chaine[chainei - length] == '.')
    {
      count = go_upz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei - 1] == '#' && chaine[chainei - 1] == '.')
    {
      count = go_leftz(chaine, piece, chainei, piecei, count, length);
    }
    }
  return (count);
}
int *go_downz(char *chaine, char *piece, int chainei, int piecei, int *count, int length)
{
  count[1]++;

  if(count[1] < 4)
    {
  piece[piecei] = 'x';
  piecei = piecei + 5;
  chainei = chainei + length;
  count = zone(chaine, chainei, count, length);
  if(piece[piecei + 1] == '#' && chaine[chainei + 1] == '.')
    {
      count = go_rightz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei + 5] == '#' && chaine[chainei + length] == '.')
    {
      count = go_downz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei - 5] == '#' && chaine[chainei - length] == '.')
    {
      count = go_upz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei - 1] == '#' && chaine[chainei - 1] == '.')
    {
      count = go_leftz(chaine, piece, chainei, piecei, count, length);
    }
    }
  return (count);
}

int *go_upz(char *chaine, char *piece, int chainei, int piecei, int *count, int length)
{
  count[1]++;

  if(count[1] < 4)
    {
  piece[piecei] = 'x';
  piecei = piecei - 5;
  chainei = chainei - length;
  count = zone(chaine, chainei, count, length);
  if(piece[piecei + 1] == '#' && chaine[chainei + 1] == '.')
    {
      count = go_rightz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei + 5] == '#' && chaine[chainei + length] == '.')
    {
      count = go_downz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei - 5] == '#' && chaine[chainei - length] == '.')
    {
      count = go_upz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei - 1] == '#' && chaine[chainei - 1] == '.')
    {
      count = go_leftz(chaine, piece, chainei, piecei, count, length);
    }
    }
  return (count);
}

int *go_leftz(char *chaine, char *piece, int chainei, int piecei, int *count, int length)
{
  count[1]++;

  if(count[1] < 4)
    {
  piece[piecei] = 'x';
  piecei = piecei - 1;
  chainei = chainei - 1;
  count = zone(chaine, chainei, count, length);
  if(piece[piecei + 1] == '#' && chaine[chainei + 1] == '.')
    {
      count = go_rightz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei + 5] == '#' && chaine[chainei + length] == '.')
    {
      count = go_downz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei - 5] == '#' && chaine[chainei - length] == '.')
    {
      count = go_upz(chaine, piece, chainei, piecei, count, length);
    }
  if(piece[piecei - 1] == '#' && chaine[chainei - 1] == '.')
    {
      count = go_leftz(chaine, piece, chainei, piecei, count, length);
    }
    }
  return (count);
}
