
## Tokenizer
+ keywords
+ print number of each TokenKind
+ use lookup table per char
+ faster keyword lookup
+ support block comment
+ let error generate line-nr
+ TODO escaped chars in strings (especially \")
+ SourceLoc of EOF is 0
+ check max identifier Length (31 bytes)
+ support basic feature-selection: (#if [cond], #else, #endif)
+ have error() be like printf
+ error/warn feature
+ named feature-selection
- FIX comment
- support nested /* */ comments
- Numbers:
    - parse floating points
    - parse hexadecimal
    - note radix in token
- advanced basic feature-selection:
    - NAME=<value> -> value always treated as text
    - OR AND NOT in condition
    - () to indicate order

## SourceManager
+ reserve location 0
+ remove hardcoded file max
+ alias-type for SrcLoc
- close files after use (need indication)

## Parser
- put all output through filter for coloring/not
- parse Types
- parse Functions
- parse Varables

## AST
+ create structure
+ create Context (for allocation)
- FIX object sizes (Stmt should be 4 bytes, not aligned yet)
- move SrcLoc to ast_helper?

## AST-Builder
+ fill AST
+ print content

## Performance
- profile application to see where time is spent
- try building as 32-bit application, measure mem + speed
    add -m32 to CFLAGS + LDFLAGS
- check how other Compilers (easier ones) parse Expr
    cproc -> see expr.c:1311 -> expr()

## General
- remove unused import
- dont import local, (for single printf)
- check clang build warnings


Parse Expr:
clang
    TODO

cproc
    TODO

c2c
    NEW (without C cast)
