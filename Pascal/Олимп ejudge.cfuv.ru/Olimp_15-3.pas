program p;

var
    T, N, i, j, max, test : integer;
    arr : array of integer;
    arrS : array of string;

begin
    readln(T);
    setLength(arr, T);
    setLength(arrS, T);
    
    for i:=0 to T-1 do
    begin
      readln(N);
      arr[i]:=N;
    end;
    
    for i:=0 to T-1 do
    begin
        max:=trunc(sqrt(arr[i]));
        for j:=1 to max do
        begin
          test:=arr[i]-j*j;
          if (test>0) and (frac(sqrt(test))=0) then
            begin
              arrS[i] := 'YES';
              break;
            end
          else
            arrS[i]:='NO';
        end;
    end;
    
    for i:=0 to T-1 do
      writeln(arrS[i]);
end.