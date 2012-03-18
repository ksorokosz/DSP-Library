#include "MUGED_Tests.h"

void runSuite()
{
	cute::suite s;
	s.push_back(CUTE(_dsp_test_));
	s.push_back(CUTE(_complex_test_));

	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main()
{
    runSuite();
    return 0;
}



