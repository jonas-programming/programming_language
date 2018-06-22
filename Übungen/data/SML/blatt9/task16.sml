fun ggT (a: int, 0) = a
|	ggT (a: int, b: int) = ggT(b, a mod b);
ggT(18, 9)