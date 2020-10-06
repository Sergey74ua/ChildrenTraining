program BublSort;
const
  M = 10;
var
  e, r, k: integer;
  str: string;
  arr: array [1..M] of integer;

//Функция вывода массива на экран
procedure Print();
begin
  e := 0;
  for var i := 1 to M do
  begin
    //Добавляем пробелы для равномерности
    if arr[i] < 10 then str := '    '
    else if arr[i] < 100 then str := '   '
    else if arr[i] < 1000 then str := '  '
    else str := ' ';
    write(str, arr[i]);
    
    //Переход на новую строку
    e := e + 1;
    if e >= 16 then
    begin
      e := 0;
      writeln;
    end;
  end;
  writeln; writeln;
end;

begin
  //Заполняем массив случайными числами
  Randomize;
  for var i := 1 to m do arr[i] := random(0, 999);
  Print();
  
  //Сортировка массива
  k := M;
  for var j := 1 to M-1 do 
  begin
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
  end;
  
  Print();
end.