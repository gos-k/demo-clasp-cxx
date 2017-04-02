
#include <stdio.h>
// clasp.h brings in everything needed for interop
#include <clasp/clasp.h>

void helloWorld()
{
    printf("Hello World\n");
    printf("This is C++ code being invoked from Clasp Common Lisp\n");
}

double addThreeNumbers(double x, double y, double z)
{
    return x+y+z;
}

float addThreeSingleFloats(float x, float y, float z)
{
    return x+y+z;
}

double addThreeNumbers_n_times(size_t n, double x, double y, double z)
{
    double result = 0.0;
    for (size_t i(0); i<n; ++i ) {
	result += x+y+z;
    }
    return result;
}

void startup()
{
    using namespace clbind;
    package("HW") [
		   def("hello-world",&helloWorld)
		   , def("addThreeNumbers",&addThreeNumbers)
		   , def("addThreeSingleFloats",&addThreeSingleFloats)
		   , def("addThreeNumbers_n_times", &addThreeNumbers_n_times)
		   ];
}


// ------------------------------------------------------------
//
// Set this code up so that it can be loaded into Clasp
//

CLASP_REGISTER_STARTUP(startup);
