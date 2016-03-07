CPP=cl
FLAGS=

all: clean dir const_list class_inside_class operator_order

dir:
	IF exist win ( echo ) ELSE ( MD win)

clean:
	del /Q win
	
const_list: src/const_list.cpp
	$(CPP) $(FLAGS) /Fo:win/const_list.obj src/const_list.cpp /link /OUT:win/const_list.exe

class_inside_class: src/class_inside_class.cpp
	$(CPP) $(FLAGS) /Fo:win/class_inside_class.obj src/class_inside_class.cpp /link /OUT:win/class_inside_class.exe

operator_order: src/operator_order.cpp
	$(CPP) $(FLAGS) /Fo:win/operator_order.obj src/operator_order.cpp /link /OUT:win/operator_order.exe