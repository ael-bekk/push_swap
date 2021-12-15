RED = \033[31m
L_RED = \033[1;31m
GRN = \033[0;32m
L_GRN = \033[1;32m
RESET = \033[0m
Purple= \033[0;35m

LIBFT = inc/libft/libft.a

PUSH_SWAP = push_swap
CHECHER = checker
GENERATOR = generator

GO_TO = inc/libft

AFFICH_INTRO = header/aff_stacks1.c header/aff_stacks2.c header/min.c

SRC_CHECKER = check/checker.c check/errors.c header/aff_stacks1.c \
			  header/aff_stacks2.c p_s/s_p_r_rr_operations.c

SRC_P_S_C = p_s/do_op_color.c p_s/sort_3_4_5.c p_s/p_s.c p_s/radix_sort.c \
			p_s/init_sort.c p_s/s_p_r_rr_operations.c header/aff_stacks1.c \
			header/aff_stacks2.c check/errors.c

SRC_P_S = p_s/do_op.c p_s/sort_3_4_5.c p_s/p_s.c p_s/radix_sort.c \
		  p_s/init_sort.c p_s/s_p_r_rr_operations.c header/aff_stacks1.c \
		  header/aff_stacks2.c check/errors.c

GEN = gen/generat_test.c

GFLAGS = cc -Wextra -Wall -Werror

all : $(LIBFT) checker push_swap1

checker	: $(LIBFT)
	@$(GFLAGS) $(AFFICH_INTRO) $(LIBFT) && ./a.out && rm a.out
	@echo "$(GRN)[libft]: compiled$(RESET)"
	@$(GFLAGS) $(SRC_CHECKER) $(LIBFT) -o $(CHECHER)
	@sleep 0.5
	@echo "$(GRN)Programme $(L_GRN)$(CHECHER)$(GRN) : is ready.$(RESET)"

push_swap1 : $(LIBFT)
	@rm -rf $(PUSH_SWAP)
	@$(GFLAGS) $(SRC_P_S) $(LIBFT) -o $(PUSH_SWAP)
	@sleep 0.5
	@echo "$(GRN)Programme $(L_GRN)$(PUSH_SWAP)$(GRN) : is ready.$(RESET)"

push_swap2 : $(LIBFT)
	@rm -rf $(PUSH_SWAP)
	@$(GFLAGS) $(SRC_P_S_C) $(LIBFT) -o $(PUSH_SWAP)
	@sleep 0.5
	@echo "$(GRN)Programme $(L_GRN)$(PUSH_SWAP)2$(GRN) : is ready.$(RESET)"

generator : $(LIBFT)
	@$(GFLAGS) $(GEN) $(LIBFT) -o $(GENERATOR)
	@sleep 0.5
	@echo "$(GRN)Programme $(L_GRN)$(GENERATOR)$(GRN) : is ready.$(RESET)"

move :
	@mkdir -p BUILTIN
	@cp gen/generat.sh BUILTIN
	@mv $(PUSH_SWAP) $(CHECHER) $(GENERATOR) BUILTIN 2> /dev/null

$(LIBFT) :
	@make -C $(GO_TO)

clean :
	@rm -rf $(CHECHER) $(PUSH_SWAP) $(PUSH_SWAP) $(GENERATOR) gen_rand.txt BUILTIN
	@sleep 0.5
	@echo "$(RED)Bin $(L_RED)./$(PUSH_SWAP)$(RESET)$(RED) removed.$(RESET)"
	@sleep 0.5
	@echo "$(RED)Bin $(L_RED)./$(CHECHER)$(RESET)$(RED) removed.$(RESET)"
	@sleep 0.5
	@echo "$(RED)Bin $(L_RED)./$(GENERATOR)$(RESET)$(RED) removed.$(RESET)"

fclean : clean
	@make fclean -C $(GO_TO)
	@sleep 0.5
	@echo "$(RED)[$(L_RED)libft$(RESET)$(RED)] : removed.$(RESET)"

re : clean all

.PHONY : all checker push_swap1 push_swap2 move clean fclean re
