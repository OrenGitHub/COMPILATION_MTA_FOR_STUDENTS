############
# COMPILER #
############
CC=gcc

###############
# DIRECTORIES #
###############
BASEDIR              = $(shell pwd)
LEXER_DIR            = $(BASEDIR)/FOLDER_00_Flex
PARSER_DIR           = $(BASEDIR)/FOLDER_01_Bison
LEXER_USER_DIR       = $(BASEDIR)/FOLDER_02_LEXER
PARSER_USER_DIR      = $(BASEDIR)/FOLDER_03_PARSER
SOURCE_FILES_DIR     = $(BASEDIR)/FOLDER_04_SOURCE_FILES
HEADER_FILES_DIR     = $(BASEDIR)/FOLDER_05_HEADER_FILES
BISON_PARSER_DIR     = $(BASEDIR)/FOLDER_06_BISON_PARSER
INPUT_DIR            = $(BASEDIR)/FOLDER_07_INPUT_FILES
OUTPUT_DIR           = $(BASEDIR)/FOLDER_08_OUTPUT_FILES
LEXER_SOURCE_DIR     = $(LEXER_DIR)/SOURCE_FILES
LEXER_HEADER_DIR     = $(LEXER_DIR)/HEADER_FILES
LEXER_OBJECT_DIR     = $(LEXER_DIR)/OBJECT_FILES
PARSER_SOURCE_DIR    = $(PARSER_DIR)/SOURCE_FILES
PARSER_HEADER_DIR    = $(PARSER_DIR)/HEADER_FILES
PARSER_OBJECT_DIR    = $(PARSER_DIR)/OBJECT_FILES

###############
# LEXER FLAGS #
###############
LEXER_USER_FLAGS = -o$(LEXER_USER_DIR)/Lexer.c

#####################
# LEXER INPUT FILES #
#####################
LEXER_USER_INPUT = $(LEXER_USER_DIR)/LEX_FILE.lex

################
# PARSER FLAGS #
################
PARSER_USER_FLAGS = -d -v -p aa -o $(PARSER_USER_DIR)/Parser.c

######################
# PARSER INPUT FILES #
######################
PARSER_USER_INPUT = $(PARSER_USER_DIR)/grammar.y

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

################
# BISON_PARSER #
################
BISON_PARSER_FLAGS         = -I$(HEADER_FILES_DIR) -w
BISON_PARSER_PROGRAM       = $(BISON_PARSER_DIR)/BISON_PARSER
BISON_PARSER_SOURCE_FILES := $(wildcard  $(SOURCE_FILES_DIR)/*.c)
BISON_PARSER_HEADER_FILES := $(wildcard  $(HEADER_FILES_DIR)/*.h)
BISON_PARSER_OBJECT_FILES := $(addprefix $(LEXER_OBJECT_DIR)/,$(LEXER_SOURCE_FILES,.c=.o))

################
# INPUT/OUTPUT #
################
INPUT  = $(INPUT_DIR)/Input.txt
OUTPUT = $(OUTPUT_DIR)/LEX_LOG_FILE.txt

##########################
# ALL LEXER(S) PARSER(S) #
##########################
all:
	@echo "\n"
	@echo "*****************"
	@echo "* Clean All ... *"
	@echo "*****************"
	@echo "\n"
	rm -rf $(LEXER_PROGRAM)
	rm -rf $(PARSER_PROGRAM)
	rm -rf $(BISON_PARSER_PROGRAM)
	rm -rf $(SOURCE_FILES_DIR)/Lexer.c
	rm -rf $(SOURCE_FILES_DIR)/Parser.c
	rm -rf $(SOURCE_FILES_DIR)/Parser.h
	@echo "\n"
	@echo "******************"
	@echo "* Build Flex ... *"
	@echo "******************"
	@echo "\n"
	$(CC) $(LEXER_FLAGS) $(LEXER_SOURCE_FILES) -o $(LEXER_PROGRAM)
	@echo "\n"
	@echo "*******************"
	@echo "* Build Bison ... *"
	@echo "*******************"
	@echo "\n"
	$(CC) $(PARSER_FLAGS) $(PARSER_SOURCE_FILES) -o $(PARSER_PROGRAM)
	@echo "\n"
	@echo "**********************************"
	@echo "* Run All Lexer(s) Parser(s) ... *"
	@echo "**********************************"
	@echo "\n"
	$(LEXER_PROGRAM)  $(LEXER_USER_FLAGS)  $(LEXER_USER_INPUT)
	$(PARSER_PROGRAM) $(PARSER_USER_FLAGS) $(PARSER_USER_INPUT)
	@echo "\n"
	@echo "***************************************************************"
	@echo "* Move Generated Lexer(s) Parser(s) to destined folder(s) ... *"
	@echo "***************************************************************"
	@echo "\n"
	mv $(LEXER_USER_DIR)/Lexer.c   $(SOURCE_FILES_DIR)
	mv $(PARSER_USER_DIR)/Parser.c $(SOURCE_FILES_DIR)
	mv $(PARSER_USER_DIR)/Parser.h $(HEADER_FILES_DIR)
	@echo "\n"
	@echo "**************************"
	@echo "* Build BISON_PARSER ... *"
	@echo "**************************"
	@echo "\n"
	$(CC) $(BISON_PARSER_FLAGS) $(BISON_PARSER_SOURCE_FILES) -o $(BISON_PARSER_PROGRAM)
	@echo "\n"
	@echo "****************"
	@echo "* Clear Screen *"
	@echo "****************"
	@echo "\n"
	clear
	@echo "\n"
	@echo "****************************"
	@echo "* Execute BISON_PARSER ... *"
	@echo "****************************"
	@echo "\n"
	$(BISON_PARSER_PROGRAM) $(INPUT) $(OUTPUT)

