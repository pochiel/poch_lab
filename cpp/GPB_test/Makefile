COMPILER = g++
CFLAGS   = -Wextra -g -MMD -MP
LDFLAGS  = -lprotobuf -lboost_system -lpthread -lboost_thread-mt
LIBS     =
INCLUDE  = -I../include
TARGET   = GPB_test
OBJDIR   = ./obj
ifeq "$(strip $(OBJDIR))" ""
	OBJDIR = .
endif
SOURCES_CPP  = $(wildcard *.cpp)
SOURCES_PROTO = $(wildcard *.proto)
OBJECTS  = $(addprefix $(OBJDIR)/, $(SOURCES_PROTO:.proto=.o))
OBJECTS  += $(addprefix $(OBJDIR)/, $(SOURCES_CPP:.cpp=.o))
PROTOCOLS_CC = $(addprefix ./, $(SOURCES_PROTO:.proto=.pb.cc)) 
PROTOCOLS_HH = $(addprefix ./, $(SOURCES_PROTO:.proto=.pb.h)) 
DEPENDS  = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS) $(LIBS)
	$(COMPILER) -o $@ $^ $(LDFLAGS)

%.pb.cc: %.proto
	protoc -I="./" --cpp_out="./" $<

$(OBJDIR)/%.o: %.cpp
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(OBJDIR)/%.o: %.pb.cc
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all : clean debug $(TARGET)

debug :
	echo $(OBJECTS)
clean:
	rm -f $(OBJECTS) $(DEPENDS) $(TARGET) $(PROTOCOLS_CC) $(PROTOCOLS_HH)
	@rmdir --ignore-fail-on-non-empty `readlink -f $(OBJDIR)`

-include $(DEPENDS)
