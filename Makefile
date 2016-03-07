CPP=g++
FLAGS=--std=c++11

all: clean dir const_list class_inside_class operator_order array

dir:
	mkdir -p lin

clean:
	rm -Rf lin
	
const_list: src/const_list.cpp
	$(CPP) $(FLAGS) src/const_list.cpp -o lin/const_list

class_inside_class: src/class_inside_class.cpp
	$(CPP) $(FLAGS) src/class_inside_class.cpp -o lin/class_inside_class
	
operator_order: src/operator_order.cpp
	$(CPP) $(FLAGS) src/operator_order.cpp -o lin/operator_order

array: src/array.cpp
	$(CPP) $(FLAGS) src/array.cpp -o lin/array