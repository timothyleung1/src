#	$OpenBSD: Makefile,v 1.20 2018/09/09 04:09:32 ccardenas Exp $

.if ${MACHINE} == "amd64" || ${MACHINE} == "i386"

PROG=		vmd
SRCS=		vmd.c control.c log.c priv.c proc.c config.c vmm.c
SRCS+=		vm.c loadfile_elf.c pci.c virtio.c i8259.c mc146818.c
SRCS+=		ns8250.c i8253.c vmboot.c ufs.c disklabel.c dhcp.c packet.c
SRCS+=		parse.y atomicio.c vioscsi.c vioraw.c vioqcow2.c

CFLAGS+=	-Wall -I${.CURDIR}
CFLAGS+=	-Wstrict-prototypes -Wmissing-prototypes
CFLAGS+=	-Wmissing-declarations
CFLAGS+=	-Wshadow -Wpointer-arith -Wcast-qual
CFLAGS+=	-Wsign-compare

LDADD+=		-lutil -lpthread -levent
DPADD+=		${LIBUTIL} ${LIBPTHREAD} ${LIBEVENT}

YFLAGS=

.else

NOPROG= yes

.endif

MAN=		vmd.8 vm.conf.5

.include <bsd.prog.mk>
