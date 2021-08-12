CC=g++
FLAGS=-Wall -Werror
TARGE=bin
OBJS=manager_view_impl.o manager_ctrl_impl.o manager_mode_impl.o manager.o service_view_impl.o service_ctrl_impl.o service_mode_impl.o department.o employee.o emis.o tools.o main.o

all:$(OBJS)
	$(CC) $(OBJS) -o $(TARGE) 

%.o:%.cpp
	$(CC) -c $(FLAGS) $< -o $@ 

clean:
	rm -rf $(TARGE) $(OBJS) *.h.gch 
