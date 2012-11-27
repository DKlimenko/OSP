###############################################################
#   Students' Makefile for Operating Systems Project          #
#                     Use As Is                               #
###############################################################


# The assignment directory 
#ASG_DIR = /chalmers/groups/cab_ce_edu_2010_eda092_os_-/OSP/lab2.1.linux/

# The default C compiler 
C_COMP = gcc


OSP : $(ASG_DIR)osp.o dialog.o cpu.o 
	$(C_COMP) $(ASG_DIR)osp.o dialog.o cpu.o -fno-builtin  -lm -g -o OSP

queue : $(ASG_DIR)osp.o dialog.o cpu_queue.o 
	$(C_COMP) $(ASG_DIR)osp.o dialog.o cpu_queue.o -fno-builtin  -lm -g -o OSP

dialog.o : dialog.c
	$(C_COMP)  -fno-builtin -c -g dialog.c

cpu.o : cpu.c 
	$(C_COMP)  -fno-builtin -c -g cpu.c 

cpu_queue.o : cpu_queue.c 
	$(C_COMP)  -fno-builtin -c -g cpu_queue.c 
