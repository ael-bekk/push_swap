RED = \033[31m
L_RED = \033[1;31m
GRN = \033[0;32m
L_GRN = \033[1;32m
RESET = \033[0m
Purple= \033[0;35m

LIBFT = inc/libft/libft.a

PUSH_SWAP = push_swap
CHECKER = checker
GENERATOR = generator

GO_TO = inc/libft

AFFICH_INTRO = header/aff_stacks1.c header/aff_stacks2.c header/min.c

SRC_CHECKER = check/checker.c check/errors.c header/aff_stacks1.c \
			  header/aff_stacks2.c p_s/s_p_r_rr_operations.c check/joine_args.c

SRC_P_S = p_s/do_op.c p_s/sort_3_4_5.c p_s/p_s.c p_s/radix_sort.c \
		  p_s/init_sort.c p_s/s_p_r_rr_operations.c header/aff_stacks1.c p_s/sort_hund.c p_s/sort_hund2.c p_s/sort_larg.c \
		  header/aff_stacks2.c check/errors.c check/joine_args.c

GEN = gen/generat_test.c

GFLAGS = cc -Wextra -Wall -Werror

all : $(CHECKER) $(PUSH_SWAP)

$(CHECKER) : $(LIBFT) $(SRC_CHECKER)
	@$(GFLAGS) $(AFFICH_INTRO) $(LIBFT) && ./a.out && rm a.out
	@echo "$(GRN)[libft]: compiled$(RESET)"
	@$(GFLAGS) $(SRC_CHECKER) $(LIBFT) -o $(CHECKER)
	@sleep 0.5
	@echo "$(GRN)Programme $(L_GRN)$(CHECKER)$(GRN) : is ready.$(RESET)"

$(PUSH_SWAP) : $(LIBFT) $(SRC_P_S)
	@rm -rf $(PUSH_SWAP)
	@$(GFLAGS) $(SRC_P_S) $(LIBFT) -o $(PUSH_SWAP)
	@sleep 0.5
	@echo "$(GRN)Programme $(L_GRN)$(PUSH_SWAP)$(GRN) : is ready.$(RESET)"

generator : $(LIBFT)
	@$(GFLAGS) $(GEN) $(LIBFT) -o $(GENERATOR)
	@sleep 0.5
	@echo "$(GRN)Programme $(L_GRN)$(GENERATOR)$(GRN) : is ready.$(RESET)"

move :
	@mkdir -p BUILTIN
	@mv $(PUSH_SWAP) $(CHECKER) $(GENERATOR) BUILTIN 2> /dev/null

$(LIBFT) :
	@make -C $(GO_TO)

clean :
	@rm -rf $(CHECKER) $(PUSH_SWAP) $(PUSH_SWAP) $(GENERATOR) gen_rand.txt BUILTIN
	@sleep 0.5
	@echo "$(RED)Bin $(L_RED)./$(PUSH_SWAP)$(RESET)$(RED) removed.$(RESET)"
	@sleep 0.5
	@echo "$(RED)Bin $(L_RED)./$(CHECKER)$(RESET)$(RED) removed.$(RESET)"
	@sleep 0.5
	@echo "$(RED)Bin $(L_RED)./$(GENERATOR)$(RESET)$(RED) removed.$(RESET)"

fclean : clean
	@make fclean -C $(GO_TO)
	@sleep 0.5
	@echo "$(RED)[$(L_RED)libft$(RESET)$(RED)] : removed.$(RESET)"

re : fclean all

.PHONY : all move clean fclean re
