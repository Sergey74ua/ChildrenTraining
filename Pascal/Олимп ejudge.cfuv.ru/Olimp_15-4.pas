program p;

var N, i, j : integer;
  arr1 : array of array of char;
  arr2 : array of array of char;

begin
  readln(N);
  setLength(arr1, N);
  for i := 0 to N-1 do
    setLength(arr[i], N);
  setLength(arr2, N);
  for i := 0 to N-1 do
    setLength(arr2[i], N);

  for i := 0 to N-1 do
  begin
    for j := 0 to N-1 do
      read(arr[i, j]);
    readln();
  end;
  
  for i := 0 to N-1 do
    for j := 0 to N-1 do
      if (arr1[i, j] = 'o') then
        
  //решение
  
  for i := 0 to N-1 do
  begin
    for j := 0 to N-1 do
      write(arr2[i, j]);
    writeln();
  end;
end.