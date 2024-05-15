# KanaScript ( 漢字スクリプト)

All KanaScript files must have a `.ks` extension.

## Syntax

### Input/Output

`「」<= [@]`: Read from user input. Does nothing with read value.

`「string」=> [@]`: Print a string.

### Variables

Variables have an inferred type of either `string`, `int`, `double`, or `bool`.

Additionally, all variable names must be in kana or Kanji.

`入 [いち] = 1`: Sets a variable to an explicit value.

`入 [に] <= [@]`: Sets a variable to a value read from user input.

`入 [に] <= [いち]`: Sets a variable to the value of a previously instantiated variable within that scope.

### Operators and Conditions

#### Operators

`加`: Addition (+); _"ka"_

`負`: Subtraction (-); _"fu"_

#### Conditions

## Example Programs

### Hello World! (jp)

```
「こんにちは、世界！」=> [@]
```

### Hello World! (en)

```
「Hello, World!」=> [@]
```
