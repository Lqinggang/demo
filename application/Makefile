OBJS=app.o daemonize.o appserver.o
ALL=appserver 
CFLAGS= -static -g
#CC= /home/lqinggang/OpenWrt/AWR52AC/staging_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mipsel-openwrt-linux-gcc
CC=gcc
TAGS:$(ALL)
appserver:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:clean
clean:
	rm -rf $(OBJS) $(ALL)
