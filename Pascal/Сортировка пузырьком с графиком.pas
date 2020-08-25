program BublSortGraph;

uses
  GraphABC;
  
const
  M = 100;
  
var
  r, k, x, y : integer;
  arr, arrF : array [1..M] of integer;
  
//Процедура для вывода фонового массива
procedure Fon();
begin
  SetPenColor(clGreen);
  SetBrushColor(clLightGray);
  x := WindowWidth div 50;
  y := WindowHeight-150;
  
  for var i := 1 to m do
  begin
    //Выводим столбики фонового массива
    x := x+6;
    Rectangle(x, y, x+4, y-arrF[i]*(y-5) div 1000);
    
    //Выводим числа фонового массива
    SetBrushColor(clWhite);
    SetFontColor(clGreen);
    TextOut(x-8, y+((i-1) mod 5)*14+75, arrF[i]);
    SetBrushColor(clLightGray);
  end;
end;

Begin  
  //Заполняем массив случайными числами
  Randomize;
  for var i := 1 to m do arr[i] := random(0, 999);
  
  //Выводим график случайного массива
  SetPenColor(clBlack);
  SetBrushColor(clBlue);
  x := WindowWidth div 50;
  y := WindowHeight-150;
  
  for var i := 1 to m do
  begin
    //Выводим столбики случайного массива
    x := x+6;
    Rectangle(x, y, x+4, y-arr[i]*(y-5) div 1000);
    
    //Выводим числа случайного массива
    SetBrushColor(clWhite);
    TextOut(x-8, y+((i-1) mod 5)*14, arr[i]);
    SetBrushColor(clBlue);
    Sleep(20);
  end;
  
  Sleep(500);
  
  //Сохраняем копию случайного массива
  arrF := arr;
  Fon();
  Sleep(500);
  
  //Сортировка массива
  k := M;
  for var j := 1 to k do
  begin
    
    LockDrawing;
    ClearWindow;
    
    Fon();
    
    //Выводим график сортируемого массива
    SetPenColor(clBlack);
    SetBrushColor(clBlue);
    SetFontColor(clBlack);
    x := WindowWidth div 50-1;
    y := WindowHeight-150+1;
    
    for var i := 1 to m do
    begin
      //Выводим столбики сортируемого массива
      x := x+6;
      Rectangle(x, y, x+4, y-arr[i]*(y-5) div 1000);
      
      //Выводим числа сортируемого массива
      SetBrushColor(clWhite);
      TextOut(x-8, y+((i-1) mod 5)*14, arr[i]);
      SetBrushColor(clBlue);
    end;
    
    //Алгоритм сортировки
    k := k-1;
    for var i := 1 to k do
    begin
      if arr[i] > arr[i+1] then
      begin
        r := arr[i];
        arr[i] := arr[i+1];
        arr[i+1] := r;
      end;
    end;
    
    //Таймер отрисовки
    Sleep(200);
    Redraw;
    
  end;
end.