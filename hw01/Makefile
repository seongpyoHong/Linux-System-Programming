#사용자의 Compilation tools
CROSS = 

#CROSS에 정의되어 있는 명령어들을 사용하여 저의
CC	= $(CROSS)gcc
CXX	= $(CROSS)g++ 
LD  = $(CROSS)cc
AR	= $(CROSS)ar
AS	= $(CROSS)as
RM 	= rm -f

#ROOT Directory 정의
ROOT = $(shell pwd)


#BITS Default 값 정의
BITS	= 32
LDFLAGS	= -lm 

#32 bits 일 때, compile option 수정
ifeq ($(BITS),32)
	CFLAGS 	+= -m32
	CXXFLAGS+= -m32	
	LDFLAGS	+= -m32
endif
# 정의 수정
# c 파일에 대한 정의 수정
CFLAGS +=
CFLAGS +=

# c++ 파일에 대한 정의 수정
CXXFLAGS +=
CXXFLAGS +=

# AR 옵션 설정
ARFLAGS	= crus

# build diretory 설정
BUILD_DIR = x86_$(BITS)

# src 파일 lib 경로 지정
#c	
vpath %.c 
#cpp
vpath %.cpp	

# demo_src 파일 경로 지정
vpath %.c  $(ROOT)/src/

#헤더 파일 경로
# .c
CFLAGS +=

# .cpp
CXXFLAGS += 

#src file 경로 및 obj 설정
#c
LIB_C_SRCS   +=	
LIB_C_OBJS	= $(patsubst %.c,$(BUILD_DIR)/%.o, $(LIB_C_SRCS))
#cpp
LIB_CXX_SRCS	= 
LIB_CXX_OBJS	= $(patsubst %.cpp,$(BUILD_DIR)/%.o, $(LIB_CXX_SRCS))

#demo_src file 경로 및 obj 설정
#C
DEMO_C_SRCS  = swap.c main.c
DEMO_C_OBJS  = $(patsubst %.c, $(BUILD_DIR)/%.o,$(DEMO_C_SRCS))
#CPP
DEMO_CXX_SRCS	= 
DEMO_CXX_OBJS	= $(patsubst %.cpp,$(BUILD_DIR)/%.o, $(DEMO_CXX_SRCS))

#Library 생성
$(LIB_TARGET): $(LIB_C_OBJS) $(LIB_CXX_OBJS)
		$(AR)  $(ARFLAGS)   $@	$^

#cpp object 생성
$(LIB_CXX_OBJS): $(BUILD_DIR)/%.o: %.cpp
		$(CXX) -c $(CXXFLAGS)  -o $@ $<

#c object 생성
$(LIB_C_OBJS): $(BUILD_DIR)/%.o: %.c
		$(CC) -c $(CFLAGS)  -o $@ $<
																								   	
#demo 실행 파일 생성
$(DEMO_TARGET): $(DEMO_C_OBJS) $(DEMO_CXX_SRCS)
	$(LD) $(LDFLAGS)  $^ $(LIB_TARGET) -o $@

#demo 실행
$(DEMO_CXX_OBJS): $(BUILD_DIR)/%.o: %.cpp
	$(CXX) -c $(CXXFLAGS)  -o $@ $<
#demo object 생
$(DEMO_C_OBJS): $(BUILD_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS)  -o $@ $<
#clean 명령어 생성
clean:
	$(RM) $(LIB_C_OBJS)  $(LIB_CXX_OBJS) $(DEMO_C_OBJS)  $(DEMO_CXX_OBJS) $(DEMO_TARGET)  $(LIB_TARGET)
