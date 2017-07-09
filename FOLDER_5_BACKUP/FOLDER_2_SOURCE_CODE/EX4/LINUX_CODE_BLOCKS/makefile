############
# COMPILER #
############
CC=gcc

###############
# DIRECTORIES #
###############
BASEDIR              = /home/oren/GIT/COMPILATION_MTA_FOR_STUDENTS/FOLDER_2_SOURCE_CODE/EX4/LINUX_GCC_MAKE
LEXER_DIR            = $(BASEDIR)/FOLDER_0_Flex
PARSER_DIR           = $(BASEDIR)/FOLDER_1_Bison
STARKIST_DIR         = $(BASEDIR)/FOLDER_2_LEXER_PARSER_StarKist
CODEGEN__DIR         = $(BASEDIR)/FOLDER_3_LEXER_PARSER_CodeGen
REGALLOC_DIR         = $(BASEDIR)/FOLDER_4_LEXER_PARSER_RegisterAllocation
COMPILER_SOURCE_DIR  = $(BASEDIR)/FOLDER_5_COMPILER_SOURCE_FILES
COMPILER_HEADER_DIR  = $(BASEDIR)/FOLDER_6_COMPILER_HEADER_FILES
LEXER_SOURCE_DIR     = $(LEXER_DIR)/SOURCE_FILES
LEXER_HEADER_DIR     = $(LEXER_DIR)/HEADER_FILES
LEXER_OBJECT_DIR     = $(LEXER_DIR)/OBJECT_FILES
PARSER_SOURCE_DIR    = $(PARSER_DIR)/SOURCE_FILES
PARSER_HEADER_DIR    = $(PARSER_DIR)/HEADER_FILES
PARSER_OBJECT_DIR    = $(PARSER_DIR)/OBJECT_FILES

###############
# LEXER FLAGS #
###############
LEXER_PROGRAM_FLAGS_StarKist   = -o$(STARKIST_DIR)/StarKistLexer.c
LEXER_PROGRAM_FLAGS__CodeGen   = -o$(CODEGEN__DIR)/CodeGen_Lexer.c
LEXER_PROGRAM_FLAGS_RegAlloc   = -o$(REGALLOC_DIR)/RegAllocLexer.c

################
# PARSER FLAGS #
################
PARSER_PROGRAM_FLAGS_StarKist  = -d -v -o $(STARKIST_DIR)/StarKistParser.c
PARSER_PROGRAM_FLAGS__CodeGen  = -d -v -p zz -o $(CODEGEN__DIR)/CodeGen_Parser.c
PARSER_PROGRAM_FLAGS_RegAlloc  = -d -v -p gg -o $(REGALLOC_DIR)/RegAllocParser.c

#####################
# LEXER INPUT FILES #
#####################
LEXER_INPUT_StarKist  = $(STARKIST_DIR)/StarKist.lex
LEXER_INPUT__CodeGen  = $(CODEGEN__DIR)/CodeGen.lex
LEXER_INPUT_RegAlloc  = $(REGALLOC_DIR)/RegAlloc.lex

######################
# PARSER INPUT FILES #
######################
PARSER_INPUT_StarKist = $(STARKIST_DIR)/StarKist.y
PARSER_INPUT__CodeGen = $(CODEGEN__DIR)/CodeGen.y
PARSER_INPUT_RegAlloc = $(REGALLOC_DIR)/RegAlloc.y

#########
# LEXER #
#########
LEXER_FLAGS           = -I$(LEXER_HEADER_DIR) -w
LEXER_PROGRAM         = $(LEXER_DIR)/MyFlex 
LEXER_SOURCE_FILES   := $(wildcard  $(LEXER_SOURCE_DIR)/*.c)
LEXER_HEADER_FILES   := $(wildcard  $(LEXER_HEADER_DIR)/*.h)
LEXER_OBJECT_FILES   := $(addprefix $(LEXER_OBJECT_DIR)/,$(LEXER_SOURCE_FILES,.c=.o))

##########
# PARSER #
##########
PARSER_FLAGS          = -I$(PARSER_HEADER_DIR) -w
PARSER_PROGRAM        = $(PARSER_DIR)/MyBison 
PARSER_SOURCE_FILES  := $(wildcard  $(PARSER_SOURCE_DIR)/*.c)
PARSER_HEADER_FILES  := $(wildcard  $(PARSER_HEADER_DIR)/*.h)
PARSER_OBJECT_FILES  := $(addprefix $(PARSER_OBJECT_DIR)/,$(PARSER_SOURCE_FILES,.c=.o))

############
# COMPILER #
############
COMPILER_FLAGS         = -I$(COMPILER_HEADER_DIR) -w
COMPILER_PROGRAM       = compiler
COMPILER_SOURCE_FILES := $(wildcard  $(COMPILER_SOURCE_DIR)/*.c)
COMPILER_HEADER_FILES := $(wildcard  $(COMPILER_HEADER_DIR)/*.h)
COMPILER_OBJECT_FILES := $(addprefix $(LEXER_OBJECT_DIR)/,$(LEXER_SOURCE_FILES,.c=.o))

##########################
# ALL LEXER(S) PARSER(S) #
##########################
all: 
	@$(CC) $(LEXER_FLAGS)  $(LEXER_SOURCE_FILES)  -o $(LEXER_PROGRAM)
	@$(CC) $(PARSER_FLAGS) $(PARSER_SOURCE_FILES) -o $(PARSER_PROGRAM)
	@$(LEXER_PROGRAM)  $(LEXER_PROGRAM_FLAGS_StarKist)  $(LEXER_INPUT_StarKist)
	@$(LEXER_PROGRAM)  $(LEXER_PROGRAM_FLAGS__CodeGen)  $(LEXER_INPUT__CodeGen)
	@$(LEXER_PROGRAM)  $(LEXER_PROGRAM_FLAGS_RegAlloc)  $(LEXER_INPUT_RegAlloc)
	@$(PARSER_PROGRAM) $(PARSER_PROGRAM_FLAGS_StarKist) $(PARSER_INPUT_StarKist)
	@$(PARSER_PROGRAM) $(PARSER_PROGRAM_FLAGS__CodeGen) $(PARSER_INPUT__CodeGen)
	@$(PARSER_PROGRAM) $(PARSER_PROGRAM_FLAGS_RegAlloc) $(PARSER_INPUT_RegAlloc)
	@mv $(STARKIST_DIR)/StarKistLexer.c  $(COMPILER_SOURCE_DIR)
	@mv $(CODEGEN__DIR)/CodeGen_Lexer.c  $(COMPILER_SOURCE_DIR)
	@mv $(REGALLOC_DIR)/RegAllocLexer.c  $(COMPILER_SOURCE_DIR)
	@mv $(STARKIST_DIR)/StarKistParser.c $(COMPILER_SOURCE_DIR)
	@mv $(CODEGEN__DIR)/CodeGen_Parser.c $(COMPILER_SOURCE_DIR)
	@mv $(REGALLOC_DIR)/RegAllocParser.c $(COMPILER_SOURCE_DIR)
	@mv $(STARKIST_DIR)/StarKistParser.h $(COMPILER_HEADER_DIR)
	@mv $(CODEGEN__DIR)/CodeGen_Parser.h $(COMPILER_HEADER_DIR)
	@mv $(REGALLOC_DIR)/RegAllocParser.h $(COMPILER_HEADER_DIR)
	@printf "\n"
	@printf "\n"
	@printf "\n"
	@pwd
	@printf "\n"
	@printf "\n"
	@printf "\n"
	@printf "\n"
	$(CC) $(COMPILER_FLAGS) $(COMPILER_SOURCE_FILES) -o $(COMPILER_PROGRAM)
#	$(CC) $(COMPILER_FLAGS) $(COMPILER_SOURCE_DIR)/absyn.c -o $(COMPILER_PROGRAM)

