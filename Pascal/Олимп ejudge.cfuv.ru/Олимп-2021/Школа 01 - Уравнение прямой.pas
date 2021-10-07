program p;

var x1, y1, x2, y2, k, b: real;
  s: char;

begin
  writeln('Введите координаты двух точек: x1, y1, x2, y2');
  readln(x1, y1, x2, y2);
  
  k := (y1 - y2) / (x1 - x2);
	b := y2 - k * x2;
	if b >= 0 then
    s := '+'
  else
    s := '-';
	b := Abs(b);
	
  writeln('Уравнения прямой: y = ', k:0:3, 'x ', s , ' ', b:0:3);
end.