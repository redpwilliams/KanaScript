# KanaScript ( 漢字スクリプト)

All KanaScript files must have a `.ks` extension.

## Syntax

Each instruction is characterized by its kanji.

### Input/Output

`読む「」<= [@]`: Read from user input. Does nothing with read value. Pronounced よむ ("_yomu_"), meaning _to read_.

`書く「string」=> [@]`: Print a string. Pronounced 書く ("_kaku_"), meaning _to write_.

### Variables

Variables have an inferred type of either `int`, `double`, `string`, or `bool`. Additionally, all variable names must be in kana or Kanji.

`成る [var] = value`: Sets a variable to an explicit value. Types are inferred.

`成る [var] <= [@]`: Sets a variable to a value read from user input.

`成る [var] <= [var]`: Sets a variable to the value of a previously instantiated variable within that scope.

These instructions use the Kanji 成る, pronounced なる ("_naru_"), meaning _to become_.

### Conditional Operators

KanaScript divides conditional operators into two types: `relational` operators and `logical` operators.

#### Relational

Relational operators establish relationships between values. KanaScript supports the standard set of relational operators: `==` (equal to), `!=` (not equal to), `<` (less than), `>` (greater than), `<=` (less than or equal to), and `>=` (greater than or equal to).

#### Logical

Logical operators combine conditions to form more complex expressions. KanaScript adopts 3 common logical operators: `||` (logical OR), `&&` (logical AND), and `!` (NOT).

### Control Flow

#### もし ("_moshi_") / If

The standard もし statement has the following structures:

`もし [var] condition value:`: Executes if `var`'s relation to `value` via the relational `condition` is truthy.

`もし [var1] condition [var2]:`: Executes if `var1`'s relation to `var2` via the relational `condition` is truthy.

#### でもーもし ("_demo-moshi_") / Else-If

The standard もし statement has the following structures:

`もし [var] condition value:`: Executes if `var`'s relation to `value` via the relational `condition` is truthy.

`もし [var1] condition [var2]:`: Executes if `var1`'s relation to `var2` via the relational `condition` is truthy.

All でもーもし statements must follow a もし statement.

#### でも ("_demo_") / Else

The standard でも statement has the following structures:

`でも [var] condition value:`: Executes if `var`'s relation to `value` via the relational `condition` is truthy.

`でも [var1] condition [var2]:`: Executes if `var1`'s relation to `var2` via the relational `condition` is truthy.

All でも statements must follow at least one もし or でもーもし statement, and cannot be followed by any control structure.

#### 重ねる ("_kasaneru_") / For, While

A 重ねる loop can execute while its condition is true (_while_), or execute incrementally while that condition is true (_for_), depending on its syntax.

`重ねる [var] condition value:` Repeats the following indented KanaScript code until `var`'s relation to `value` via the relational `condition` is falsy.

`重ねる [var1] condition [var2]:` Repeats the following indented KanaScript code until `var1`'s relation to `var2` via the relational `condition` is falsy.

`重ねる ( [var] ; [var] condition [var]|value  ; [var]' ):` Repeats the following indented KanaScript code incrementally. This 重ねる loop is divided into `initialization`, `condition`, and `incrementation`:

1. `Initialization`: Creates a variable to be used within the scope of the 重ねる loop and to be incremented on using any valid variable initialization procedure. Must be either an `int` or `double`.
2. `Condition`: Executes the 重ねる loop repeatedly until the condition is falsy.
3. `Incrementation`: Executes a statement of code. Usually operates on the initialized variable, but it can run a function, as well.

## Example Programs

### Hello World! (jp)

```
「こんにちは、世界！」=> [@]
```

### Hello World! (en)

```
「Hello, World!」=> [@]
```
