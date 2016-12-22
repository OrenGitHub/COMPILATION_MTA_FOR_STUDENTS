############
# COMPILER #
############
CC=gcc

###############
# DIRECTORIES #
###############
BASEDIR = .
LEXER_PARSER_StarKist_DIR  = $(BASEDIR)/LEXER_PARSER_1_StarKist
LEXER_StarKist_DIR         = $(LEXER_PARSER_StarKist_DIR)/Flex
PARSER_StarKist_DIR        = $(LEXER_PARSER_StarKist_DIR)/Bison
LEXER_StarKist_SOURCE_DIR  = $(LEXER_StarKist_DIR)/SOURCE_FILES
LEXER_StarKist_HEADER_DIR  = $(LEXER_StarKist_DIR)/HEADER_FILES
LEXER_StarKist_OBJECT_DIR  = $(LEXER_StarKist_DIR)/OBJECT_FILES
PARSER_StarKist_SOURCE_DIR = $(PARSER_StarKist_DIR)/SOURCE_FILES
PARSER_StarKist_HEADER_DIR = $(PARSER_StarKist_DIR)/HEADER_FILES
PARSER_StarKist_OBJECT_DIR = $(PARSER_StarKist_DIR)/OBJECT_FILES

##################
# StarKist LEXER #
##################
LEXER_FLAGS_StarKist               =
LEXER_PROGRAM_StarKist             = Flex 
LEXER_StarKist_SOURCE_FILES        = $(wildcard  $(LEXER_StarKist_SOURCE_DIR)/*.c)
LEXER_StarKist_HEADER_FILES        = $(LEXER_StarKist_SOURCE_DIR)/*.h
LEXER_StarKist_OBJECT_FILES        = $(addprefix $(LEXER_StarKist_OBJECT_DIR)/,$(LEXER_StarKist_SOURCE_FILES,.c=.o)))

###################
# StarKist PARSER #
###################
PARSER_FLAGS_StarKist               =
PARSER_PROGRAM_StarKist             = Bison 
PARSER_StarKist_SOURCE_FILES        = $(wildcard  $(PARSER_StarKist_SOURCE_DIR)/*.c)
PARSER_StarKist_HEADER_FILES        = $(PARSER_StarKist_HEADER_DIR)/*.h
PARSER_StarKist_OBJECT_FILES        = $(addprefix $(PARSER_StarKist_OBJECT_DIR)/,$(LEXER_StarKist_SOURCE_FILES,.c=.o)))

#########################
# StarKist LEXER PARSER #
#########################
LEXER_PARSER_StarKist: $(LEXER_StarKist_OBJECT_FILES) $(PARSER_StarKist_OBJECT_FILES) $(LEXER_StarKist_HEADER_FILES) $(PARSER_StarKist_HEADER_FILES)
	$(CC) $(LEXER_FLAGS_StarKist)  $(LEXER_StarKist_SOURCE_DIR)/$(LEXER_StarKist_SOURCE_FILES)
	$(CC) $(PARSER_FLAGS_StarKist) $(PARSER_StarKist_SOURCE_DIR)/$(PARSER_StarKist_SOURCE_FILES)
	$(PARSER_PROGRAM_StarKist) $(PARSER_PROGRAM_FLAGS_StarKist) $(PARSER_INPUT_StarKist)
	$(LEXER_PROGRAM_StarKist)  $(LEXER_PROGRAM_FLAGS_StarKist)  $(LEXER_INPUT_StarKist)

########################
# CodeGen LEXER PARSER #
########################
LEXER_PARSER_CodeGen: $(SOURCE_FILES_LEXER_PARSER_CodeGen) $(HEADER_FILES_LEXER_PARSER_CodeGen)
	$(CC) $(LEXER_FLAGS_CodeGen)  $(SOURCE_FILES_LEXER_CodeGen)
	$(CC) $(PARSER_FLAGS_CodeGen) $(SOURCE_FILES_PARSER_CodeGen)
	$(PARSER_PROGRAM_CodeGen) $(PARSER_PROGRAM_FLAGS_CodeGen) $(PARSER_INPUT_CodeGen)
	$(LEXER_PROGRAM_CodeGen)  $(LEXER_PROGRAM_FLAGS_CodeGen)  $(LEXER_INPUT_CodeGen)

###################################
# RegisterALlocation LEXER PARSER #
###################################
LEXER_PARSER_RegisterAllocation: $(SOURCE_FILES_LEXER_PARSER_RegisterAllocation) $(HEADER_FILES_LEXER_PARSER_RegisterAllocation)
	$(CC) $(LEXER_FLAGS_RegisterAllocation)  $(SOURCE_FILES_LEXER_RegisterAllocation)
	$(CC) $(PARSER_FLAGS_RegisterAllocation) $(SOURCE_FILES_PARSER_RegisterAllocation)
	$(PARSER_PROGRAM_RegisterAllocation) $(PARSER_PROGRAM_FLAGS_RegisterAllocation) $(PARSER_INPUT_RegisterAllocation)
	$(LEXER_PROGRAM_RegisterAllocation)  $(LEXER_PROGRAM_FLAGS_RegisterAllocation)  $(LEXER_INPUT_RegisterAllocation)

############
# Compiler #
############
Compiler: LEXER_PARSER_StarKist LEXER_PARSER_CodeGen LEXER_PARSER_RegisterAllocation
	$(CC) $(COMPILER_FLAGS) $(COMPILER_SRC_FILES)
