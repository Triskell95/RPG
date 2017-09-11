NAME	=	My_RPG

SRC		=	My_RPG.cc \
			Personnage.cc \
			Arme.cc \
			Magicien.cc \
			Guerrier.cc
		
#[ CMD ]########################################################################

CC		=	g++
RMV		=	rm -vf
RM		=	rm -f
ECHO	=	echo -e

#[ SYS ]########################################################################

OBJDIR	:=	obj
OBJS	:=	$(patsubst %,$(OBJDIR)/%.o,$(SRC))

VPATH	= \
		  source

#LDFLAGS += -L lib 

ifeq ($(DEBUG), yes)
	CFLAGS	+= -O0
	CFLAGS	+= -g
else
	CFLAGS  += -O3
endif

CFLAGS  += -I include

CFLAGS	+=	-std=c++11
# CFLAGS	+=	-Wextra
CFLAGS	+=	-Wall
# CFLAGS	+=	-Werror
# CFLAGS	+=	-W
# stop cflags
CFLAGS  +=  -c
# for dependencies
CFLAGS  +=  -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" 
DEPS	:=	$(OBJS:%.o=%.d)

#[ EXEC ]#######################################################################

$(NAME)	:   $(OBJS)
			@$(ECHO) "- - -"
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all		:	$(NAME)

$(OBJDIR)/%.o	:	%
	$(CC) $(CFLAGS) $< -o $@

$(OBJS)	:	| $(OBJDIR)

$(OBJDIR):
			mkdir -p $(OBJDIR)

clean	:
			@$(ECHO) "REMOVE..."
			@$(RMV) $(OBJS)
			@$(RMV) $(DEPS)

fclean	:	clean
			@$(RMV) $(NAME)
			@$(ECHO) "- - -"

re		:	fclean all

.PHONY	:	all $(OBJDIR)/%.o clean fclean re

################################################################################

-include   $(DEPS)


################################################################################
# Automatically-generated file. Do not edit!
################################################################################
#
#-include ../makefile.init
#
#RM := rm -rf
#
## All of the sources participating in the build are defined here
#-include sources.mk
#-include source/subdir.mk
#-include subdir.mk
#-include objects.mk
#
#ifneq ($(MAKECMDGOALS),clean)
#ifneq ($(strip $(CC_DEPS)),)
#-include $(CC_DEPS)
#endif
#ifneq ($(strip $(C++_DEPS)),)
#-include $(C++_DEPS)
#endif
#ifneq ($(strip $(C_UPPER_DEPS)),)
#-include $(C_UPPER_DEPS)
#endif
#ifneq ($(strip $(CXX_DEPS)),)
#-include $(CXX_DEPS)
#endif
#ifneq ($(strip $(CPP_DEPS)),)
#-include $(CPP_DEPS)
#endif
#ifneq ($(strip $(C_DEPS)),)
#-include $(C_DEPS)
#endif
#endif
#
#-include ../makefile.defs
#
## Add inputs and outputs from these tool invocations to the build variables 
#
## All Target
#all: My_RPG
#
## Tool invocations
#My_RPG: $(OBJS) $(USER_OBJS)
#	@echo 'Building target: $@'
#	@echo 'Invoking: GCC C++ Linker'
#	g++  -o "My_RPG" $(OBJS) $(USER_OBJS) $(LIBS)
#	@echo 'Finished building target: $@'
#	@echo ' '
#
## Other Targets
#clean:
#	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) My_RPG
#	-@echo ' '
#
#.PHONY: all clean dependents
#.SECONDARY:
#
#-include ../makefile.targets
