
# Programs
LD 		= g++
CC 		= g++
AR		= ar

# Folders
LIB		= lib
SRC 	= src
OBJ		= obj
INC 	= inc
DOC 	= doc
PROG	= int

# Flags
LDFLAGS	=
CFLAGS 	= -c -std=c++11 -g -Wall -m64 -L$(LIB) -I$(INC)

LEX		= scanner
BISON = parser

# Utils
RM 		= /bin/rm
MKDIR = /bin/mkdir

# Files
SOURCES = $(wildcard $(SRC)/*.cpp)
OBJECTS = $(addprefix $(OBJ)/,$(notdir $(SOURCES:.cpp=.o)))

# Default behaviour
all: dir libr bison flex $(PROG)

# Make new project structure
project: dir docsconfig gitignore
	cp ~/Documents/GitHub/doxygen-bootstrapped/customdoxygen.css $(DOC)/;\
	cp ~/Documents/GitHub/doxygen-bootstrapped/doxy-boot.js $(DOC)/html;\
	cp ~/Documents/GitHub/doxygen-bootstrapped/example-site/header.html $(DOC)/;\
	cp ~/Documents/GitHub/doxygen-bootstrapped/example-site/footer.html $(DOC)/;\
	sed -i "s/HTML_HEADER            =/HTML_HEADER = $(DOC)\/header.html/g" $(DOC)/doxy.conf;\
	sed -i "s/HTML_FOOTER            =/HTML_FOOTER = $(DOC)\/footer.html/g" $(DOC)/doxy.conf;\
	sed -i "s/HTML_EXTRA_STYLESHEET  =/HTML_EXTRA_STYLESHEET = $(DOC)\/customdoxygen.css/g" $(DOC)/doxy.conf;\
	sed -i "s/OUTPUT_DIRECTORY       =/OUTPUT_DIRECTORY = $(DOC)/g" $(DOC)/doxy.conf;\
	sed -i "s/JAVADOC_AUTOBRIEF      = NO/JAVADOC_AUTOBRIEF = YES/g" $(DOC)/doxy.conf;\
	sed -i "s/RECURSIVE              = NO/RECURSIVE = YES/g" $(DOC)/doxy.conf;\
	sed -i "s/EXCLUDE_PATTERNS       =/EXCLUDE_PATTERNS = \*\/bin\/\*\nEXCLUDE_PATTERNS += \*\/doc\/\*\nEXCLUDE_PATTERNS += \*\/obj\/\*\n/g" $(DOC)/doxy.conf;

# Compile all sources
$(PROG): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $(PROG)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

# create scanner
flex:
	flex -o $(SRC)/$(LEX).cpp --header-file=$(INC)/$(LEX).h $(SRC)/$(LEX).lex

# create parser
bison:
	bison -o $(SRC)/$(BISON).cpp --defines=$(INC)/$(BISON).h $(SRC)/$(BISON).y

# create libraries
libr:

# create directories
dir:
	$(MKDIR) -p $(LIB) $(SRC) $(OBJ) $(INC) $(DOC) $(DOC)/html

# generate documentation
docsconfig:
	doxygen -g $(DOC)/doxy.conf
docs:
	doxygen $(DOC)/doxy.conf

# create gitignore file
gitignore:
	echo "/bin/*\n/obj/\n*.log\n*.o\n*.so" > .gitignore

# clean
clean:
	$(RM) -f $(PROG) $(OBJ)/* $(INC)/$(BISON).h $(INC)/$(LEX).h $(SRC)/$(LEX).cpp $(SRC)/$(BISON).cpp

graph:
	dot -Tpdf graph.dot -otree.pdf
