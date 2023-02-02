###############################################################################
#                                              COLORS                         #
###############################################################################
	# Reset
	NoColor=\033[0m

	# Regular Colors
	Black=\033[0;30m
	Red=\033[0;31m
	Green=\033[0;32m
	Yellow=\033[0;33m
	Blue=\033[0;34m
	Purple=\033[0;35m
	Cyan=\033[0;36m
	White=\033[0;37m

	# Bold
	BBlack=\033[1;30m
	BRed=\033[1;31m
	BGreen=\033[1;32m
	BYellow=\033[1;33m
	BBlue=\033[1;34m
	BPurple=\033[1;35m
	BCyan=\033[1;36m
	BWhite=\033[1;37m

	# Underline
	UBlack=\033[4;30m
	URed=\033[4;31m
	UGreen=\033[4;32m
	UYellow=\033[4;33m
	UBlue=\033[4;34m
	UPurple=\033[4;35m
	UCyan=\033[4;36m
	UWhite=\033[4;37m

	# Background
	On_Black=\033[40m
	On_Red=\033[41m
	On_Green=\033[42m
	On_Yellow=\033[43m
	On_Blue=\033[44m
	On_Purple=\033[45m
	On_Cyan=\033[46m
	On_White=\033[47m

	# High Intensity
	IBlack=\033[0;90m
	IRed=\033[0;91m
	IGreen=\033[0;92m
	IYellow=\033[0;93m
	IBlue=\033[0;94m
	IPurple=\033[0;95m
	ICyan=\033[0;96m
	IWhite=\033[0;97m

	# Bold High Intensity
	BIBlack=\033[1;90m
	BIRed=\033[1;91m
	BIGreen=\033[1;92m
	BIYellow=\033[1;93m
	BIBlue=\033[1;94m
	BIPurple=\033[1;95m
	BICyan=\033[1;96m
	BIWhite=\033[1;97m

	# High Intensity backgrounds
	On_IBlack=\033[0;100m
	On_IRed=\033[0;101m
	On_IGreen=\033[0;102m
	On_IYellow=\033[0;103m
	On_IBlue=\033[0;104m
	On_IPurple=\033[0;105m
	On_ICyan=\033[0;106m
	On_IWhite=\033[0;107m

###############################################################################
#                                              FILES                          #
###############################################################################
CFILES		= \
			main.c create_list.c utils/utils.c utils/utils_struck.c utils/utils_sort.c \
			utils/utils_struck2.c move/rotate.c move/swap.c move/push.c move/reverse.c \
			sort/small_list.c sort/5_numbers.c utils/created_index.c utils/move_block_b.c \
			sort/100_numbers.c utils/return_stack.c utils/struct_free.c \
			utils/psorder_b.c utils/radix.c utils/print_list.c
OBJS	=	${CFILES:.c=.o}

CLIBFT		= \
			libft/lib/ft_atoi.c libft/lib/ft_bzero.c libft/lib/ft_calloc.c \
			libft/lib/ft_isalnum.c libft/lib/ft_isalpha.c libft/lib/ft_isascii.c \
			libft/lib/ft_isdigit.c libft/lib/ft_isprint.c libft/lib/ft_memchr.c \
			libft/lib/ft_memcmp.c libft/lib/ft_memcpy.c libft/lib/ft_memmove.c \
			libft/lib/ft_memset.c libft/lib/ft_strchr.c libft/lib/ft_strdup.c \
			libft/lib/ft_strlcat.c libft/lib/ft_strlcpy.c libft/lib/ft_strlen.c \
			libft/lib/ft_strncmp.c libft/lib/ft_strnstr.c libft/lib/ft_strrchr.c \
			libft/lib/ft_tolower.c libft/lib/ft_toupper.c libft/lib/ft_substr.c \
			libft/lib/ft_strjoin.c libft/lib/ft_strtrim.c libft/lib/ft_putchar_fd.c \
			libft/lib/ft_putstr_fd.c libft/lib/ft_putendl_fd.c libft/lib/ft_putnbr_fd.c \
			libft/lib/ft_itoa.c libft/lib/ft_strmapi.c libft/lib/ft_striteri.c \
			libft/lib/ft_split.c libft/lib/ft_lstnew_bonus.c \
			libft/lib/ft_lstadd_front_bonus.c libft/lib/ft_lstsize_bonus.c \
			libft/lib/ft_lstlast_bonus.c libft/lib/ft_lstadd_back_bonus.c \
			libft/lib/ft_lstdelone_bonus.c libft/lib/ft_lstclear_bonus.c \
			libft/lib/ft_lstiter_bonus.c libft/lib/ft_lstmap_bonus.c \

OLIBFT	=	${CLIBFT:.c=.o}

CPRINTF		= \
			libft/printf/ft_printf.c \
			libft/printf/utils/ft_selectoption.c libft/printf/utils/ft_strchrp.c \
			libft/printf/utils/ft_putstr.c libft/printf/ft_options/ft_c.c \
			libft/printf/ft_options/ft_di.c libft/printf/ft_options/ft_u.c \
			libft/printf/ft_options/ft_s.c libft/printf/ft_options/ft_x.c \
			libft/printf/ft_options/ft_p.c \

OPRINTF	=	${CPRINTF:.c=.o}

CGNL		= \
			libft/gnl/get_next_line.c libft/gnl/get_next_line_utils.c \
			libft/gnl/get_next_line_bonus.c
OGNL	=	${CGNL:.c=.o}

###############################################################################
#                                              SETTINGS                       #
###############################################################################
NAME = push_swap
HDRS = push_swap.h

NLIBRARY= libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OPGRAFIC = -lmlx -framework OpenGL -framework AppKit
FSANITIZE = -fsanitize=address -g

AR = ar
ARFLAGS = -rcs
RM = rm -f

LIBFT = $(OLIBFT) $(OPRINTF) $(OGNL)

###############################################################################
#                                              OPTIONS                        #
###############################################################################
all: ${NAME}

${NAME}: ${NLIBRARY} ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${NLIBRARY} -o $@
	@echo "🍺${Green}Created '${NAME}'.${NoColor}"

$(NLIBRARY): $(LIBFT)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "🍺${Green}Created '${NLIBRARY}'.${NoColor}"

git: fclean
	@echo "\t${BIPurple}>>Push To Git<<${NoColor}"
	@git add . ;
	@read -p "Name the commit: " commit ;\
	git commit -m "$$commit" ;\
	git push origin master ;

normi:
	@echo "${BICyan}>>Check Files with ${BIRed}ERROR${BICyan} norminette<<${NoColor}"
	@norminette -R CheckForbiddenSourceHeader | grep Error! | grep -v tester

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

###############################################################################
clean:
		@${RM} ${OBJS} ${LIBFT}
		@echo "❌${Red}Delete .o.${NoColor}"

fclean: clean
		@${RM} ${NLIBRARY} ${NAME}
		@echo "❌${Red}Delete '${NLIBRARY}' and '${NAME}'.${NoColor}"

re: fclean all

help:
	@echo "${UGreen}Options of MakeFile:${NoColor}"
	@echo "\t${BICyan}Default:${NoColor} Created '${NAME}'"
	@echo "\t${IRed}clean:${NoColor} Delete '.o'."
	@echo "\t${BIRed}fclean:${NoColor} Delete'.o', '${NLIBRARY}'"
	@echo "\t${BICyan}re:${NoColor} Delete '.o', '${NLIBRARY}', '${NAME}' and creates '${NAME}'"
	@echo "\t${BIPurple}git:${NoColor} Push to git."
	@echo "\t${BICyan}normi:${NoColor} Check file with Error the norminette."
	@echo "MakeFile by ${UBlue}tvillare.${NoColor}"

.PHONY = all clean fclean re help
