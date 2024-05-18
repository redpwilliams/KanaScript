package main

type Token struct {
	value     string
	tokenType TokenType
}

type TokenType int

const (
	Kaku       TokenType = iota // Kanji character
	Identifier                  // <variable name>
	String                      // 「<string>」
	// Whitespace QuotationLeft   <--?? goland sux //「
	//QuotationRight                     // 」
	Whitespace       // <whitespace>
	AssignmentInput  // <=
	AssignmentOutput // =>
	Variable
	Contact // [@]
)
