program p;

var N, S, i, j : integer;
  arr1 : array of array of char;
  arr2 : array of array of char;

begin
  readln(N);
  setLength(arr1, N+2);
  for i := 0 to N+1 do
    setLength(arr1[i], N+2);
  setLength(arr2, N);
  for i := 0 to N-1 do
    setLength(arr2[i], N);

  for i := 1 to N do
  begin
    for j := 1 to N do
      read(arr1[i, j]);
    readln();
  end;
  
  for i := 1 to N-1 do
    for j := 1 to N-1 do
    begin
      S := 0;
      if arr1[i - 1, j - 1] = 'o' then S := S + 1;
      if arr1[i - 1, j] = 'o' then S := S + 1;
      if arr1[i - 1, j + 1] = 'o' then S := S + 1;
      if arr1[i, j - 1] = 'o' then S := S + 1;
      if arr1[i, j + 1] = 'o' then S := S + 1;
      if arr1[i + 1, j - 1] = 'o' then S := S + 1;
      if arr1[i + 1, j] = 'o' then S := S + 1;
      if arr1[i + 1, j + 1] = 'o' then S := S + 1;
      
      if (arr1[i, j] = '.') and (S = 3) then
        arr2[i-1, j-1] := 'o'
      else if (arr1[i, j] = 'o') and (S < 2) and (S > 3) then
        arr2[i-1, j-1] := '.'
      else
        arr2[i-1, j-1] := '.';
    end;
    
  for i := 0 to N-1 do
  begin
    for j := 0 to N-1 do
      write(arr2[i, j]);
    writeln();
  end;
end.