#include "emis.h"

int main(int argc,const char* argv[])
{
	EMIS& emis = EMIS::singleEMIS();
	emis.login();
}
