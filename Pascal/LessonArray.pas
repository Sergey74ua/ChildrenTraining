Program Urok;

var StatArr : array [0..5] of integer;
    DynArr  : array of integer;

Begin
  SetLength(DynArr, 10);
  
  StatArr[0] := 111;
  write(StatArr[0]);
  writeln();
  DynArr[3] := 222;
  
  for var i := 0 to High(StatArr) do
    StatArr[i] := i*i;
  
  write(StatArr);
  writeln();
  
  for var i := 0 to DynArr.Length-1 do
    DynArr[i] := i*i;
  
  write(DynArr);
end.