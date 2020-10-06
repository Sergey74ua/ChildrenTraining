Program Risovanie;
uses GraphABC;

Begin
  Pen.Color := RGB(0, 255, 0);
  Line(300, 100, 200, 200); 
  SetPenColor(clBlue);
  SetBrushColor(clRed);
  Circle(100, 100, 50);
  SetPenColor(clRed);
  SetBrushColor(clYellow);
  Rectangle(200, 250, 400, 400);
  
end.