#include <iostream>

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
    std::unique_ptr<BatchRendererApp> app = std::make_unique<BatchRendererApp>();
    LOG_ERROR("Hello");
    app->Run();

}


