__asm__(
".text\n"
".global " START "\n"
".type   " START ", %function\n"
START ":\n"
"	lgr  %r2, %r15\n"
"	larl %r3, 1f\n"
"	agf  %r3, 0(%r3)\n"
"	aghi %r15, -160\n"
"	lghi %r0, 0\n"
"	stg  %r0, 0(%r15)\n"
"	jg " START "_c\n"
"	.align 8\n"
".weak   _DYNAMIC\n"
".hidden _DYNAMIC\n"
"1:	.long _DYNAMIC-.\n"
);
