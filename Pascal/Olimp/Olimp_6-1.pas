Program p;
var N1, N2, A1, B1, A2, B2 : integer;

Begin
readln(A1, B1, A2, B2);
if (A1 > B1) then N1 := A1 else N1 := B1;
if (A2 > B2) then N2 := A2 else N2 := B2;
writeln (N1 + N2);
end.