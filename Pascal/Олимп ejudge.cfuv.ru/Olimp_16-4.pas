program p;
var N, S, i, j : integer;
  arr : array of array of integer;
  arrI : array of integer;
begin
  readln(N);
  setLength(arr, N);
    for i := 0 to N-1 do
      SetLength(arr[i], N);
  setLength(arrI, N);

  for i := 0 to N-1 do
  begin
    for j := 0 to N-1 do
      read(arr[i, j]);
    readln();
  end;
  
  for i := 0 to N-1 do
    for j := 0 to N-1 do
      if (arr[i, j] > 0) and then
        S := S + arr[i, j];
  //решение
  
  for i := 0 to N-1 do
  begin
    for j := 0 to N-1 do
      write(arr[i, j], ' ');
    writeln();
  end;
end.