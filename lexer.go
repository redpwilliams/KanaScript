package main

import "fmt"

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
			fmt.Println("hg")
			break
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

	}

}
func NextTokenIs(token, input string, pos int) bool {
	return input[pos:pos+len(token)] == token
}
