Program Bit;
var 
  i: integer;
  pi: ^integer;
  
  s:string;
  a: array[0..255] of string[8];
  k,n,x: byte;
  
Begin
pi := @i; // указателю присвоили адрес переменной i
pi^ := 5; // переменной i присвоили 5
writeln(pi);
writeln;

//Преобразуем текст в бинарный код
writeln('Введите текст');
readln(s);
n:=0;
for k:=1 to length(s) do
 begin
  x:=ord(s[k]);
  n:=n+1;
  a[n]:='';
  while x>0 do
   begin
    a[n]:=chr(x mod 2+48)+a[n];
    x:=x div 2;
   end;
  while length(a[n])<8 do a[n]:='0'+a[n];
 end;
for k:=1 to n do
write(a[k],' ');

End.