#include <iostream>
#include <memory>

#include "GL-Core/GLCore.h"
using namespace GLCore;
class BatchRendererApp : public Application
{
public:
    BatchRendererApp()
    {}
};

int main()
{
    std::cout << "Hello World!\n";
    std::unique_ptr<BatchRendererApp> app = std::make_unique<BatchRendererApp>();
    app->Run();

}


