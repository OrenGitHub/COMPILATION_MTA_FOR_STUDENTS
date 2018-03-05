##############
# SIMULATION #
##############
CC=gcc

###############
# DIRECTORIES #
###############
BASEDIR                = /home/oren/GIT/COMPILATION_TAU_FOR_STUDENTS/EX5/SIMULATION_VERSION_6/LINUX_GCC_MAKE
LEXER_DIR              = $(BASEDIR)/FOLDER_0_Flex
PARSER_DIR             = $(BASEDIR)/FOLDER_1_Bison
CODEGEN__DIR           = $(BASEDIR)/FOLDER_2_LEXER_PARSER_CodeGen
SIMULATION_SOURCE_DIR  = $(BASEDIR)/FOLDER_3_SIMULATION_SOURCE_FILES
SIMULATION_HEADER_DIR  = $(BASEDIR)/FOLDER_4_SIMULATION_HEADER_FILES
SIMULATION_DIR         = $(BASEDIR)/FOLDER_5_SIMULATION
INPUT_DIR              = $(BASEDIR)/FOLDER_6_INPUT_PSEUDO_ASM
OUTPUT_DIR             = $(BASEDIR)/FOLDER_7_OUTPUT_C_SIMULATION
LEXER_SOURCE_DIR       = $(LEXER_DIR)/SOURCE_FILES
LEXER_HEADER_DIR       = $(LEXER_DIR)/HEADER_FILES
LEXER_OBJECT_DIR       = $(LEXER_DIR)/OBJECT_FILES
PARSER_SOURCE_DIR      = $(PARSER_DIR)/SOURCE_FILES
PARSER_HEADER_DIR      = $(PARSER_DIR)/HEADER_FILES
PARSER_OBJECT_DIR      = $(PARSER_DIR)/OBJECT_FILES

###############
# LEXER FLAGS #
###############
LEXER_PROGRAM_FLAGS__CodeGen   = -o$(CODEGEN__DIR)/CodeGen_Lexer.c

################
# PARSER FLAGS #
################
PARSER_PROGRAM_FLAGS__CodeGen  = -d -v -p zz -o $(CODEGEN__DIR)/CodeGen_Parser.c

#####################
# LEXER INPUT FILES #
#####################
LEXER_INPUT__CodeGen  = $(CODEGEN__DIR)/CodeGen.lex

######################
# PARSER INPUT FILES #
######################
PARSER_INPUT__CodeGen = $(CODEGEN__DIR)/CodeGen.y

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

##############
# SIMULATION #
##############
SIMULATION_FLAGS         = -I$(SIMULATION_HEADER_DIR) -w
SIMULATION_PROGRAM       = $(SIMULATION_DIR)/simulator
SIMULATION_SOURCE_FILES := $(wildcard  $(SIMULATION_SOURCE_DIR)/*.c)
SIMULATION_HEADER_FILES := $(wildcard  $(SIMULATION_HEADER_DIR)/*.h)
SIMULATION_OBJECT_FILES := $(addprefix $(LEXER_OBJECT_DIR)/,$(LEXER_SOURCE_FILES,.c=.o))

################
# INPUT/OUTPUT #
################
INPUT_PSEUDO_ASM    = $(INPUT_DIR)/PseudoAsm.txt
OUTPUT_C_SIMULATION = $(OUTPUT_DIR)/simulation.c

##########################
# ALL LEXER(S) PARSER(S) #
##########################
all:
	@rm -rf $(LEXER_PROGRAM) 
	@rm -rf $(PARSER_PROGRAM) 
	@rm -rf $(SIMULATION_PROGRAM) 
	@rm -rf $(SIMULATION_SOURCE_DIR)/CodeGen_Lexer.c
	@rm -rf $(SIMULATION_SOURCE_DIR)/CodeGen_Parser.c
	@rm -rf $(SIMULATION_HEADER_DIR)/CodeGen_Parser.h
	@$(CC) $(LEXER_FLAGS)  $(LEXER_SOURCE_FILES)  -o $(LEXER_PROGRAM)
	@$(CC) $(PARSER_FLAGS) $(PARSER_SOURCE_FILES) -o $(PARSER_PROGRAM)
	@$(LEXER_PROGRAM)  $(LEXER_PROGRAM_FLAGS__CodeGen)  $(LEXER_INPUT__CodeGen)
	@$(PARSER_PROGRAM) $(PARSER_PROGRAM_FLAGS__CodeGen) $(PARSER_INPUT__CodeGen)
	@mv $(CODEGEN__DIR)/CodeGen_Lexer.c  $(SIMULATION_SOURCE_DIR)
	@mv $(CODEGEN__DIR)/CodeGen_Parser.c $(SIMULATION_SOURCE_DIR)
	@mv $(CODEGEN__DIR)/CodeGen_Parser.h $(SIMULATION_HEADER_DIR)
	@printf "\n"
	@printf "\n"
	@printf "\n"
	@pwd
	@printf "\n"
	@printf "\n"
	@printf "\n"
	@printf "\n"
	$(CC) $(SIMULATION_FLAGS) $(SIMULATION_SOURCE_FILES) -o $(SIMULATION_PROGRAM)
	$(SIMULATION_PROGRAM) $(INPUT_PSEUDO_ASM) $(OUTPUT_C_SIMULATION)

