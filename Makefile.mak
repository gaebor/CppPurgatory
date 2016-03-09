CPP=cl
FLAGS=/EHsc

all: clean dir const_list class_inside_class operator_order array rvalue

right: clean dir const_list class_inside_class operator_order rvalue

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
	
array: src/array.cpp
	$(CPP) $(FLAGS) /Fo:win/array.obj src/array.cpp /link /OUT:win/array.exe

rvalue: src/rvalue.cpp
	$(CPP) $(FLAGS) /Fo:win/rvalue.obj src/rvalue.cpp /link /OUT:win/rvalue.exe