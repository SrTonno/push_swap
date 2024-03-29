include colors.mk
###############################################################################
#                                              FILES                          #
###############################################################################
CFILES		= \
			main.c create_list.c utils/utils.c utils/utils_struck.c utils/utils_sort.c \
			utils/utils_struck2.c move/rotate.c move/swap.c move/push.c move/reverse.c \
			sort/small_list.c sort/5_numbers.c utils/created_index.c utils/move_block_b.c \
			sort/100_numbers.c utils/return_stack.c utils/struct_free.c \
			utils/psorder_b.c utils/radix.c utils/print_list.c utils/ft_check_int.c
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
	@echo "${God}${Green}Created '${NAME}'.${NoColor}"

$(NLIBRARY): $(LIBFT)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "${God}${Green}Created '${NLIBRARY}'.${NoColor}"

git: fclean
	@echo "\t${BIPurple}>>Push To Git<<${NoColor}"
	@git add . ;
	@read -p "Name the commit: " commit ;\
	git commit -m "$$commit" ;\
	git push origin master ;

normi:
	@echo "${BICyan}>>Check Files with ${BIRed}ERROR${BICyan} norminette<<${NoColor}"
	@norminette -R CheckForbiddenSourceHeader | grep Error! | grep -v tester
	@echo "Total Errores $$(norminette -R CheckForbiddenSourceHeader | grep -v Error! | grep -v tester | wc -l)"

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

###############################################################################
clean:
		@${RM} ${OBJS} ${LIBFT}
		@echo "${Bad}${Red}Delete .o.${NoColor}"

fclean: clean
		@${RM} ${NLIBRARY} ${NAME}
		@echo "${Bad}${Red}Delete '${NLIBRARY}' and '${NAME}'.${NoColor}"

re: fclean all

help:
	@echo "${UGreen}Options of MakeFile:${NoColor}"
	@echo "Used: make [options]"
	@echo "\t${BICyan}Default:${NoColor} Created '${NAME}'"
	@echo "\t${IRed}clean:${NoColor} Delete '.o'."
	@echo "\t${BIRed}fclean:${NoColor} Delete'.o', '${NLIBRARY}'"
	@echo "\t${BICyan}re:${NoColor} Delete '.o', '${NLIBRARY}', '${NAME}' and creates '${NAME}'"
	@echo "\t${BIPurple}git:${NoColor} Push to git."
	@echo "\t${BICyan}normi:${NoColor} Check file with Error the norminette."
	@echo "MakeFile by ${UBlue}tvillare${NoColor}."

.PHONY = all clean fclean re help normi git
