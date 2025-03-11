A = [a1, a2]
B = [b1, b2]

A include B if
 - a1 <= b1 && a2 >= b2
B include A if
 - a1 >= b1 && a2 <= b2

 A and B intersect if
 - max(a1 ,b1) <= min(a2, b2)
