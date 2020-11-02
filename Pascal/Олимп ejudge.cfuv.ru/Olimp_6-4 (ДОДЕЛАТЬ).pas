program p;
var N, X, f, i : int64;

function IsPrime(nPrime: int64): boolean;
var iPrime, fPrime, delta: int64;
begin
  if (nPrime >= 5) and ((nPrime - 1) mod 6 = 0) or ((nPrime + 1) mod 6 = 0) then
  begin
    iPrime := 5;
    delta := 2;
    fPrime := trunc(sqrt(nPrime));
    IsPrime := false;
    while iPrime <= fPrime do
    begin
      if nPrime mod iPrime = 0 then
        exit;
      Inc(iPrime, delta);
      delta := delta xor 6;
    end;
    IsPrime := true;
  end
  else
    IsPrime := (nPrime = 2) or (nPrime = 3);
end;

begin
  read(N);
  X := 0;
  i := 1;
  
  f := N div 2;
  while i <= f do
  begin
    if N mod i = 0 then
      if IsPrime(i) then
        X := X + 1;
    i := i + 2;
  end;
  
  if N mod 2 = 0 then
    X := X + 1;
  
  if IsPrime(N) and (N <> 2) then
    X := X + 1;
  
  write(X);
end.