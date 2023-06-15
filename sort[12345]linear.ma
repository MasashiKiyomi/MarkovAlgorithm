#! ./markov

# {1,2,3,4,5}* を線形行でソート

]1 : [.,]
]2 : [..,]
]3 : [...,]
]4 : [....,]
]5 : [.....,]

[ : {
] : }

.{ : {.
,{ : {,

a. : .b
b. : .c
c. : .d
d. : .e

a, : ,A
b, : ,B
c, : ,C
d, : ,D
e, : ,E

.<A : <A.
.<B : <B.
.<C : <C.
.<D : <D.

.,<A. : ,.a
..,<B. : ,.a
...,<C. : ,.a
....,<D. : ,.a

B. : .A
C. : .B
D. : .C
E. : .D

A, : <A.,
B, : <B..,
C, : <C...,
D, : <D....,

A. : (.
.( : (.

,(. : ,.a

A} : }
B} : }
C} : }
D} : }
E} : }

{. : .a

.....,} : }5
....,} : }4
...,} : }3
..,} : }2
.,} : }1
} ::

: ]
