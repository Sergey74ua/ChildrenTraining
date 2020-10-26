program p;

var d : word;
    i, temp : byte;
    arr : array [1..4] of byte;

begin
  readln(d);
  
  for i := 1 to 4 do
  begin
    arr[i] := d mod 10;
    d := d div 10;
  end;
  
  for i := 1 to 4 do
    arr[i] := (arr[i] + 7) mod 10;
  
  temp := arr[1];
  arr[1]:= arr[2];
  arr[2] := temp;
  temp := arr[3];
  arr[3]:= arr[4];
  arr[4] := temp;
  
  for i := 1 to 4 do
    write(arr[i]);
  
end.