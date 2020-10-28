program p;

var N, M, maxN, sumN, i, j, temp : integer;
    arr : array of integer;

begin
  read(N);
  read(M);
  setLength(arr, M);
  
  for i := 0 to M-1 do
    read(arr[i]);
  sumN := 0;
  maxN := 0;
  
  for i := 0 to M-1 do
  begin
    temp := 0;
    for j := i to M-1 do
      if arr[j] = arr[i] then
        temp := temp + 1;
    if temp > sumN then
    begin
      maxN := arr[i];
      sumN := temp
    end
    else
    if (temp = sumN) and (maxN > arr[i]) then
    begin
      maxN := arr[i];
      sumN := temp
    end;
  end;
  
  write(maxN, ' ', sumN);
end.