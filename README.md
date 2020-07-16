# OOP project 

This is an OOP project for FMI, Sofia University, Sofia.

## Application for working with spreadsheets.

### Data representation
The data will be stored in *.txt files, following the rules: 

1. Each row in the file represents a separated row in the spreadsheet.
2. Each row in the file contains data, separated by comma. This data
we should interpret like the data in the cells of that row.
3. Each row of the spreadsheet can contain different number of cells.
Therefore each row of the file can contain different number of of elements, separated by comma.
4. Empty row in the file represents empty row in the spreadsheet.
5. Between two comma signs there could be no data. (Representing empty cell)
6. Between data and commas there could be arbitrary whitespaces.

Let's have an example spreadsheet.

| 10     | 20     | 30       | 40 |
|--------|--------|----------|----|
|        |        |          |    |
| **10** |        | **1000** |    |
|        |        |          |    |
|        | **10** |          |    |


We can represent it in different ways. For example:

```
10, 20, 30, 40

10,,1000,
,,,
,10
```
or

```
10, 20 , 30  , 40

10,	, 1000,
  ,    , 	,
  , 10
```  

## Data types
Each cell in the spreadsheet has its own type.
Our app should supports the following types:

### Integer numbers
Sequence of digits without any different symbols between them.
The sequence can start with '+' or '-'.

Examples: 
* 123
* -123
* +123

### Floating-point numbers
Sequence of digits followed by '.' followed by another sequence of digits.
The sequence can start with '+' or '-'.

Examples: 
* 123.456
* -123.456
* +123.456

### String
Sequence of random characters enclosed in quotation marks.

**Warning** 
* If you want to add the quotation mark inside the string, you must do it like that: \\"
* If you want to add the backslash sign, you must do it like that: \\\

Examples:
```
"Hello world!"
"C:\\temp\\"
"\"This is a quotation\""
```

### Formula
The formula must begin with equal sign. We can use the following operations inside the formula: +, -, *, /, ^.
The formula operands can be numbers or references of the cells.

## Functionality

* open - by given file
* close
* save 
* save as - by given file
* help
* exit
* print - on the console
* edit - by given cell and new content


### print command example

Input file information:
```
10, "Hello world!", 123.56
"\"Quoted\""
1, 2, 3, 4
```
Console output:
```
10       | Hello world! | 123.56 |   |
"Quoted" |              |        |   |
1        |            2 |      3 | 4 |
```

### Formulas

* Reference
R\<N>C\<M> represents the cell in row \<N> and in col \<M>. (counting from 1)

* Arithmetic rules: If there is a string we must convert it into a number. If the string represents a valid number, we should use it, otherwise we should evaluate it with 0.

Examples:

String | Evaluation
-------|-----------
“123”  | 123
“123.456.789” | 0
“123.456” | 123.456
“Hello world” | 0
“123abc” | 0


**Warning:** 
Empty cells must be evaluated with 0.
