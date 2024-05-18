package main

import (
	"fmt"
	"os"
)

type Lexer struct {
	tokens []Token
}

func (l *Lexer) Tokenize(input string) {
	//Read and interpret each character
	//characters := []rune(input)
	for i := 0; i < len(input); i++ {
		// Write
		if NextTokenIs("書く", input, i) {
			l.tokens = append(l.tokens, Token{"書く", Kaku})
			i += len("書く") - 1 // let the loop do the last increment
		} else if NextTokenIs("「", input, i) {
			start := i
			for !NextTokenIs("」", input, i) {
				i++
			}
			l.tokens = append(l.tokens, Token{input[start : i+len("」")], String})
			i += len("」") - 1
		} else if NextTokenIs("=>", input, i) {
			l.tokens = append(l.tokens, Token{input[i : i+len("=>")], AssignmentOutput})
			i += len("=>") - 1
		} else if NextTokenIs("[@]", input, i) {
			l.tokens = append(l.tokens, Token{input[i : i+len("[@]")], Contact})
			i += len("[@]") - 1
		} else if NextTokenIs(" ", input, i) {
			l.tokens = append(l.tokens, Token{input[i : i+len(" ")], Whitespace})
			i += len(" ") - 1
		} else {
			fmt.Println("Unexpected character")
			os.Exit(1)
		}
	}

}
func NextTokenIs(token, input string, pos int) bool {
	if pos+len(token) > len(input) {
		return false
	}
	return input[pos:pos+len(token)] == token
}
