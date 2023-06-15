#! ./markov
# Determine if the input string whose alpabet = {0,1} is palindromic.
# Return "yes" or "no".

0 : [a]
1 : [b]

][ :

[a : a[
[b : b[

[] : ]|

a] : ]a
b] : ]b

|]a : a|[
|]b : b|[

] : |[

a[| : ]|a
b[| : ]|b

# ||[| appears if and only if the length of the input string is odd.
# The next character of ||[| is always the center in that case.
||[|a : !
||[|b : !

# |[| is the center of the string.
|[| : !

a!a : !
b!b : !

a!b : $
b!a : $

! : yes

a :
b :
$ : no
