program p;

var N, M, i, j, temp, row, d : integer;
    arr : array of integer;

begin
  read(N, M);
  SetLength(arr, N);
  
  for i := 0 to N-1 do
    read(arr[i]);
  
  for i := 0 to N-1 do
    for j := i+1 to N-1 do
      if arr[i] > arr[j] then
        begin
          temp := arr[i];
          arr[i] := arr[j];
          arr[j] := temp;
        end;
  
  temp := 0;
  for i := 0 to N-2 do
    if arr[i] = arr[i+1] then
      temp := temp+1
    else
    begin
      ****************************************
    end;
  
  write(arr);
end.