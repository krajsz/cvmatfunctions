#include <iostream>
#include "myprocessingclass.h"

using std::endl;

int main (int argc, char** argv)
{
    MyProcessingClass test_class;
    try
    {
        test_class.tests();
        std::string argvstring(argv[1]);

        if (argvstring.size() != 0)
        {
            test_class.read(argvstring);

            test_class.getInput() = test_class.im2bw(test_class.getCInput(), 100);
            test_class.getInput() = test_class.medfilt2(test_class.getCInput(), 5);

            test_class.show();
        }
    }
    catch(const cv::Exception& ex)
    {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    return 0;
}
