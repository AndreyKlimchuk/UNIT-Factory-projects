#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/02 11:23:48 by aklimchu          #+#    #+#              #
#    Updated: 2017/04/02 15:12:21 by kbovt            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ASM = asm
VM = corewar
SRC_VM = main.c instruction_handler.c op.c sup_func.c core.c core_assist.c \
live.c ld.c lld.c ldi.c lldi.c add.c sub.c and.c or.c xor.c aff.c zjmp.c \
fork.c lfork.c st.c sti.c prog_args_handler.c champion_handler.c \
champions_loader.c graphic_init.c graphic_update.c graphic_helper.c \
core_helper.c

SRC_ASM = main.c get_next_line.c err_handler.c get_describe.c comments_skip.c \
white_char.c hash_table.c cor_name.c make_nc.c ophash.c op.c start_write.c\
write_int_in.c get_cmd.c is_label_char.c make_command.c read_argument.c\
properties.c extract_from_quotes.c

PTH_VM = ./vm_dir/Srcs/
PTH_ASM = ./asm_dir/src/

all : $(ASM) $(VM)

$(ASM) : $(addprefix $(PTH_ASM), $(SRC_ASM))
	make -C ./asm_dir/

$(VM) :	$(addprefix $(PTH_VM), $(SRC_VM))
	make -C ./vm_dir/

clean :
	make -C ./asm_dir/ clean
	make -C ./vm_dir/ clean

fclean : clean
	rm $(ASM) $(VM)

re : fclean all
