using System;

public class Kata
{
  public static bool IsIsogram(string str) 
  {
    byte test;
    str = str.ToLower();
    
    foreach(char i in str)
    {
      test = 0;
      foreach(char j in str)
        if (i == j)
            test++;
      if(test > 1)
        return false;
    }
    return true;
  }
}