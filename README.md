# Compilation

Le projet doit être compilé depuis la racine à partir du makefile:

```
make
```

Deux paramètres existent dans le makefile

- DEBUG (0 ou 1, par défaut 1)

Lorsque le programme est compilé en mode DEBUG, de nombreuses informations s'affichent. En particulier, les instructions ajoutées à la table des programmes et les push/pop sur la stack.

Compiler avec le mode DEBUG désactivé: 
```
make DEBUG=0
```

Exemple affichage mode DEBUG
```
./calc               ✔  5330  11:25:40
(src/symbol.c     install          32  ) Token "PI" type CONST installed, value 3.1415927
(src/symbol.c     install          32  ) Token "E" type CONST installed, value 2.7182818
(src/symbol.c     install          32  ) Token "GAMMA" type CONST installed, value 0.57721566
(src/symbol.c     install          32  ) Token "DEG" type CONST installed, value 57.29578
(src/symbol.c     install          32  ) Token "PHI" type CONST installed, value 1.618034
(src/symbol.c     install          35  ) Token "sin" type PREDEF installed
(src/symbol.c     install          35  ) Token "cos" type PREDEF installed
(src/symbol.c     install          35  ) Token "tan" type PREDEF installed
(src/symbol.c     install          35  ) Token "abs" type PREDEF installed
(src/symbol.c     install          35  ) Token "log" type PREDEF installed
(src/symbol.c     install          35  ) Token "log10" type PREDEF installed
(src/symbol.c     install          35  ) Token "exp" type PREDEF installed
(src/symbol.c     install          35  ) Token "sqrt" type PREDEF installed
> a = 5
(src/symbol.c     install          26  ) Token "a" type UNDEF installed
(src/code.c       code             66  ) Address [@0x10d5d65b0] --> Instruction [data_push]
(src/code.c       code             66  ) Address [@0x10d5d65b8] --> Instruction [a UNDEF]
(src/symbol.c     install          20  ) Token "" type INT installed, value 5
(src/code.c       code             66  ) Address [@0x10d5d65c0] --> Instruction [data_push]
(src/code.c       code             66  ) Address [@0x10d5d65c8] --> Instruction [INT 5]
(src/code.c       code             66  ) Address [@0x10d5d65d0] --> Instruction [assign]
(src/code.c       code             66  ) Address [@0x10d5d65d8] --> Instruction [print]
(src/code.c       code             66  ) Address [@0x10d5d65e0] --> Instruction [STOP]
(src/code.c       execute          78  ) Executing data_push
(src/code.c       data_push        212 ) Var "a" type UNDEF pushed.
(src/code.c       execute          78  ) Executing data_push
(src/code.c       data_push        164 ) Value "5" type INT pushed.
(src/code.c       execute          78  ) Executing assign
(src/code.c       assign           241 ) Value "5" type INT popped.
(src/code.c       assign           281 ) Var "a" type UNDEF popped.
(src/code.c       assign           301 ) Assigning "5" to var "a" type VINT.
(src/code.c       assign           302 ) Var "a" type VINT pushed.
(src/code.c       execute          78  ) Executing print
(src/code.c       print            112 ) Var "a" type VINT popped.
a = 5
> 5 + 6
(src/symbol.c     install          20  ) Token "" type INT installed, value 5
(src/code.c       code             66  ) Address [@0x10d5d65b0] --> Instruction [data_push]
(src/code.c       code             66  ) Address [@0x10d5d65b8] --> Instruction [INT 5]
(src/symbol.c     install          20  ) Token "" type INT installed, value 6
(src/code.c       code             66  ) Address [@0x10d5d65c0] --> Instruction [data_push]
(src/code.c       code             66  ) Address [@0x10d5d65c8] --> Instruction [INT 6]
(src/code.c       code             66  ) Address [@0x10d5d65d0] --> Instruction [add]
(src/code.c       code             66  ) Address [@0x10d5d65d8] --> Instruction [print]
(src/code.c       code             66  ) Address [@0x10d5d65e0] --> Instruction [STOP]
(src/code.c       execute          78  ) Executing data_push
(src/code.c       data_push        164 ) Value "5" type INT pushed.
(src/code.c       execute          78  ) Executing data_push
(src/code.c       data_push        164 ) Value "6" type INT pushed.
(src/code.c       execute          78  ) Executing add
(src/num.c        add              18  ) Value "6" type INT popped.
(src/num.c        add              75  ) Value "5" type INT popped.
(src/num.c        add              132 ) Value "11" type INT pushed.
(src/code.c       execute          78  ) Executing print
(src/code.c       print            91  ) Value "11" type INT popped.
= 11
```


-AUTOCLEAN (0 ou 1, par défaut 1)

Lorsque compilé en mode AUTOCLEAN, les valeurs numériques sont supprimées de la table des symboles après chaque évaluation. Si vous supprimez ce mode, vous pourrez voir les valeurs numériques anonymes dans la table des symboles.

Compiler avec le mode AUTOCLEAN désactivé: 
```
make AUTOCLEAN=0
```

# High Order Calculator

- les valeurs numériques (INT/FLOAT)
```
> 1
= 1
> 1.7
= 1.7
```

- les valeurs booléennes (BOOL, 'true' et 'false')
```
> true
is true
> false
is false
```

- les variables 
	- non initialisées : UNDEF
	- initialisées : VINT/VFLOAT/VBOOL

- les constantes (CONST, flottantes)
```
> PI
PI = 3.1415927
> PHI
PHI = 1.618034
> DEG
DEG = 57.29578
> GAMMA
GAMMA = 0.57721566
> E
E = 2.7182818
```

- les opérations numériques usuelles (+, -, *, /, ^, %)
```
> 1+4
= 5
> 4-1
= 3
> 4*3
= 12
> 4/2
= 2
> 16%4
= 0
> 17%4
= 1
```

- les opérateurs de comparaison usuels ('>', '>=', '<', '<=', '==', '!=')
```
> 5 < 15
is true
> 14 > 17
is false
> 3 >= 3
is true
> 2 <=2
is true
> 3 == 5
is false
> 4 != 4
is false
> 5 != 3
is true
```

- les opérations logiques usuelles (AND, OR, NOT)
```
> false OR 4 < 5
is true
> true AND 5 > 6
is false
> NOT 7 != 6
is false
```

- les assignations (=)
```
> a = 4
a = 4
```

- les parenthèses ('(' et ')')
```
> 5*(2+4)
= 30
> 5*2+4
= 14
```

- les fonctions prédéfinies (log, log10, sqrt, sin, cos...)
```
> log(1)
= 0
> log(3)
= 1.0986123
> log10(4)
= 0.60205999
> sqrt(4)
= 2
> sin(90)
= 0.89399666
> cos(90)
= -0.44807362
```

- l'affichage de la table des symboles (commande "symbols")
```
Symbol List :

Address         Name    Type    Value
0x7f8141d00060  c       VINT    7
0x7f8141d00030  b       VINT    6
0x7f8141c02e60  a       VINT    5
0x7f8141d00000  sqrt    PREDEF
0x7f8141c02e30  exp     PREDEF
0x7f8141c02e00  log10   PREDEF
0x7f8141c02dd0  log     PREDEF
0x7f8141c02da0  abs     PREDEF
0x7f8141c02d70  tan     PREDEF
0x7f8141c02d40  cos     PREDEF
0x7f8141c02d10  sin     PREDEF
0x7f8141c02ce0  PHI     CONST   1.618034
0x7f8141c02cb0  DEG     CONST   57.29578
0x7f8141c02c90  GAMMA   CONST   0.57721566
0x7f8141c02c50  E       CONST   2.7182818
0x7f8141c02b90  PI      CONST   3.1415927
```

- la sortie du programme (commande "exit" ou "quit")
```
> exit
See you soon !.

> quit
See you soon !.
```

- if / else / { / } / ;

# CHANGELOG

## Version 1.1 (Jan. 11, 2019)

- Partitionnement du fichier code.c en 3 fichiers distincts
	code.c : gestion de la table des programmes et code intermédiaire non spécifique
	num.c : code intermédiaire correspondant aux opérations numériques
	bool.c : code intermédiaire correspondant aux opérations logiques
- Support des booléens (BOOL) et des variables booléennes (VBOOL)
- Support des opérations logiques usuelles (AND, OR, NOT)
- Support des opérateurs de comparaison usuels ('>', '>=', '<', '<=', '==', '!=')

## Version 1.0 (Dec. 22, 2018)
- Support des INT/FLOAT
- Support des variables UNDEF/VINT/VFLOAT
- Support des opérations usuelles (+, -, *, /, ^, %)
- Support des assignations (=)
- Support des parenthèses ('(', ')')
- Support des constantes et fonctions prédéfinies ("init.c", "init.h")
- Affichage de la table des symboles à l'aide de la commande "symbols"
- Sortie du programme à l'aide des commandes "exit" ou "quit"
