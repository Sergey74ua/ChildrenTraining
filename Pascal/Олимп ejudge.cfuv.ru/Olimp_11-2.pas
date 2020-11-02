program p;

var N, i, temp : word;
    arr : array of word;

begin
  read(N);
  setLength(arr, N);
  
  for i := 0 to N-1 do
  begin
    readln(temp);
    if temp = 0 then
      arr[i] := 2
    else
      arr[i] := temp - 1;
  end;
  
  for i := 0 to N-1 do
    writeln(arr[i]);
end.