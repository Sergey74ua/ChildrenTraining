program p;

var
  arr : array of integer;
  x, l, tmp, i, j: integer;

Begin
    readln(x);
    
    l := 0;
    tmp := x;
    while tmp > 0 do
    begin
      tmp := tmp div 10;
      if tmp < 0 then
        break
      else
        l := l + 1;
    end;
    
    setLength(arr, l);
    
    for i := 0 to l-1 do
    begin
      arr[i] := x mod 10;
      x := x div 10;
    end;
    
    for i := 0 to l-1 do
    begin
      for j := i + 1 to l-1 do
      begin
        if arr[j] > arr[i] then
        begin
          tmp := arr[i];
          arr[i] := arr[j];
          arr[j] := tmp;
        end;
      end;
    end;

    for i := 0 to l-1 do
    begin
      x := x * 10 + arr[i];
    end;
    
    write(x);
end.