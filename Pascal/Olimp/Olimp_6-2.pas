program p;
var
  x : longint;
  dig : array [1..20] of integer;
  n, i, j, tmp : integer;

Begin
    readln(x);
    
    n := 0;
    while x > 0 do
    begin
      dig[n+1] := x mod 10;
      x := x div 10;
      n := n + 1;
    end;
    
    for i := 1 to n-1 do
    begin
      for j := i + 1 to n do
      begin
        if dig[j] > dig[i] then
        begin
          tmp := dig[i];
          dig[i] := dig[j];
          dig[j] := tmp;
        end;
      end;
    end;

    for i := 1 to n do
		write(dig[i]);
end.