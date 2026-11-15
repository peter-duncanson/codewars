#include <stdbool.h>
#include <stdlib.h>
//--------------------------------------------------------------------------------------------------
bool ValidPos(const short pos[2])
{
  return ((0 <= pos[0]) && (pos[0] < 8) && (0 <= pos[1]) && (pos[1] < 8));
}
//--------------------------------------------------------------------------------------------------
bool KnightImpl(const short start[2], const short end[2], short steps2go)
{
  if (!ValidPos(start) || !ValidPos(end) || (steps2go < 0))
    return false;
  
  if ((start[0] == end[0]) && (start[1] == end[1]))
    return true;
    
  static dir[8][2] = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };
  for (unsigned short i = 0; i < 8; ++i)
  {
    short new_start[2] = { start[0] + dir[i][0], start[1] + dir[i][1] };
    bool res = KnightImpl(new_start, end, steps2go-1);
    if (res == true)
      return true;
  }
  
  return false;
}
//--------------------------------------------------------------------------------------------------
short knight(const char *p1, const char *p2) 
{
  short start[2] = { p1[0]-'a',p1[1]-'1' };
  short end[2] = { p2[0]-'a',p2[1]-'1' };
  
  if (!ValidPos(start) || !ValidPos(end))
    return -1;

  for (short i = 0; ; ++i)
  {
    bool res = KnightImpl(start, end, i);
    if (res == true)
      return i;
  }
}

