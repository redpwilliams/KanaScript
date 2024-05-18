package main

import (
	"fmt"
)

type Lexer struct {
	tokens []Token
}

func (l *Lexer) Tokenize(input string) {
	//Read and interpret each character
	characters := []rune(input)
	for i := 0; i < len(characters); i++ {
		// Write
		//if input[i:i+len("書く")] == "書く" {
		if NextTokenIs("書く", input, i) {
			l.tokens = append(l.tokens, Token{"書く", Kaku})
			i += len([]rune("書く"))
		}
		//else if input[i:i+len("「")] == "「" {
		//	i++
		//	closed := false
		//	for i < len(input) && !closed {
		//		if input[i:i+len("」")] == "」" {
		//			closed = true
		//			l.tokens = append(l.tokens, Token{"test", String})
		//		}
		//		i++
		//	}
		//}

		fmt.Printf("%c\n", []rune(input)[i])
	}

}
func NextTokenIs(token, input string, pos int) bool {
	return input[pos:pos+len(token)] == token
}
