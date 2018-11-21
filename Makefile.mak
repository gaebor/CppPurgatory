CPPFLAGS=/EHsc /nologo

right: clean dir   \
    template_order class_inside_class operator_order \
    rvalue pointer_play template_inheritance thread_local \
    template_error ambiguity parameter_precedence static_cast \
	static_template map_copy template_syntax tls

all: clean dir         \
    template_order const_list class_inside_class operator_order \
    rvalue pointer_play template_inheritance array macro_comma thread_local \
    template_error ambiguity parameter_precedence static_cast static_template \
    map_copy template_syntax tls

{src\}.cpp{win\}.exe::
	$(CPP) $(CPPFLAGS) /Fo"src/" $< /Fe"win/"

dir:
	IF exist win ( echo ) ELSE ( MD win)

clean:
	del /Q win

ambiguity: win\ambiguity.exe
static_cast: win\static_cast.exe
parameter_precedence: win\parameter_precedence.exe
const_list: win\const_list.exe
class_inside_class: win\class_inside_class.exe
operator_order: win\operator_order.exe
array: win\array.exe	
rvalue: win\rvalue.exe
template_order: win\template_order.exe
macro_comma: win\macro_comma.exe
pointer_play: win\pointer_play.exe
template_inheritance: win\template_inheritance.exe
thread_local: win\thread_local.exe
template_error: win\template_error.exe
static_template: win\static_template.exe
map_copy: win\map_copy.exe
template_syntax: win\template_syntax.exe
tls: win\tls.exe
