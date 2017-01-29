CPPFLAGS=/EHsc -nologo

right: clean dir template_order const_list class_inside_class operator_order rvalue

all: clean dir         \
    const_list         \
    class_inside_class \
    operator_order     \
    array              \
    rvalue             \
    template_order

{src\}.cpp{win\}.exe:
	$(CPP) $(CPPFLAGS) /Fo$*.obj $< /link /OUT:$@

dir:
	IF exist win ( echo ) ELSE ( MD win)

clean:
	del /Q win

const_list: win\const_list.exe
class_inside_class: win\class_inside_class.exe
operator_order: win\operator_order.exe
array: win\array.exe	
rvalue: win\rvalue.exe
template_order: win\template_order.exe
