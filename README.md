#  Personal programming language interpreter

<h3> Keyword table </h3>

|Action| Key |
|--|--|
| Initializing a Variable | `VAR` |
| Cycle call **while** | `WHILE` |
| Conditional operator **if** | `IF` |
| Conditional operator **else** | `ELSE` |
| Print to console | `PRINT` |

<h3>Language syntax</h3>

At the end of the line you need to put `;` .
If we call `WHILE` conditions we push in `()` and the instruction in `{}` .
In conditional operator`IF-ELSE`  - conditions we push in `()` and the instruction in `{}` .

<h3> Пример кода </h3>

```
VAR a = 3;
VAR b = 9;
WHILE (a < b){
	a += 1;
}
VAR c = True;
IF (c == False){
	PRINT a;
}
ELSE{
	PRINT b;
}

```
