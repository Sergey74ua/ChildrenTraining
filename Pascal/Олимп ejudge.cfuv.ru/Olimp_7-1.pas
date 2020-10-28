program p;

var N, A, i : integer;
    arr : array of integer;

begin
  read(N);
  setLength(arr, N);
  
  for i := 0 to N-1 do
  begin
    read(A);
    if (A <= 100) or ((A - 100) mod 7 <> 0) then
        arr[i] := -1
    else
        arr[i] := ((A - 100) div 7);
  end;
  
  for i := 0 to N-1 do
    writeln(arr[i]);
end.