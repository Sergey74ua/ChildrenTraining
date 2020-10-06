program p;
var T, N, i, j, max, test : integer;
    arr : array of integer;
    msg : string;
begin
  readln(T);
  setLength(arr, T);
  
  for i:=0 to T-1 do
    readln(arr[i]);
  
  for i:=0 to T-1 do
  begin
    msg:='NO';
    for j:=1 to trunc(sqrt(arr[i])) do
    begin
      test:=arr[i]-j*j;
      if (test>0) and (frac(sqrt(test))=0) then
      begin
        msg:='YES';
        break;
      end;
    end;
    writeln(msg);
  end;
end.