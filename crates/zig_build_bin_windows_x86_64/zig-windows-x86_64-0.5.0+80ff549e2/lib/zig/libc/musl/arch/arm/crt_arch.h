__asm__(
".text \n"
".global " START " \n"
".type " START ",%function \n"
START ": \n"
"	mov fp, #0 \n"
"	mov lr, #0 \n"
"	ldr a2, 1f \n"
"	add a2, pc, a2 \n"
"	mov a1, sp \n"
"2:	and ip, a1, #-16 \n"
"	mov sp, ip \n"
"	bl " START "_c \n"
".weak _DYNAMIC \n"
".hidden _DYNAMIC \n"
".align 2 \n"
"1:	.word _DYNAMIC-2b \n"
);
