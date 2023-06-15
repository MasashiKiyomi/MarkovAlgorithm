#! ./markov
# Determine if the input string whose alpabet = {0,1} is palindromic.
# Return "yes" or "no".

0 : [.,]
1 : [..,]
2 : [...,]
3 : [....,]

][ :

[no : no
.no : no
,no : no

[] : yes
[.,] : yes
[..,] : yes
[...,] : yes
[....,] : yes

[a.,] : yes
[b..,] : yes
[c...,] : yes
[d....,] : yes

a] : no
b] : no
c] : no
d] : no

,a.,] : ,]
,b..,] : ,]
,c...,] : ,]
,d....,] : ,]

a. : .a
b. : .b
c. : .c
d. : .d

a, : ,a
b, : ,b
c, : ,c
d, : ,d

[., : [a
[.., : [b
[..., : [c
[...., : [d
